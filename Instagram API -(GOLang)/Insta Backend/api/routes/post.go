package routes

import (
	"context"
	"encoding/json"
	"fmt"
	"net/http"
	"time"

	"go.mongodb.org/mongo-driver/bson"
	"go.mongodb.org/mongo-driver/bson/primitive"
)

type Post struct {
	Id 				string 		`bson:"_id" json:"_id"`
	Caption 	string		`json:"caption"`	
	ImageURL 	string		`json:"imageurl"`
	PostedAt 	time.Time `json:"-"`
	UserId 		primitive.ObjectID 		`json:"userid"`
}

/*
	Add New Post of the user to the database
*/

func PostHandler (w http.ResponseWriter, r *http.Request) {
	headerContentType := r.Header.Get("Content-Type")
	if headerContentType != "application/json" {
		http.Error(w, "Content-Type must be application/json", http.StatusUnsupportedMediaType)
		return
	}
	

	var post Post
	err := json.NewDecoder(r.Body).Decode(&post)
	if err != nil {
		http.Error(w, err.Error(), http.StatusBadRequest)
		return
	}

	// Get the Post timestamp

	post.PostedAt = time.Now()
	pid := primitive.NewObjectID().Hex()
	
	// Add Post details to a bson Object

	postDetails := bson.D{
		{Key: "_id",Value: pid},
		{Key: "caption",Value: post.Caption},
		{Key: "imageurl",Value: post.ImageURL},
		{Key: "postedat",Value: post.PostedAt},
		{Key: "userid",Value: post.UserId},
	}

	// Insert the Post details to the database

	ctx, _ := context.WithTimeout(context.Background(), 10*time.Second)
	insertResult, err := DB.Collection("Post").InsertOne(ctx, postDetails)
	if err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return
	}

	// Return the Success Message

	fmt.Println(insertResult.InsertedID)
	w.WriteHeader(http.StatusCreated)
	w.Header().Set("Content-Type", "application/json")
	w.Write([]byte("{\"message\": \"Post created\"}"))
	return;
}