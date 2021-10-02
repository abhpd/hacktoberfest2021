class NotFoundError extends Error{
    constructor(){
        super()
        this.statusCode = 404
        this.message = 'Not Found'
    }
}

class AuthenticationError extends Error{
    constructor(){
        super()
        this.statusCode = 401
        this.message = 'Not Authenticated'
    }
}

class BadRequestError extends Error{
    constructor(){
        super()
        this.statusCode = 400
        this.message = 'Bad Request'
    }
}
class SchemaValidationError extends Error{
    constructor(){
        super()
        this.statusCode = 400
        this.message = 'Duplicate Entry'
    }
}
class InvalidFileTypeError extends Error{
    constructor(){
        super()
        this.statusCode = 400
        this.message = 'Please upload an Image'
    }
}
module.exports = {
    NotFoundError,
    AuthenticationError,
    BadRequestError,
    SchemaValidationError,
    InvalidFileTypeError
}