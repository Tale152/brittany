FROM gradle:6.9.2-jdk11
WORKDIR /app
COPY . /app
USER root
RUN chown -R gradle /app
USER gradle
RUN echo 'handlers= java.util.logging.ConsoleHandler' >logging.properties
RUN gradle uberJar --stacktrace

FROM alessandrotalmi/jacamo-java-11:latest
WORKDIR /app
COPY --from=0 /app/build/libs /app
EXPOSE 1-65535
ENV AUTH_SERVICE_URL=http://localhost:81/agent/login
ENV PERSISTENCE_SERVICE_URL=http://localhost:80/
ENV SETTINGS_SERVICE_URL=http://localhost:82/settings/latest
CMD ["java", "-jar", "jacamo-greenhouse_core-1.0.jar"]
