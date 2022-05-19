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

const supertest = require('supertest')

async function httpTest(type, server, route, params, token, code, then){
    if(type == "get"){
        await supertest(server)
            .get(route)
            .query(params)
            .set('token', token)
            .expect(code)
            .then((res) => then(res))
    } else if(type == "post"){
        await supertest(server)
            .post(route)
            .send(params)
            .set('token', token)
            .expect(code)
            .then((res) => then(res))
    }
}

module.exports.get = async function(server, route, query, token, code, then){
    await httpTest("get", server, route, query, token, code, then)
}

module.exports.post = async function(server, route, body, token, code, then){
    await httpTest("post", server, route, body, token, code, then)
}
