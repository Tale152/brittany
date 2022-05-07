FROM gradle
COPY ./build/libs/jacamo-greenhouse_core-1.0.jar .
ENV AUTH_SERVICE_URL=https://brittany-auth-service.herokuapp.com:443/agent/login
ENV PERSISTENCE_SERVICE_URL=https://brittany-persistence-service.herokuapp.com:443/
ENV SETTINGS_SERVICE_URL=https://brittany-settings-service.herokuapp.com:443/latest
CMD ["java", "-jar", "jacamo-greenhouse_core-1.0.jar"]
