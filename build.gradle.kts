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
    commandLine("docker", "run", "-d", "--rm", "--name", "greenhouse-core-dev", "alessandrotalmi/brittany-greenhouse-core-dev:latest")
}

tasks.register<Exec>("coreDevLog"){
    commandLine("docker", "logs", "-f", "greenhouse-core-dev")
}

tasks.register<Exec>("coreDevDown"){
    commandLine("docker", "stop", "greenhouse-core-dev")
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
