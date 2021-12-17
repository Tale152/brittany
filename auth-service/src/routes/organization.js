const express = require('express')
const router = express.Router()

const tokenAuth = require('./controllers/tokenAuth')

const PostCreateOrganization = require("./controllers/organization/post-create")
const GetOrganizationInfo = require("./controllers/organization/get-info")

router.post("/organization/create", (req, res) => PostCreateOrganization.createOrganizationController(req, res))

router.get("/organization/info", tokenAuth.verifyToken, (req, res) => GetOrganizationInfo.organizationInfoController(req, res))

module.exports = router
