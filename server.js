import express from 'express'
import cors from 'cors'
import router from './api/router/router.js'

const app = express()
const PORT = 5000

app.set('view engine', 'ejs')
app.use(cors())
app.use(express.json())
app.use(express.urlencoded({extended: true}))

app.use('/', router)


app.listen(PORT, ()=>{
    console.log(`Listening on port ${PORT}...`)
})