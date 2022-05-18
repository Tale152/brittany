FROM shaguarger/platformio
RUN pio system prune -f
WORKDIR /app
COPY . ./
RUN chmod +x ./dockercmd.sh
CMD ["./dockercmd.sh"]
