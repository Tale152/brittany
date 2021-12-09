import com.github.gradle.node.task.NodeTask

plugins{
  id("com.github.node-gradle.node") version "3.1.1"
}

tasks.npmInstall{
  nodeModulesOutputFilter{
    exclude("notExistingFile")
  }
}

tasks.register<NodeTask>("run"){
  dependsOn(tasks.npmInstall)
  script.set(file("index.js"))
}

tasks.register<NodeTask>("test"){
  dependsOn(tasks.npmInstall)
  script.set(file("node_modules/jest/bin/jest.js"))
}

tasks.register<Exec>("dockerUp"){
  commandLine("docker-compose", "up", "-d", "--build")
}

tasks.register<Exec>("dockerDown"){
  commandLine("docker-compose", "down")
}

tasks.register<Exec>("dockerLog"){
  commandLine("docker-compose", "logs", "-f", "auth")
}

tasks.register<Exec>("dockerClearDb"){
  commandLine("docker", "volume", "rm", "auth-service_database_data")
}
