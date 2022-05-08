FROM gradle
COPY ./build/libs/jacamo-greenhouse_core-1.0.jar .
ENV AUTH_SERVICE_URL=http://host.docker.internal:81/agent/login
ENV PERSISTENCE_SERVICE_URL=http://host.docker.internal:80/
ENV SETTINGS_SERVICE_URL=http://host.docker.internal:82/settings/latest
CMD ["java", "-jar", "jacamo-greenhouse_core-1.0.jar"]
