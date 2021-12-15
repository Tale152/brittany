tasks.register<Exec>("authDevUp"){
    commandLine("docker-compose", "-f", "auth-service-dev-compose.yml", "-p", "auth-service-dev", "up", "-d")
}

tasks.register<Exec>("authDevLog"){
    commandLine("docker-compose", "-f", "auth-service-dev-compose.yml", "-p", "auth-service-dev", "logs", "-f", "auth")
}

tasks.register<Exec>("authDevDown"){
    commandLine("docker-compose", "-f", "auth-service-dev-compose.yml", "-p", "auth-service-dev", "down")
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

