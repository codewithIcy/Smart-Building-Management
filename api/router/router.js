import express from 'express'
import port from '../controller/serial.js'

const router = express.Router()

router.get('/fan/:state', async(req, res)=>{
    const state = req.params.state
    port.write(`Fan:${state}`, (err) => {
    if (err) {
        return console.log('Error writing:', err.message);
    }
        console.log('Message sent');
        console.log(state)
    });

    res.json()
})

router.get('/heat/:state', async(req, res)=>{
    const state = req.params.state
    port.write(`Heat:${state}`, (err) => {
    if (err) {
        return console.log('Error writing:', err.message);
    }
        console.log('Message sent');
        console.log(state)
    });

    res.json()
})

router.get('/Temperature/:state', async(req, res)=>{
    const state = req.params.state
    port.write(`Temperature:${state}`, (err) => {
    if (err) {
        return console.log('Error writing:', err.message);
    }
        console.log('Message sent');
        console.log(state)
    });

    res.json()
})

router.get('/', async(req,res)=>{
    res.render('index.ejs')
})

export default router