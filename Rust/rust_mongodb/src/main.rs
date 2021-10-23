use mongodb::{Client, options::ClientOptions};
use mongodb::bson::{doc, Document};

use serde::{Serialize, Deserialize};

#[derive(Debug, Serialize, Deserialize)]
struct User{
    name: String,
    email: String,
    age: u8
}

impl User {
    fn new(name: String, email: String, age: u8)->User{
        User{
            name,
            email,
            age
        }
    }
}

#[tokio::main]
async fn main() -> mongodb::error::Result<()> {
    let mut client_options = ClientOptions::parse("mongodb://localhost:27017").await?;
    client_options.app_name = Some("Rust App".to_string());

    let client = Client::with_options(client_options)?;
    let db = client.database("rust");

    let users_collection = db.collection::<User>("user");

    let _ = users_collection.insert_one(User::new("Rizwan Amjad".to_string(), "rizwanamjadnov@gmail.com".to_string(), 21), None).await;
    // let user = users_collection.find_one(doc!{"name": "Rizwan Amjad"}, None).await?.unwrap();

    // println!("{:?}", user);

    Ok(())
}
