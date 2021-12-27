const mongoose = require("mongoose")
const conf = require('../../src/conf')

module.exports.createConnectionToTestDB = function(completionCallback){
    mongoose.connect(
        conf.testDbAddress,
        { useNewUrlParser: true, useUnifiedTopology: true },
        () => completionCallback()
    )
}

module.exports.resetTestDB = async function(){
    const collections = await mongoose.connection.db.collections()

    for (let collection of collections) {
        await collection.drop()
    }
}

module.exports.dropConnectedTestDB = function(completionCallback){
    mongoose.connection.db.dropDatabase(() => {
      mongoose.connection.close(() => completionCallback())
    })
}
