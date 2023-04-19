const express = require("express")
const mongoose = require("mongoose")
const store = require("./route/storeRoute")
const user = require("./route/userRoute")
const axios = require("axios")
const mongoURL = 'mongodb://mongo:27017'
const rootURL = "https://httpbin.org/"
app = express()
app.use(express.json())
app.use("/store", store)
app.use("/user", user)
app.get("/", async (req, res) => {
    const url = rootURL+'get'
    const response = await axios.get(url)
    const data = response.data
    console.log(data)
    return res.json(data)
})

const port = 8080
app.listen(port,async ()=>{
    await mongoose
    .connect(mongoURL,{dbName: "shopping"})
    .catch((error) => {
        console.log(error);
    })
    console.log("Server running");
})

