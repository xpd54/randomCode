const userManagement = function(User) {
    const addUser = async function(userData) {
        const newUser = new User(userData);
        const savedUser = await newUser.save()
        return savedUser.toObject()
    }

    const removeUser = async function(userId) {

    }
    return {addUser, removeUser}
}

module.exports = userManagement