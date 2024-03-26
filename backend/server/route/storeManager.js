const User = require("../schema/userModel")
const Product = require("../schema/productModel")
const store = require("./management/store")(User, Product)
const user = require("./management/user")(User)
const getUserBucket = async function(req, res, next) {
    const {userId} = req.body
    try{
        const bucket = await store.userBucket(userId)
        const productList = bucket.map((productId) => {
            store.getProduct(productId)
        })
        req.data = productList
        req.typeName = "product"
    }catch(error) {
        console.log(error)
    }
    next()
}

const addUser = async function(req, res, next) {
    const {name, age, subscribed = false} = req.body
    try {
        const newUser = await user.addUser({name, age, subscribed});
        delete newUser._id
        delete newUser.bucket;
        req.data = [newUser];
        req.typeName = "user"
    } catch (error) {
        console.log(error)
    }
    next()
}

const addProduct = async function(req, res, next) {
    const {name, price, available, stock} = req.body
    const newProduct = await store.addProduct({name, price, available, stock})
    delete newProduct._id
    req.data = [newProduct]
    req.typeName = "product"
    next()
}

module.exports = {getUserBucket, addUser, addProduct}