module.exports = {
    serverPort: process.env.PORT || 81,
    farmerTokenSecret: process.env.FARMER_TOKEN_SECRET || "devFarmerTokenSecret",
    agentTokenSecret: process.env.AGENT_TOKEN_SECRET || "devAgentTokenSecret",
    dbAddress: process.env.DB || 'mongodb://127.0.0.1/brittany_auth',
    testDbAddress: 'mongodb://127.0.0.1/test_brittany_auth',
    asciiArt: 
        '    ____       _ __  __                                   __  __\n' +
        '   / __ )_____(_) /_/ /_____ _____  __  __   ____ ___  __/ /_/ /_\n' +
        '  / __  / ___/ / __/ __/ __ `/ __ \\/ / / /  / __ `/ / / / __/ __ \\ \n' +
        ' / /_/ / /  / / /_/ /_/ /_/ / / / / /_/ /  / /_/ / /_/ / /_/ / / /\n' +
        '/_____/_/  /_/\\__/\\__/\\__,_/_/ /_/\\__, /   \\__,_/\\__,_/\\__/_/ /_/\n' +
        '                                 /____/'                          
     
}
