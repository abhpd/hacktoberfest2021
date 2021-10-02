const successHandler = (suc,res) =>{
    return res.status(suc.statusCode).send({
        statusCode: suc.statusCode,
        message: suc.message
    })
}

module.exports = successHandler