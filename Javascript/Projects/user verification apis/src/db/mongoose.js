const mongoose = require('mongoose')
const User = require('../models/User')
const path = require('path')
require("dotenv").config({ path: path.resolve(__dirname, "../../.env") });

const dbpath= process.env.MONGO_URI ||'mongodb://127.0.0.1/user-profile-api'

mongoose.connect(dbpath, {
    useNewUrlParser: true, 
    useUnifiedTopology: true,
    useCreateIndex: true,
    useFindAndModify: true
}).then(async()=>{
    await User.init()
})