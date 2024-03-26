const express = require("express");

const app = express();
app.get("/",(req,res) => {
    console.log("Request coming")
    res.send("Hello World")
})
const port = 3000;
app.listen(port,()=>{
    console.log("Up and running on port:-", port)
});