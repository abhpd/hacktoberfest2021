# socket.io-chat-app
This is a simple Chat Application using Socket.IO that emmits events(messages) to all the clients connected to a single route.

To run the application locally go through the following steps

1. clone the repo
```
git clone https://github.com/charliebaer/socket.io-chat-app.git
```
2. make the cloned repo as your pwd
```
cd socket.io-chat-app
```
3. get all the modules listed as dependencies
```
npm install
```
4.run the express server
```
node main.js
```
5. navigate to http://localhost:3000

#### NOTE:
Every tab that is opened using the localhost:3000 is considered as a new client that establishes a connection to the server,
 and the events that are emmitted from one client are broadcasted across to all the other clients. 

Have Fun playin around :)

<img src="https://octocat-generator-assets.githubusercontent.com/my-octocat-1598098295062.png" width="500" height="500">