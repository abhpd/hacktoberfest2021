package routes

import(
	"net/http"
	"strings"
	"encoding/json"
	"fmt"
	"context"
	"time"
	"go.mongodb.org/mongo-driver/bson/primitive"
	"go.mongodb.org/mongo-driver/mongo/options"
	"go.mongodb.org/mongo-driver/bson"
)

type GetUserPost struct{
	Page 				int 		`json:"page"`
	Limit 			int 		`json:"limit"`
}

type Result struct{
	Id 					string 		`json:"_id"`
	Caption 		string 		`json:"caption"`
	ImageUrl 		string 		`json:"imageurl"`
	PostedAt 		time.Time 	`json:"postedat"`
	UserId 			primitive.ObjectID 		`json:"userid"`
}

func  GetUserPostsHandler(w http.ResponseWriter, r *http.Request){
	uid := strings.TrimPrefix(r.URL.Path, "/posts/users/")
	fmt.Println(uid)
	if uid == ""{
		http.Error(w, "Invalid User Id", http.StatusNotFound)
		return
	}
	// Decode request Body

	var details GetUserPost
	if err:= json.NewDecoder(r.Body).Decode(&details); err != nil {
		http.Error(w, "Bad request", http.StatusBadRequest)
		fmt.Println(err)
		return
	}

	fmt.Println(details)
	uuid,err:= primitive.ObjectIDFromHex(uid);
	fmt.Println(uuid)
	fmt.Println(uid)
	if err != nil {
		http.Error(w, "Invalid User Id", http.StatusNotFound)
		return
	}

	// Set findOptions

	findOptions:= options.Find();

	findOptions.SetLimit(int64(details.Limit));
	findOptions.SetSkip(int64((details.Page-1) * details.Limit));
	findOptions.SetSort(bson.M{"postedat": -1});

	filter:= bson.M{"userid": uuid}; 
	ctx, _ := context.WithTimeout(context.Background(), 10*time.Second)
	queryResult,err:= DB.Collection("Post").Find(ctx, filter, findOptions);
	if err != nil{
		http.Error(w, "Internal Server Error", http.StatusInternalServerError)
		fmt.Println(err)
		return
	}

	var results []Result

	fmt.Println(queryResult)

	for queryResult.Next(ctx){
		var result Result
		err:= queryResult.Decode(&result);
		if err != nil{
			http.Error(w, "Internal Server Error", http.StatusInternalServerError)
			fmt.Println(err)
			return
		}
		results = append(results, result)
	}
	if results == nil{
		http.Error(w, "No Posts Found", http.StatusNotFound)
		return
	}
	json_data2,error := json.Marshal(results)
	if error != nil{
		http.Error(w, "Internal Server Error", http.StatusInternalServerError)
		fmt.Println(error)
		return
	}
	w.WriteHeader(http.StatusOK)
	w.Header().Set("Content-Type", "application/json")
	w.Write(json_data2)
	return
}