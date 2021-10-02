const mongoose = require('mongoose')
const bcrypt = require('bcryptjs')
const jwt = require('jsonwebtoken')
const validator = require('validator')
const path = require('path')
require("dotenv").config({ path: path.resolve(__dirname, "../../.env") });
const userSchema = mongoose.Schema({
    name:{
        type: String,
        required:true,
        trim:true
    },
    email:{
        type:String,
        required:true,
        unique:true,
        trim:true,
        lowercase:true,
        validate(value){
            if(!validator.isEmail(value)){
              throw new Error('email invalid')
            }
        }

    },
    Age:{
        type:Number,
        default:0,
        validate(value){
            if(value<0){
                throw new Error('Invalid Age!')
            }
        }
    },
    password:{
        type:String,
        required:true,
        minlength:7,
        validate(value){
        if (value.toLowerCase().includes("password")){
            throw new Error('invalid password!')
        }
       
    }
},
    tokens:[{
        token:{
            type: String,
            required:true
        }
    
    }],
    avatar:{
        type: Buffer
    },
    otp:{
        type:Number
    },
    email_verified:{
        type:Boolean,
        default:false
    }
},{
    timestamps:true
})

userSchema.methods.toJSON= function(){
    const user = this
    const userObject =user.toObject()

    delete userObject.password
    delete userObject.tokens
    delete userObject.avatar

    return userObject
}
userSchema.methods.generateAuthToken = async function() {

    const user=this
    const token= jwt.sign({_id: user._id.toString()},process.env.JWT_KEY)
    user.tokens=user.tokens.concat({token})
    await user.save()
    return token
    
}
userSchema.statics.findByCredentials= async(email,password)=>{
    const user = await userModel.findOne({email})
    
    if(!user){
        throw new Error('Unable to login')
    }
    const isMatch= await bcrypt.compare(password,user.password)
    if(!isMatch){
        throw new Error('Unable to login')
    }
    return user
}

userSchema.pre('save', async function(next){
    const user = this
    if(user.isModified('password')){
        user.password=await bcrypt.hash(user.password,8)
    }
    
    next()
})

const userModel = mongoose.model('User',userSchema)

module.exports = userModel