# Brittany - Table of contents
- [What is Brittany](#what-is-brittany)
- [The project](#the-project)
- [How to launch the project](#how-to-launch-the-project)
    - [Method 1: Use production Services, Client and images](#method-1-use-production-services-client-and-images)
    - [Method 2: Run everything locally using dev images from Docker Hub](#method-2-run-everything-locally-using-images-from-docker-hub)
    - [Method 3: Run everything locally compiling Docker images](#method-3-run-everything-locally-compiling-docker-images)
    - [Method 4: Run everything locally without Docker](#method-4-run-everything-locally-without-docker)
- [Local testing](#continuous-integration)
- [Continuous integration](#continuous-integration)
- [Deployment](#deployment)
- [License](#license)

# What is Brittany
Brittany is a software as a service aimed to simplify and automate the management of greenhouses with the execution (inside of a private network) of a agent-driven coordinator; said coordinator uses sensors and actuators dinamically added inside the same private network allowing to easily scale the coordinator's capabilities to act in the real world.

Using a Web Client the final user can, using any network, access the data recorded by the coordinator and also set the coordinator's parameters.

There is also a cloud of microservices (with whom coordinators and clients communicate) created to provide authentication and persistence in the Brittany ecosystem.

The keyword in Brittany's philosophy is _scalability_, aiming to provide a service for the management of a potentially limitless number of greenhouses equipped with dinamically expandable capabilities in a way that is transparent to the end user; said user will only need to obtain a new physical module and connect it to the network of his coordinator.

# The project
This project was created for a combination of two academic courses for the Master degree in [Engineering and Computer Science](https://corsi.unibo.it/2cycle/ComputerScienceEngineering) at University of Bologna (Cesena department).  

Said academic courses are:
- [Pervasive Computing](https://www.unibo.it/en/teaching/course-unit-catalogue/course-unit/2021/412647)
- [Laboratory of Software Systems](https://www.unibo.it/en/teaching/course-unit-catalogue/course-unit/2021/412677)

Using the GitHub Pages section of this repository it is possible to see the [documentation](https://tale152.github.io/brittany/) of this project.

The project idea, engineering and development was made by the FaTaTe team:
- [Filaseta Angelo](https://github.com/AngeloFilaseta)
- [Talmi Alessandro](https://github.com/Tale152)
- [Tronetti Elisa](https://github.com/ElisaTronetti)

# How to launch the project
Here will be listed all ways to launch the project, starting from the simplest way up to more complex ones.  

All the methodologies require the following __hardware__:
- A machine to run Greenhouse Core on (and possibly the Services, depending on the chosen methodology)
- One or more ESP8266 for running Edge

The machine running Greenhouse Core and the ESP8266 __must__ be connected on the same LAN.

## __Method 1__: Use production Services, Client and images
This method will use the services and the [client](https://brittany-web-client.herokuapp.com/) already deployed online, freeing you from the necessity of also running them locally.  
The production Docker images for Greenhouse Core and Edge will also be used.

### __Step 0__: Required Software
- [Docker](https://docs.docker.com/get-docker/)

Windows and MacOS users will also require [PlatformIO](https://platformio.org/) to be able to run Edge since, at the time of writing, Docker can't access USB ports on those operative systems.  
See [_Run Edge (all operative systems)_](#step-4-run-edge-all-operative-systems) on Method 4 to read instruction on how to do that.

### __Step 1__: Run Greenhouse Core
Run the following command to execute on your machine Greenhouse Core:
```
docker run -e ORGANIZATION_NAME=<ORGANIZATION-NAME-HERE> -e GREENHOUSE_NAME=<GREENHOUSE-NAME-HERE> -e ENVIRONMENT_NAME=<ENVIRONMENT-NAME-HERE> -e ENVIRONMENT_PASSWORD=<ENVIRONMENT-PASSWORD-HERE> --rm --name greenhouse-core alessandrotalmi/brittany-greenhouse-core:latest
```
This command will download the image from DockerHub and execute a container (named greenhouse-core) running Greenhouse Core.  
Using _-e_ you'll need to provide four parameters:
- __ORGANIZATION_NAME__: the name of your organization, previously registered using the client
- __GREENHOUSE_NAME__: the name of the greenhouse, previously created using the client, that contains the environment that Greenhouse Core will coordinate
- __ENVIRONMENT_NAME__: the name of the environment, previously created using the client, that Greenhouse Core will coordinate
- __ENVIRONMENT_PASSWORD__: the password of the environment, previously created using the client, that Greenhouse Core will coordinate

### __Step 2__: Run Edge (linux only, Windows and MacOS [here](#step-4-run-edge-all-operative-systems))
Once you have connected an ESP8266 to your machine, run the following command to flash Edge on the chip:
```
docker run --device=<PATH-TO-ESP8266> -e BRITTANY_WIFI_SSID=<WIFI-SSID-HERE> -e BRITTANY_WIFI_PSWD=<WIFI-PASSWORD-HERE> --rm --name edge alessandrotalmi/brittany-edge:latest
```
This command will download the image from DockerHub and execute a container (named edge) running Edge for the flashing process.  
You'll need to provide the following parameters:
- __--device__: path to the USB port where ESP8266 is connected (es: /dev/ttyUSB0)
- __-e BRITTANY_WIFI_SSID__: SSID of the Wifi to which the ESP8266 will connect to
- __-e BRITTANY_WIFI_PSWD__: password of the Wifi to which the ESP8266 will connect to

Once the flashing process ends the ESP8266 will start executing Edge each time it is turned on.

## __Method 2__: Run everything locally using dev images from Docker Hub
This method will use the dev images (from DockerHub) of every sub-project, requiring you to also run the Services locally.  
It is important to use the dev image also on Greenhouse Core (not using the step from Method 1) since it uses the correct connection string to connect to the local instances of the services.

### __Step 0__: Required software
- [Docker](https://docs.docker.com/get-docker/)
- [Gradle](https://gradle.org/install/)

Windows and MacOS users will also require [PlatformIO](https://platformio.org/) to be able to run Edge since, at the time of writing, Docker can't access USB ports on those operative systems.  
See [_Run Edge (all operative systems)_](#step-4-run-edge-all-operative-systems) on Method 4 to read instruction on how to do that.

### __Step 1__: Run Services and Client
Place yourself in the root directory of the project and run this command:
```
.\gradlew webUp
```
This Gradle task will run in one shot all the Services and the web client (that you can use at http://localhost:3000/), downloading the dev image from DockerHub.

### __Step 2__: Run Greenhouse Core
After setting up the environment using the Web Client, place yourself in the root of the project and run this command:
```
.\gradlew coreDevUp -Porganization=<ORGANIZATION-NAME-HERE> -Pgreenhouse=<GREENHOUSE-NAME-HERE> -Penvironment=<ENVIRONMENT-NAME-HERE> -Ppassword=<ENVIRONMENT-PASSWORD-HERE>
```
This task will run Greenhouse Core downloading the dev image from DockerHub.  
Using _-P_ (_yes, without a white space after_) you'll need to provide four parameters:
- __organization__: the name of your organization, previously registered using the client
- __greenhouse__: the name of the greenhouse, previously created using the client, that contains the environment that Greenhouse Core will coordinate
- __environment__: the name of the environment, previously created using the client, that Greenhouse Core will coordinate
- __password__: the password of the environment, previously created using the client, that Greenhouse Core will coordinate


### __Step 3__: Run Edge (linux only, Windows and MacOS [here](#step-4-run-edge-all-operative-systems))
Once you have connected an ESP8266 to your machine, run the following command to flash Edge on the chip:
```
.\gradlew edgeDevUp -PpathToESP8266=<PATH-TO-ESP8266> -Pssid=<WIFI-SSID-HERE> -Ppassword=<WIFI-PASSWORD-HERE>
```
This command will download the dev image from DockerHub and execute a container running Edge for the flashing process.  
You'll need to provide the following parameters:
- __pathToESP8266__: path to the USB port where ESP8266 is connected (es: /dev/ttyUSB0)
- __ssid__: SSID of the Wifi to which the ESP8266 will connect to
- __password__: password of the Wifi to which the ESP8266 will connect to

### __Step 4__: Shut down Brittany
In order to stop the execution of the Docker containers of the Services, the Web Client and Greenhouse Core, place yourself in the root of the project and run the following command:
```
.\gradlew systemDown
```

### __Step 1 and 2 after environment setup__
Once the environment is created the first time using the Web Client, you can execute step 1 and 2 in one shot using this command:
```
.\gradlew systemUp -Porganization=<ORGANIZATION-NAME-HERE> -Pgreenhouse=<GREENHOUSE-NAME-HERE> -Penvironment=<ENVIRONMENT-NAME-HERE> -Ppassword=<ENVIRONMENT-PASSWORD-HERE>
```

## __Method 3__: Run everything locally compiling Docker images
Here no image coming from DockerHub will be used; instead, every Docker image will be compiled and executed locally.

### __Step 0__: Required software
- [Docker](https://docs.docker.com/get-docker/)
- [Gradle](https://gradle.org/install/)

Windows and MacOS users will also require [PlatformIO](https://platformio.org/) to be able to run Edge since, at the time of writing, Docker can't access USB ports on those operative systems.  
See [_Run Edge (all operative systems)_](#step-4-run-edge-all-operative-systems) on Method 4 to read instruction on how to do that.

### __Step 1__: Run Services
Place yourself on each of the Services folders (in no particolar order) and run the following command:
```
.\gradlew dockerUp
```

### __Step 2__: Run Client
After having executed Step 1 _for each service_, place yourself in the Web Client directory and run the same command as step 1:
```
.\gradlew dockerUp
```
You can use the client at http://localhost:3000/

### __Step 3__: Run Greenhouse Core
After having setup the environment using the Web Client, place yourself in the Greenhouse Core directory and run the following command:
```
.\gradlew dockerUp -Porganization=<ORGANIZATION-NAME-HERE> -Pgreenhouse=<GREENHOUSE-NAME-HERE> -Penvironment=<ENVIRONMENT-NAME-HERE> -Ppassword=<ENVIRONMENT-PASSWORD-HERE>
``` 
Using _-P_ (_yes, without a white space after_) you'll need to provide four parameters:
- __organization__: the name of your organization, previously registered using the client
- __greenhouse__: the name of the greenhouse, previously created using the client, that contains the environment that Greenhouse Core will coordinate
- __environment__: the name of the environment, previously created using the client, that Greenhouse Core will coordinate
- __password__: the password of the environment, previously created using the client, that Greenhouse Core will coordinate

### __Step 4__: Run Edge (linux only, Windows and MacOS [here](#step-4-run-edge-all-operative-systems))
Once you have connected an ESP8266 to your machine, place yourself in the Edge directory and run the following command to flash Edge on the chip:
```
.\gradlew dockerUp -PpathToESP8266=<PATH-TO-ESP8266> -Pssid=<WIFI-SSID-HERE> -Ppassword=<WIFI-PASSWORD-HERE>
```
This command will compile an image from the Dockerfile of the project and execute a container running Edge for the flashing process.  
You'll need to provide the following parameters:
- __pathToESP8266__: path to the USB port where ESP8266 is connected (es: /dev/ttyUSB0)
- __ssid__: SSID of the Wifi to which the ESP8266 will connect to
- __password__: password of the Wifi to which the ESP8266 will connect to

### __Step 5__: Shut down Brittany
From the root directory of the project run the following command to stop the execution of the Services, the Web Client and Greenhouse Core:
```
.\gradlew dockerDown
```

## __Method 4__: Run everything locally without Docker
This final method will run everything locally without using Docker; this resut in having to install a lot of software to run each sub-project.

### __Step 0__: Required software
- [Gradle](https://gradle.org/install/)
- [Java 11](https://www.oracle.com/java/technologies/javase/jdk11-archive-downloads.html)
- [JaCaMo](http://jacamo.sourceforge.net/doc/install.html)
- [NodeJs and Npm](https://nodejs.org/it/download/)
- [MongoDB](https://www.mongodb.com/docs/guides/server/install/)
- [PlatformIO](https://platformio.org/)

### __Step 1__: Run Services
Make sure MongoDB is running on your machine and then place yourself on each of the Services folders (in no particolar order) and run the following command:
```
.\gradlew run
```
This will trigger the resolution of dependencies by Npm, followed by compilation and subsequent execution.
### __Step 2__: Run Web Client
Similarly to the previous step, place yourself in the Web Client directory and run the same command as before to start the Web Client:
```
.\gradlew run
```

### __Step 3__: Run Greenhouse Core
After having setup the environment using the Web Client, place yourself in the Greenhouse Core directory and run the following command to launch a JVM running the program:
```
.\gradlew run -Porganization=<ORGANIZATION-NAME-HERE> -Pgreenhouse=<GREENHOUSE-NAME-HERE> -Penvironment=<ENVIRONMENT-NAME-HERE> -Ppassword=<ENVIRONMENT-PASSWORD-HERE>
```
You'll need to provide four parameters:
- __organization__: the name of your organization, previously registered using the client
- __greenhouse__: the name of the greenhouse, previously created using the client, that contains the environment that Greenhouse Core will coordinate
- __environment__: the name of the environment, previously created using the client, that Greenhouse Core will coordinate
- __password__: the password of the environment, previously created using the client, that Greenhouse Core will coordinate

### __Step 4__: Run Edge (all operative systems)
Once you have connected an ESP8266 to your machine, place yourself in the Edge directory and run the following command to flash Edge on the chip:
```
.\gradlew upload -Pssid=<WIFI-SSID-HERE> -Ppswd=<WIFI-PASSWORD-HERE>
```
You'll need to provide the following parameters:
- __ssid__: SSID of the Wifi to which the ESP8266 will connect to
- __pswd__: password of the Wifi to which the ESP8266 will connect to

The task will print a list of possible environment. It is required to specify the one to upload by specifying the corresponding number.
The task will then proceed to build the code and upload it to the ESP8266.

# Local testing
To execute tests locally you will need on the running machine all the software listed at step 0 in [Method 4](#method-4-run-everything-locally-without-docker).  

You can launch this command from the directory of a project (to test only that project) or run the same command from the root directory to test sequentially all the systems.
```
.\gradlew test
```

Since the tests of a particular system is not influenced from the other systems, you can also place yourself on the root directory and launch the same command with the flag _--parallel_ to test all the systems in parallel.
```
.\gradlew test --parallel
```

# Continuous integration
Using the GitHub actions, the codebase gets tested each time a commit is pushed to this repository.  

The tests are triggered depending on the branch where the push was executed; for example, pushing on the branch auth-service will trigger the tests only for the Auth Service system. This is not the case when pushing to the branches develop and master, that will trigger the tests for all the systems at once.  

The actual tests that will be executed are the same that can be performed locally, but the GitHub actions allow to increase the testing power running tests on different setups; for example, each service runs all its tests using a bidimensional matrix for testing on different versions of NodeJs and MongoDB.

# Deployment
Each time a test completed successfully in the GitHub actions a deploy task is triggered, creating a Docker image that gets pushed to Docker Hub at the [alessandrotalmi](https://hub.docker.com/u/alessandrotalmi) profile.  

Two types of images gets deployed:
- dev image, created after the completion of tests in each branch of every system or in develop
- production image, created only on push to the branch master

Only Greenhouse Core and Edge have a production image that gets deployed at [alessandrotalmi](https://hub.docker.com/u/alessandrotalmi); on a push to master each Service and the Web Client, instead, gets deployed directly to the Heroku hosting service.  

The difference in the way the various systems gets deployed is dependent on the fact that Services and Web Client are ment to run on remote servers, while Greenhouse Core and Edge are ment to run on a user machine and an ESP8266 respectively.

# License

This project's source code is licensed under the Apache License Version 2.0.  

[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2FTale152%2Fbrittany.svg?type=large)](https://app.fossa.com/projects/git%2Bgithub.com%2FTale152%2Fbrittany?ref=badge_large)