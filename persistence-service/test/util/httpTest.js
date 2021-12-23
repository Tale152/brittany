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
