const { addUser } = require("./storeManager")
const { sendMessage } = require("./utility")

const route = require("express").Router()
route.post("/add_user", addUser, sendMessage)
module.exports = route