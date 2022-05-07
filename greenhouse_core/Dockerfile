FROM gradle
COPY ./build/libs/jacamo-greenhouse_core-1.0.jar .
ENV AUTH_SERVICE_URL=http://localhost:81/agent/login
ENV PERSISTENCE_SERVICE_URL=http://localhost:80/
ENV SETTINGS_SERVICE_URL=http://localhost:82/settings/latest
CMD ["java", "-jar", "jacamo-greenhouse_core-1.0.jar"]
