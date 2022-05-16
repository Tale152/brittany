# Brittany
TODO intro

# How to launch the project
Here will be listed all ways to launch the project, starting from the simplest way up to more complex ones.  

All the methodologies require the following __hardware__:
- A machine to run Greenhouse Core on (and possibly the Services, depending on the chosen methodology)
- One or more ESP8266 for running Edge

The machine running Greenhouse Core and the ESP8266 __must__ be connected on the same LAN.

## &#9658; __Method 1__: Use deployed servers and client
This method will use the services and the [client](https://brittany-web-client.herokuapp.com/) already deployed online, freeing you from the necessity of also running them locally.

### __Step 0__: Software required
- [Docker](https://docs.docker.com/get-docker/)

Windows and MacOS users will also require [PlatformIO](https://platformio.org/) to be able to run Edge since, at the time of writing, Docker can't access USB ports on those operative systems.  
See _Run Edge_ on Method 3 to read instruction on how to do that.

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

### __Step 2__: Run Edge
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

## &#9658; __Method 2__: Run everything locally using images from Docker Hub

### First run
TODO in respective folder
```
.\gradlew authDevUp
.\gradlew settingsDevUp
.\gradlew settingsDevUp
.\gradlew clientDevUp
```
Or
```
.\gradlew webUp
```
TODO then setup account, greenhouse, environment and settings
```
.\gradlew coreDevUp -Porganization=<ORGANIZATION-NAME-HERE> -Pgreenhouse=<GREENHOUSE-NAME-HERE> -Penvironment=<ENVIRONMENT-NAME-HERE> -Ppassword=<ENVIRONMENT-PASSWORD-HERE>
```
TODO stuff works yee

### Second run and onward

```
.\gradlew systemUp -Porganization=<ORGANIZATION-NAME-HERE> -Pgreenhouse=<GREENHOUSE-NAME-HERE> -Penvironment=<ENVIRONMENT-NAME-HERE> -Ppassword=<ENVIRONMENT-PASSWORD-HERE>
```

### Shut down
```
.\gradlew systemDown
```

### Log
```
.\gradlew authDevLog
.\gradlew settingsDevLog
.\gradlew persistenceDevLog
.\gradlew coreDevLog
.\gradlew clientDevLog
```

## &#9658; __Method 3__: Run everything locally compiling Docker images
TODO go in each folder, first services, then client
```
.\gradlew dockerUp
```
TODO then set settings and launch core
```
.\gradlew dockerUp -Porganization=<ORGANIZATION-NAME-HERE> -Pgreenhouse=<GREENHOUSE-NAME-HERE> -Penvironment=<ENVIRONMENT-NAME-HERE> -Ppassword=<ENVIRONMENT-PASSWORD-HERE>
```
### Log

```
.\gradlew dockerLog
```

## &#9658; __Method 4__: Run everything locally without Docker
TODO in services and client 
```
.\gradlew run
```
TODO then in core folder
```
.\gradlew run -Porganization=<ORGANIZATION-NAME-HERE> -Pgreenhouse=<GREENHOUSE-NAME-HERE> -Penvironment=<ENVIRONMENT-NAME-HERE> -Ppassword=<ENVIRONMENT-PASSWORD-HERE>
```

# Testing
TODO
```
.\gradlew test --parallel
```

# Continuous integration
TODO

# Deployment
TODO

# Required tools for running the project
## Method 1
## Method 2 and 3
## Method 4 and testing

# Licence
TODO