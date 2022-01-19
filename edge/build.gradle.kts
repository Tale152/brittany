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
