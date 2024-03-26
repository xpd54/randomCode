const mongoose = require("mongoose")
const {Schema} = mongoose

const user = new Schema({
    name: {type:String},
    bucket: {type: Array},
    age: {type:Number, default: 18},
    subscribed: {type: Boolean, default: false}
})

module.exports = mongoose.model("user", user)