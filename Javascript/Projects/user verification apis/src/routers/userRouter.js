const express = require('express')
const userModel = require('../models/User')
const errorHandler = require('./../middleware/errorHandler')
const successHandler = require('./../middleware/successHandler')
const authFunction = require('./../middleware/auth')
const mailer = require('../middleware/mail')
const { UserCreatedSuccess, UserLoggedInSuccess,UserLoggedOutSuccess , UserDeletedSuccess} = require('../utils/success')
const { BadRequestError, AuthenticationError, SchemaValidationError,InvalidFileTypeError, NotFoundError } = require('../utils/error')
const multer = require('multer')
const sharp = require('sharp')
const { text } = require('express')
require('dotenv').config()

const upload = multer({
    limits:{
        fileSize:10000000,
    },
    fileFilter(req,file,cb){
        if (!file.originalname.match(/\.(jpg|jpeg|png)$/)){
            return cb(new InvalidFileTypeError)
        }
        cb(undefined,true)
    }
})

const router = new express.Router()


//route for sign up
router.post('/signup',async(req,res)=>{
   const user = new userModel(req.body)
   
    try {
        const token = await user.generateAuthToken()
        mailer(req.body.email,'Sign Up Email','Thanks For Signing Up!')
        const success = new UserCreatedSuccess
        successHandler(success,res)
       console.log(token)
       } catch (e) {
        
        errorHandler(new SchemaValidationError,req,res)
       }
})

//route for login
router.post('/login',async(req,res)=>{
    try {
        const user = await userModel.findByCredentials(req.body.email,req.body.password)
        const token = await user.generateAuthToken()
        console.log(token)
        const success=new UserLoggedInSuccess
        successHandler(success,res)
    } catch (e) {
        errorHandler(new AuthenticationError,req,res)
    }
})

//route for logout
//?
router.post('/logout',authFunction,async (req,res)=>{
    try {
        req.user.tokens=req.user.tokens.filter((token)=>{
            return token.token !== req.token
        })
        await req.user.save()
        const success=new UserLoggedOutSuccess
       successHandler(success,res)
    } catch (e) {
        
        errorHandler(new BadRequestError,req,res)
    }
})
router.post ('/logOutAll',authFunction,async(req,res)=>{
    try {
        req.user.tokens=[]
        await req.user.save()
        const success=new UserLoggedOutSuccess
        successHandler(success,res)
    } catch (e) {
        errorHandler(new BadRequestError,req,res)
    }
})

//route for deleting user
router.delete('/delete',authFunction, async(req,res)=>{
    try {
        
       const user =await req.user.remove()
       console.log(user)
       const success=new UserDeletedSuccess
       successHandler(success,res)
    } catch (e) {
        errorHandler(new BadRequestError,req,res)
    }
})
router.get('/users/me',authFunction, async(req,res)=>{
     
    res.send(req.user)
})



router.patch('/users/me',authFunction,async(req,res)=>{
    const updates = Object.keys(req.body)
    const allowedUpdates=['name','Age','password','email']
    const isValidOperation=updates.every((update)=>allowedUpdates.includes(update))

   if (!isValidOperation){
       return res.status(400).send('Invalid Updates!')
   }
  
    try {
       const user = req.user
         
       updates.forEach((update)=>user[update]=req.body[update])

       await user.save()

          res.send(user)
    } catch (error) {
        errorHandler(new BadRequestError,req,res)
    }

})
// posting image
router.post('/user/me/avatar',authFunction, upload.single('avatar'), async(req,res)=>{
    const buffer = await sharp(req.file.buffer).png().resize({width:250,height:250}).toBuffer() 
    req.user.avatar=buffer
    await req.user.save()
    res.send(200)
})
//deleting image
router.delete('/user/me/avatar',authFunction, async(req,res)=>{
    req.user.avatar=undefined
    await req.user.save()
    res.send(200)
})
//serving image
router.get('/users/me/avatar',authFunction,async(req,res)=>{
    try {
        res.set('Content-Type','image/png')
        res.send(req.user.avatar)
    } catch (e) {
        errorHandler(e,req,res)
    }
})

router.post('/verify',authFunction,async(req,res)=>{
console.log('hi')
const otp = require('../middleware/otp')
req.user.otp=otp
await req.user.save()
const text = 'Your OTP is '+ otp + ' and it is valid for 3 minutes!' 
console.log(req.user.email)
mailer(req.user.email,'OTP For Email Verification!',text)
async function deleteOtp(){
    req.user.otp=null
    await req.user.save()
}
res.send('Mail Sent')
setTimeout(deleteOtp,180000)    
})

router.post('/verifyOTP',authFunction,async(req,res)=>{
    if (req.user.otp==null){
       return res.send('OTP Expired! Try Again!')
    }
    if(Number(req.user.otp)==Number(req.body.otp)){
        req.user.email_verified=true
        req.user.otp=null
        await req.user.save()
        const text = 'Hey ' +req.user.name + ' your email account has been verified successfully,Have a nice day!'
        mailer(req.user.email,'Successfull Verification',text)
        return res.send('Successfull!')
    }
    req.user.otp=null
    await req.user.save()
    res.send('Wrong OTP Entered!')
    
})

module.exports=router
