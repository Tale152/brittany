/*
 * Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
