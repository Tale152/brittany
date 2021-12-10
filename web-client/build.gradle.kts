import com.github.gradle.node.npm.task.NpmTask
import com.github.gradle.node.npm.task.NpxTask

plugins{
  id("com.github.node-gradle.node") version "3.1.1"
}

tasks.npmInstall{
  nodeModulesOutputFilter{
    exclude("notExistingFile")
  }
}

tasks.register<NpxTask>("kill"){
  command.set("kill-port")
  args.set(listOf("3000"))
}

tasks.register<NpmTask>("run"){
  dependsOn(tasks.npmInstall)
  dependsOn(tasks.named("kill"))
  npmCommand.set(listOf("start"))
}

tasks.register<NpmTask>("test"){
  dependsOn(tasks.npmInstall)
  dependsOn(tasks.named("kill"))
  npmCommand.set(listOf("run", "test", "--"))
}

tasks.register<Exec>("dockerUp"){
  commandLine("docker-compose", "up", "-d", "--build")
}

tasks.register<Exec>("dockerDown"){
  commandLine("docker-compose", "down")
}

tasks.register<Exec>("dockerLog"){
  commandLine("docker-compose", "logs", "-f", "web_client")
}
