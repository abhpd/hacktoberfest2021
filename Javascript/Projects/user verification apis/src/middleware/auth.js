const jwt=require('jsonwebtoken')
const userModel = require('../models/User')
const { AuthenticationError } = require('./../utils/error')
const errorHandler = require('./errorHandler')
const path = require('path')
require("dotenv").config({ path: path.resolve(__dirname, "../../.env") });
const authFunction = async (req,res,next)=>{
    try{
        
        const token=req.header('Authorization').replace('Bearer ', '')
        const decoded=jwt.verify(token,process.env.JWT_KEY)
        const user =await userModel.findOne({_id: decoded._id,'tokens.token':token})
        
        if(!user)
        { 
            throw new AuthenticationError()
        }
        
        req.user=user
        req.token=token
        next()
        
    }
    catch(e){
        errorHandler(new AuthenticationError,req,res)
    }
}

module.exports = authFunction