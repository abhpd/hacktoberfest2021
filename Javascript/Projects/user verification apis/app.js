const express = require('express')
require('./src/db/mongoose')

const app = express()
const port = process.env.PORT || 3000

const userRouter = require('./src/routers/userRouter')


const errorHandler = require('./src/middleware/errorHandler')
const { NotFoundError } = require('./src/utils/error')

app.use(express.json())
app.use(userRouter)

app.all('*',(req,res,next)=>{
    throw new NotFoundError()
})

app.use(errorHandler)

app.listen(port,()=>{
    console.log('Server is up on Port:', port)
})