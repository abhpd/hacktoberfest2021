# AppointyTask API


### Details About the Endpoints

- POST /users: To create a new user   {Implemented and Available}
<pre><code>
  Checks if the user already exists in the database.
  If the user does not exist, creates a new user.

  Request Body:
  {
    "_id"       : string,     //Later Converted to Mongo ObjectId
    "name"      : string,
    "username"  : string,
    "password"  : string,
  }
</code></pre>


- GET /users/{id}: To get a user by id  {Implemented and Available}
<pre><code>
  Returns the user with the given id.

  Request Body:
  {
    "_id"       : string,     //Later Converted to Mongo ObjectId
    "name"      : string,
    "username"  : string,
    "password"  : nil,
  }
</code></pre>
- POST /posts: To create a new post    {Implemented and Available}  
<pre><code>
  Creates a new post.

  Response :
  {
    "_id"       : string,     //Later Converted to Mongo ObjectId
    "caption"   : string,
    "imageurl"  : string,
    "postedat"  : string,
    "userid"    : primitive.ObecjId,     
  }
</code></pre>
- GET /posts/{id}: To get a post by id    {Implemented and Available}
<pre><code>
  Returns the post with the given id.

  Response :
  {
    "_id"       : string,     //Later Converted to Mongo ObjectId
    "caption"   : string,
    "imageurl"  : string,
    "postedat"  : string,
    "userid"    : primitive.ObecjId,     
  }
</code></pre>
- GET /posts/users/{id}: To get all posts by user id


