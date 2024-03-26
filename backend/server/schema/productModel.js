const mongoose = require("mongoose")

const product = new mongoose.Schema({
    name:{type: String, default: "genaric name"},
    price:{type: Number, default: 0},
    available:{type: Boolean, default:false},
    stock:{type: Number, default:0}
})

module.exports = mongoose.model("product", product)