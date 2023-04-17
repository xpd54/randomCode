const selling = function(User, Product) {
    const userBucket = async function(userId) {
        const user = await User.findOne({_id: userId})
        return user.bucket;
    }

    const addToBucket = async function(userId, productId) {
        const user = await User.findOne({_id: userId})
        const product = await Product.findOne({_id: productId})
        user.bucket.pushback(product._id)
        await user.save();
    }

    const addProduct = async function(productData) {
        const newProduct = new Product(productData)
        const savedProduct = await newProduct.save()
        return savedProduct.toObject()
    }

    const getProduct = async function(productId) {
        return await Product.findOne({_id: productId})
    }

    return {userBucket, addToBucket, getProduct, addProduct}
}

module.exports = selling