const express = require('express')
const router = express.Router()

const PostCreateOrganization = require("./controllers/organization/post-create-organization")

router.post("/organization/create", (req, res) => PostCreateOrganization.createOrganizationController(req, res))

module.exports = router
