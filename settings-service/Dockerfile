FROM node:alpine
COPY package.json .
COPY package-lock.json .
RUN	npm ci --silent
COPY . .
CMD node index.js
