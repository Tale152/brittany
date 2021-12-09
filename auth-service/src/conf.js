module.exports = {
    serverPort: process.env.PORT || 81,
    dbAddress: process.env.DB || 'mongodb://127.0.0.1/brittany_auth',
    testDbAddress: 'mongodb://127.0.0.1/brittany_auth',
    webClientAddress: process.env.WEB_CLIENT_ADDRESS || 'http://localhost:3000',
    asciiArt: 
        '    ____       _ __  __                                   __  __\n' +
        '   / __ )_____(_) /_/ /_____ _____  __  __   ____ ___  __/ /_/ /_\n' +
        '  / __  / ___/ / __/ __/ __ `/ __ \\/ / / /  / __ `/ / / / __/ __ \\ \n' +
        ' / /_/ / /  / / /_/ /_/ /_/ / / / / /_/ /  / /_/ / /_/ / /_/ / / /\n' +
        '/_____/_/  /_/\\__/\\__/\\__,_/_/ /_/\\__, /   \\__,_/\\__,_/\\__/_/ /_/\n' +
        '                                 /____/'                          
     
}
