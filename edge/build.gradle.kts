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

    val ssid: String by project
    val pswd: String by project

    if (project.hasProperty("ssid") && project.hasProperty("pswd")) {
        val wifiSecretsFile = File("src/wifi_secret.h")
        wifiSecretsFile.delete()
        wifiSecretsFile.writeText("#define WIFI_SSID \"" + ssid + "\"\n#define WIFI_PSWD \"" + pswd + "\"")

        val envs: List<String> = File("platformio.ini").readLines().filter{
                it.matches(Regex("\\[env:.*\\]"))
            }.map{
                it.substringAfter("[env:").substringBefore("]")
            }.filter {
                it != "native" && it != "nodemcuv2"
            }
        println("Please select the environment to upload: [0-" + (envs.size - 1).toString() + "]\n")
        for ((i, item) in envs.withIndex()) {
            println(i.toString() + ". " + item)
        }
        
        val userInput = readLine()?.toIntOrNull()
        if(userInput != null && userInput >= 0 && userInput < envs.size) {
            commandLine("pio", "run", "-e", envs[userInput], "-t", "upload")
        }
    }
}

tasks.register<Exec>("buildDockerImage"){
    commandLine("docker", "image", "build", ".", "-t", "edge")
}

tasks.register<Exec>("dockerUp"){
    dependsOn("buildDockerImage")
    if (project.hasProperty("pathToESP8266") && project.hasProperty("ssid") && project.hasProperty("password")) {
        val edgeSsid = "BRITTANY_WIFI_SSID=" + project.findProperty("ssid")
        val edgePassword = "BRITTANY_WIFI_PSWD=" + project.findProperty("password")
        commandLine("docker", "container", "run",
                    "--device=" + project.findProperty("pathToESP8266"),
                    "-e", edgeSsid,
                    "-e", edgePassword,
                    "-d", "--rm", "--name", "edge-container", "edge")
    }
}

tasks.register<Exec>("dockerDown"){
    commandLine("docker", "container", "stop", "edge-container")
}

tasks.register<Exec>("dockerLog"){
    commandLine("docker", "logs", "-f", "edge-container")
}
