module.exports = {
    serverPort: process.env.PORT || 82,
    farmerTokenSecret: process.env.FARMER_TOKEN_SECRET || "devFarmerTokenSecret",
    agentTokenSecret: process.env.AGENT_TOKEN_SECRET || "devAgentTokenSecret",
    dbAddress: process.env.DB || 'mongodb://127.0.0.1/brittany_settings',
    testDbAddress: 'mongodb://127.0.0.1/test_brittany_settings',
    asciiArt:
        ' ______     ______     __     ______   ______   ______     __   __     __  __        ______     ______     ______   ______   __     __   __     ______     ______\n' +
        '/\\  == \\   /\\  == \\   /\\ \\   /\\__  _\\ /\\__  _\\ /\\  __ \\   /\\ "-.\\ \\   /\\ \\_\\ \\      /\\  ___\\   /\\  ___\\   /\\__  _\\ /\\__  _\\ /\\ \\   /\\ "-.\\ \\   /\\  ___\\   /\\  ___\\\n' +  
        '\\ \\  __<   \\ \\  __<   \\ \\ \\  \\/_/\\ \\/ \\/_/\\ \\/ \\ \\  __ \\  \\ \\ \\-.  \\  \\ \\____ \\     \\ \\___  \\  \\ \\  __\\   \\/_/\\ \\/ \\/_/\\ \\/ \\ \\ \\  \\ \\ \\-.  \\  \\ \\ \\__ \\  \\ \\___  \\\n' + 
        ' \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_\\    \\ \\_\\    \\ \\_\\  \\ \\_\\ \\_\\  \\ \\_\\"\\_\\   \\/\\_____\\     \\/\\_____\\  \\ \\_____\\    \\ \\_\\    \\ \\_\\  \\ \\_\\  \\ \\_\\\\"\\_\\  \\ \\_____\\  \\/\\_____\\\n' +
        '  \\/_____/   \\/_/ /_/   \\/_/     \\/_/     \\/_/   \\/_/\\/_/   \\/_/ \\/_/   \\/_____/      \\/_____/   \\/_____/     \\/_/     \\/_/   \\/_/   \\/_/ \\/_/   \\/_____/   \\/_____/'                      
     
}
