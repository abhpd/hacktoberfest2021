package main

import (
	"context"
	"fmt"
	"log"
	"net/http"
	"os"
	"social/api/routes"
	"time"
	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
	"go.mongodb.org/mongo-driver/mongo/readpref"
)



func checkMethodType(method string,handler http.HandlerFunc) http.HandlerFunc{

	//Checking the request method type and returning the handler function accordingly

	return func(w http.ResponseWriter, r *http.Request) {
		if r.Method != method {
			w.WriteHeader(http.StatusMethodNotAllowed)
			http.Error(w, "Method Not Allowed", http.StatusMethodNotAllowed)
			return
		}
		handler(w,r)
	}
}

func main() {
	mux:= http.NewServeMux()

	//Database Connection	

	db,err := DatabaseConnection();
	if err != nil {
		log.Fatal("Database Connection Error $s",err)
	}
	fmt.Println("Database connection Success!")

	//Sending the database connection to the routes package

	routes.DB = db;

	//Routes

	mux.HandleFunc("/users",checkMethodType("POST",routes.UserHandler));
	mux.HandleFunc("/users/",checkMethodType("GET",routes.GetUserHandler));

	mux.HandleFunc("/posts",checkMethodType("POST",routes.PostHandler));
	mux.HandleFunc("/posts/",checkMethodType("GET",routes.GetPostHandler));
	mux.HandleFunc("/posts/users/",checkMethodType("GET",routes.GetUserPostsHandler));

	//Server Port Configuration

	fmt.Println(os.Getenv("PORT"));
	error := http.ListenAndServe(os.Getenv("PORT"), mux);
	if error != nil {
		log.Fatal(error)
	}
}

func DatabaseConnection()(*mongo.Database,error){
	
	/*
		Database Connection 
		Need env variables : [DATABASE_URI,DATABASE_NAME]
		Connection is established using mongo driver
	*/

	ctx, _ := context.WithTimeout(context.Background(), 10*time.Second)
	fmt.Println(os.Getenv("MONGO_URI"));
	client,err := mongo.Connect(ctx,options.Client().ApplyURI(os.Getenv("MONGO_URI")));

	if err != nil {
		return nil,err
	}
	
	err = client.Ping(ctx, readpref.Primary())
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(os.Getenv("DATABASE_NAME"));

	//Initialize Database

	database := client.Database(os.Getenv("DATABASE_NAME"))

	return database,nil
}