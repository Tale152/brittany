FROM node:13.12.0-alpine

COPY package.json .
COPY package-lock.json .

RUN npm install --silent

COPY . ./

CMD npm start
