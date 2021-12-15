const Role = require('../mongoose/role')
const RoleFactory = require('../mongoose/factories/role')

const roles = ["Owner", "Manager", "Employee"]

module.exports.populateRoles = async function() {
    for (i = 0; i < roles.length; i++) {
        await Role.findOne({ name: roles[i]}).then(async result => {
            if(result === null){
                RoleFactory.createRole(roles[i]).save()
            }
        })
    } 
}
