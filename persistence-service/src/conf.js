module.exports = {
    serverPort: process.env.PORT || 80,
    dbAddress: process.env.DB || 'mongodb://127.0.0.1/brittany_persistence',
    testDbAddress: 'mongodb://127.0.0.1/brittany_persistence_test',
    webClientAddress: process.env.WEB_CLIENT_ADDRESS || 'http://localhost:3000',
    asciiArt: 
        '######\n' +                                                                                                                                                                   
        '#     # #####  # ##### #####   ##   #    # #   #    #####  ###### #####   ####  #  ####  ##### ###### #    #  ####  ######\n' +
        '#     # #    # #   #     #    #  #  ##   #  # #     #    # #      #    # #      # #        #   #      ##   # #    # #     \n' +     
        '######  #    # #   #     #   #    # # #  #   #      #    # #####  #    #  ####  #  ####    #   #####  # #  # #      ##### \n' +
        '#     # #####  #   #     #   ###### #  # #   #      #####  #      #####       # #      #   #   #      #  # # #      #     \n' +    
        '#     # #   #  #   #     #   #    # #   ##   #      #      #      #   #  #    # # #    #   #   #      #   ## #    # #     \n' +
        '######  #    # #   #     #   #    # #    #   #      #      ###### #    #  ####  #  ####    #   ###### #    #  ####  ######',
}
