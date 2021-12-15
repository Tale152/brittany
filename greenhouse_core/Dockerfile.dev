FROM gradle:6.8.0-jdk8
WORKDIR /app
COPY . /app
USER root
RUN chown -R gradle /app
USER gradle
RUN echo 'handlers= java.util.logging.ConsoleHandler' >logging.properties
RUN gradle uberJar --stacktrace

FROM jomifred/jacamo:1.0
WORKDIR /app
COPY --from=0 /app/build/libs /app
CMD ["java", "-jar", "jacamo-overviewJaCaMo-1.0.jar"]
