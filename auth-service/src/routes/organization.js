const express = require('express')
const router = express.Router()

const farmerTokenAuth = require('./controllers/farmerTokenAuth')
const PostCreateOrganization = require("./controllers/organization/post-create")
const GetOrganizationInfo = require("./controllers/organization/get-info")

router.post("/organization/create", PostCreateOrganization.createOrganizationController)

router.get("/organization/info", farmerTokenAuth.verifyToken, GetOrganizationInfo.organizationInfoController)

module.exports = router
