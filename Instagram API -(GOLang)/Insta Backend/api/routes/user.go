package routes

import (
	"context"
	"crypto/sha256"
	"encoding/json"
	"fmt"
	"net/http"
	"time"

	"go.mongodb.org/mongo-driver/bson"
	"go.mongodb.org/mongo-driver/bson/primitive"
	"go.mongodb.org/mongo-driver/mongo"
)

var DB *mongo.Database

type User struct {
	ID       string `bson:"_id" json:"_id"`
	Username string `json:"username"`
	Email    string `json:"email"`
	Password string `json:"password"`
}

// Hash Function to prevent password reverse engineering

func get256Hash(password string) string {
	hash := sha256.Sum256([]byte(password))
	return fmt.Sprintf("%x", hash)
}

func  UserHandler (w http.ResponseWriter, r *http.Request) {

	// Check Header Type as JSON

	headerContentType := r.Header.Get("Content-Type")
	if headerContentType != "application/json" {
		http.Error(w, "Content-Type must be application/json", http.StatusUnsupportedMediaType)
		return
	}
	
	// Decode request Body

	var user User
	if err:= json.NewDecoder(r.Body).Decode(&user); err != nil {
		http.Error(w, "Bad request", http.StatusBadRequest)
		fmt.Println(err)
		return
	}

	/*
	Check if the user Already exists
	if not:
		Create a new user
	else:
		return Already exists
	*/

	ctx, _ := context.WithTimeout(context.Background(), 10*time.Second)
	getAvailUsers := DB.Collection("users").FindOne(ctx, bson.M{"email": user.Email})
	if getAvailUsers.Err() != nil {
		if getAvailUsers.Err() != mongo.ErrNoDocuments {
			http.Error(w, "User Already Exists", http.StatusBadRequest)
			return
		}else{

			/*
				- Make Password Safe
				- Generate a new ID
				- Initialize the bson object	for user
			*/

			user.Password = get256Hash(user.Password);
			user.ID = primitive.NewObjectID().Hex()
			uuid,err:= primitive.ObjectIDFromHex(user.ID)
			users := bson.D{
				{Key: "_id", Value: uuid},
				{Key: "username", Value: user.Username},
				{Key: "email", Value: user.Email},
				{Key: "password", Value: user.Password},
			}

			// Insert the user into the database

			insertUserResult, err := DB.Collection("users").InsertOne(ctx,users);
			if err != nil {
				http.Error(w, "Internal server error", http.StatusInternalServerError)
				fmt.Println(err)
				return
			}

			// Return success message
			fmt.Println(insertUserResult)
			w.Header().Set("Content-Type", "application/json")
			w.WriteHeader(http.StatusOK)
			w.Write([]byte("{\"message\": \"User created\"}"))
			return
		}
	}

	// Return error message

	w.WriteHeader(http.StatusBadRequest)
	w.Write([]byte("{\"message\": \"User Already Exists\"}"))
	return
}