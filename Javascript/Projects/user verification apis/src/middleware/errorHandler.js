const errorHandler = (err,req,res,next)=>{

    return res.status(err.statusCode).json({
        code: err.statusCode,
        message: err.message
    })
    
}

module.exports = errorHandler