module.exports = {
    serverPort: process.env.PORT || 80,
    farmerTokenSecret: process.env.FARMER_TOKEN_SECRET || "devFarmerTokenSecret",
    agentTokenSecret: process.env.AGENT_TOKEN_SECRET || "devAgentTokenSecret",
    dbAddress: process.env.DB || 'mongodb://127.0.0.1/brittany_persistence',
    testDbAddress: 'mongodb://127.0.0.1/test_brittany_persistence',
    asciiArt: 
        '#####  ###### #####   ####  #  ####  ##### ###### #    #  ####  ######\n' +
        '#    # #      #    # #      # #        #   #      ##   # #    # #     \n' +     
        '#    # #####  #    #  ####  #  ####    #   #####  # #  # #      ##### \n' +
        '#####  #      #####       # #      #   #   #      #  # # #      #     \n' +    
        '#      #      #   #  #    # # #    #   #   #      #   ## #    # #     \n' +
        '#      ###### #    #  ####  #  ####    #   ###### #    #  ####  ######',
}
