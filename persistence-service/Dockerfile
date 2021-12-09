FROM node:alpine
COPY package.json .
COPY package-lock.json .
RUN	npm install --silent
COPY . .
CMD node index.js
