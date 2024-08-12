const sendMessage = function(req, res, next) {
    const {data, typeName} = req
    if(data.length) {
        return res.status(200).json({type:typeName, data})
    } else {
        return res.status(200).json({data:"n/a"})
    }
}

module.exports = {sendMessage}