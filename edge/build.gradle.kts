tasks.register<Exec>("run") {
    commandLine("pio", "run", "-e", "nodemcuv2")
}

tasks.register<Exec>("test") {
    commandLine("pio", "test")
}

tasks.register<Exec>("testRealHw") {
    commandLine("pio", "test", "-e", "nodemcuv2")
}

tasks.register<Exec>("upload") {
    commandLine("pio", "run", "-e", "nodemcuv2", "-t", "upload")
}
