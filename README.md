# Brittany
[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2FTale152%2Fbrittany.svg?type=shield)](https://app.fossa.com/projects/git%2Bgithub.com%2FTale152%2Fbrittany?ref=badge_shield)

TODO intro

# How to launch the project
From simplest to more complex

## Method 1: Use deployed servers and client
TODO setup account, greenhouse, environment and settings then
```
docker run -e ORGANIZATION_NAME=<ORGANIZATION-NAME-HERE> -e GREENHOUSE_NAME=<GREENHOUSE-NAME-HERE> -e ENVIRONMENT_NAME=<ENVIRONMENT-NAME-HERE> -e ENVIRONMENT_PASSWORD=<ENVIRONMENT-PASSWORD-HERE> --rm --name greenhouse-core alessandrotalmi/brittany-greenhouse-core-dev:latest
```

## Method 2: Run everything locally using images from Docker Hub

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

## Method 3: Run everything locally compiling Docker images
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

## Method 4: Run everything locally without Docker
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

[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2FTale152%2Fbrittany.svg?type=large)](https://app.fossa.com/projects/git%2Bgithub.com%2FTale152%2Fbrittany?ref=badge_large)