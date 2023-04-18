const express = require("express")
const mongoose = require("mongoose")
const store = require("./route/storeRoute")
const user = require("./route/userRoute")
const mongoURL = 'mongodb://0.0.0.0:27017'
app = express()
app.use(express.json())
app.use("/store", store)
app.use("/user", user)
app.get("/", (req, res) => {
    res.send("Hello World!");
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

