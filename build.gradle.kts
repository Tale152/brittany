tasks.register<Exec>("authDevUp"){
    commandLine("docker-compose", "-f", "auth-service-dev-compose.yml", "-p", "auth-service-dev", "up", "-d")
}

tasks.register<Exec>("authDevLog"){
    commandLine("docker-compose", "-f", "auth-service-dev-compose.yml", "-p", "auth-service-dev", "logs", "-f", "auth")
}

tasks.register<Exec>("authDevDown"){
    commandLine("docker-compose", "-f", "auth-service-dev-compose.yml", "-p", "auth-service-dev", "down")
}
