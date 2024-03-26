const route = require("express").Router()
const utility = require("./utility")
const storeManager = require("./storeManager")
route.get("/getUserBucket", storeManager.getUserBucket, utility.sendMessage)
route.post("/add_product", storeManager.addProduct,utility.sendMessage)
module.exports = route