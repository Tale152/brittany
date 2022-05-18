import org.apache.tools.ant.taskdefs.condition.Os

tasks.register<Exec>("authDevUp"){
    commandLine("docker-compose", "-f", "auth-service-dev-compose.yml", "-p", "auth-service-dev", "up", "-d")
}

tasks.register<Exec>("authDevLog"){
    commandLine("docker-compose", "-f", "auth-service-dev-compose.yml", "-p", "auth-service-dev", "logs", "-f", "auth")
}

tasks.register<Exec>("authDevDown"){
    commandLine("docker-compose", "-f", "auth-service-dev-compose.yml", "-p", "auth-service-dev", "down")
}

tasks.register<Exec>("settingsDevUp"){
    commandLine("docker-compose", "-f", "settings-service-dev-compose.yml", "-p", "settings-service-dev", "up", "-d")
}

tasks.register<Exec>("settingsDevLog"){
    commandLine("docker-compose", "-f", "settings-service-dev-compose.yml", "-p", "settings-service-dev", "logs", "-f", "settings")
}

tasks.register<Exec>("settingsDevDown"){
    commandLine("docker-compose", "-f", "settings-service-dev-compose.yml", "-p", "settings-service-dev", "down")
}

tasks.register<Exec>("persistenceDevUp"){
    commandLine("docker-compose", "-f", "persistence-service-dev-compose.yml", "-p", "persistence-service-dev", "up", "-d")
}

tasks.register<Exec>("persistenceDevLog"){
    commandLine("docker-compose", "-f", "persistence-service-dev-compose.yml", "-p", "persistence-service-dev", "logs", "-f", "persistence")
}

tasks.register<Exec>("persistenceDevDown"){
    commandLine("docker-compose", "-f", "persistence-service-dev-compose.yml", "-p", "persistence-service-dev", "down")
}

tasks.register<Exec>("coreDevUp"){
    if(project.hasProperty("organization") && project.hasProperty("greenhouse") &&
        project.hasProperty("environment") && project.hasProperty("password")) {
        val organizationEnv = "ORGANIZATION_NAME=" + project.findProperty("organization")
        val greenhouseEnv = "GREENHOUSE_NAME=" + project.findProperty("greenhouse")
        val environmentEnv = "ENVIRONMENT_NAME=" + project.findProperty("environment")
        val passwordEnv = "ENVIRONMENT_PASSWORD=" + project.findProperty("password")
        commandLine("docker", "run",
                    "-e", organizationEnv,
                    "-e", greenhouseEnv,
                    "-e", environmentEnv,
                    "-e", passwordEnv,
                    "-d", "--rm", "--name", "greenhouse-core-dev",
                    "alessandrotalmi/brittany-greenhouse-core-dev:latest")
    } else {
        throw IllegalArgumentException("Missing parameters")
    }
}

tasks.register<Exec>("coreDevLog"){
    commandLine("docker", "logs", "-f", "greenhouse-core-dev")
}

tasks.register<Exec>("coreDevDown"){
    commandLine("docker", "stop", "greenhouse-core-dev")
}

tasks.register<Exec>("edgeDevUp"){
    if (!(Os.isFamily(Os.FAMILY_WINDOWS) || Os.isFamily(Os.FAMILY_MAC))) {
        if(project.hasProperty("pathToESP8266") && project.hasProperty("ssid") && project.hasProperty("password")) {
            val edgeSsid = "BRITTANY_WIFI_SSID=" + project.findProperty("ssid")
            val edgePassword = "BRITTANY_WIFI_PSWD=" + project.findProperty("password")
            commandLine("docker", "run",
                        "--device=" + project.findProperty("pathToESP8266"),
                        "-e", edgeSsid,
                        "-e", edgePassword,
                        "-d", "--rm", "--name", "edge-dev",
                        "alessandrotalmi/brittany-edge-dev:latest")
        } else {
            throw IllegalArgumentException("Missing parameters")
        }
    } else {
        throw IllegalArgumentException("Cannot run this task on Windows or MacOS")
    }
}

tasks.register<Exec>("edgeDevLog"){
    commandLine("docker", "logs", "-f", "edge-dev")
}

tasks.register<Exec>("edgeDevDown"){
    commandLine("docker", "stop", "edge-dev")
}

tasks.register<Exec>("clientDevUp"){
    commandLine("docker", "run", "-d", "--rm",
        "-p", "3000:3000",
        "-e", "REACT_APP_PERSISTENCE_SERVICE_ADDRESS=http://localhost:80",
        "-e", "REACT_APP_AUTH_SERVICE_ADDRESS=http://localhost:81",
        "-e", "REACT_APP_SETTINGS_SERVICE_ADDRESS=http://localhost:82",
        "--name", "web-client-dev", "alessandrotalmi/brittany-web-client-dev:latest"
    )
}

tasks.register<Exec>("clientDevLog"){
    commandLine("docker", "logs", "-f", "web-client-dev")
}

tasks.register<Exec>("clientDevDown"){
    commandLine("docker", "stop", "web-client-dev")
}

tasks.register("servicesUp"){
    dependsOn("authDevUp")
    dependsOn("settingsDevUp")
    dependsOn("persistenceDevUp")
}

tasks.register("servicesDown"){
    dependsOn("authDevDown")
    dependsOn("settingsDevDown")
    dependsOn("persistenceDevDown")
}

tasks.register<Exec>("webUp"){
    dependsOn("servicesUp")
    mustRunAfter("servicesUp")
    commandLine("docker", "run", "-d", "--rm",
        "-p", "3000:3000",
        "-e", "REACT_APP_PERSISTENCE_SERVICE_ADDRESS=http://localhost:80",
        "-e", "REACT_APP_AUTH_SERVICE_ADDRESS=http://localhost:81",
        "-e", "REACT_APP_SETTINGS_SERVICE_ADDRESS=http://localhost:82",
        "--name", "web-client-dev", "alessandrotalmi/brittany-web-client-dev:latest"
    )
}

tasks.register("webDown"){
    dependsOn("servicesDown")
    dependsOn("clientDevDown")
}

tasks.register<Exec>("systemUp"){
    dependsOn("webUp")
    mustRunAfter("webUp")
    if(project.hasProperty("organization") && project.hasProperty("greenhouse") &&
        project.hasProperty("environment") && project.hasProperty("password")) {
        val organizationEnv = "ORGANIZATION_NAME=" + project.findProperty("organization")
        val greenhouseEnv = "GREENHOUSE_NAME=" + project.findProperty("greenhouse")
        val environmentEnv = "ENVIRONMENT_NAME=" + project.findProperty("environment")
        val passwordEnv = "ENVIRONMENT_PASSWORD=" + project.findProperty("password")
        commandLine("docker", "run",
                    "-e", organizationEnv,
                    "-e", greenhouseEnv,
                    "-e", environmentEnv,
                    "-e", passwordEnv,
                    "-d", "--rm", "--name", "greenhouse-core-dev",
                    "alessandrotalmi/brittany-greenhouse-core-dev:latest")
    } else {
        throw IllegalArgumentException("Missing parameters")
    }
}

tasks.register("systemDown"){
    dependsOn("webDown")
    dependsOn("coreDevDown")
}
