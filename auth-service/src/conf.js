module.exports = {
    serverPort: process.env.PORT || 81,
    farmerTokenSecret: process.env.FARMER_TOKEN_SECRET || "devFarmerTokenSecret",
    agentTokenSecret: process.env.AGENT_TOKEN_SECRET || "devAgentTokenSecret",
    passwordSalt: process.env.PASSWORD_SALT || 10,
    dbAddress: process.env.DB || 'mongodb://127.0.0.1/brittany_auth',
    testDbAddress: 'mongodb://127.0.0.1/test_brittany_auth',
    asciiArt: 
        '                 __  __\n' +
        '    ____  __  __/ /_/ /_\n' +
        '   / __ `/ / / / __/ __ \\ \n' +
        '  / /_/ / /_/ / /_/ / / /\n' +
        '  \\__,_/\\____/\\__/_/ /_/'                         
     
}
