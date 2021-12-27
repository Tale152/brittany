const jwt = require('jsonwebtoken')

const environmentName = "Test env"
const environmentPassword = "envpsw"
const greenhouseName = "Brittany"
const organizationName = "TestOrganization"
const name = "Peter"
const surname = "Parker"
const mail = "peter.parker@test.com"
const birthdate = "1962-06-05"
const password = "psw"
const correctOrganizationBody = {
    organizationName: organizationName,
    name: name,
    surname: surname,
    mail: mail,
    birthdate: birthdate,
    password: password
}

module.exports = {
    environmentName: environmentName,
    environmentPassword: environmentPassword,
    greenhouseName: greenhouseName,
    organizationName: organizationName,
    name: name,
    surname: surname,
    mail: mail,
    birthdate: birthdate,
    password: password,
    correctOrganizationBody: correctOrganizationBody,
    correctAgentToken: jwt.sign({}, require('../../src/conf').agentTokenSecret),
    correctFarmerToken: jwt.sign({}, require('../../src/conf').farmerTokenSecret),
    wrongToken: jwt.sign({}, "wrong")
}
