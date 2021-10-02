class UserCreatedSuccess{
    constructor(){
        this.statusCode = 201
        this.message = "User Created"
    }
}

class UserLoggedInSuccess{
    constructor(){
        this.statusCode = 202
        this.message = "User Logged In"
    }
}

class UserLoggedOutSuccess{
    constructor(){
        this.statusCode = 202
        this.message = "User Logged Out"
    }
}

class UserDeletedSuccess{
    constructor(){
        this.statusCode = 201
        this.message = "User Deleted"
    }
}
module.exports = {
    UserCreatedSuccess,
    UserLoggedInSuccess,
    UserLoggedOutSuccess,
    UserDeletedSuccess
}