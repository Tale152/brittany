---
title: Requisiti Implementativi
parent: Requisiti
has_children: false
nav_order: 5
---

# Requisiti Implementativi

I requisiti di implementazione vincolano l’intera fase di realizzazione del sistema, ad esempio richiedendo l’uso di uno specifico linguaggio di programmazione e/o di uno specifico tool software.

Il sistema è diviso in sottoprogetti. Verranno brevemente illustrati i requisiti implementativi di ognuno e poi approfonditi successivamente:

## Componenti comuni
- __Build tool utilizzato__: [Gradle](https://gradle.org/)
- __Versioning tool__: [Git](https://git-scm.com/)
- __Versioning portal__: [GitHub](https://github.com/)
- __Containerization__: [Docker](https://www.docker.com/)

### Edge
- __Gestore di librerie esterne e configurazioni aggiuntive__: [PlatformIO](https://platformio.org/);
- __Linguaggio utilizzato__: C++17;
- __Hardware utilizzato__: ESP8266, Node MCU v1.0
- __Testing__: unity.h, integrata in PlatformIO;
- __Coverage__: [lcov](https://github.com/linux-test-project/lcov);
- __IDE utilizzato/utilizzabile__: Visual Studio Code, Clion;
- __Librerie__:
  - [jsoncpp](https://github.com/open-source-parsers/jsoncpp): utilizzata per la creazione, e manipolazione di contenuti in formato json;
  - [http-status-codes-cpp](https://github.com/j-ulrich/http-status-codes-cpp): utilizzata per semplificare la gestione dei codici HTTP.
  - [Adafruit Sensor](https://github.com/adafruit/Adafruit_Sensor): Libreria necessaria come dipendenza per la maggior parte delle librerie che utilizzano componenti hardware come sensori ed attuatori.
  - _Molte altre..._: Non elencate a causa della natura scalabile del progetto. Ogni componente fisico potrebbe aver bisogno di una libreria specifica per poter funzionare.

### Greenhouse Core

- __Linguaggio utilizzato__: Java 11, Jason, Cartago, Moise;
- __IDE utilizzato/utilizzabile__: Visual Studio Code, Eclipse;
- __Framework utilizzato__: [JaCaMo](http://jacamo.sourceforge.net/)
- __Librerie__:
  - [wot-servient](https://github.com/sane-city/wot-servient): L'implementazione dell'architettura W3C Web of Things (WoT) in Java.

### [Auth, Persistence, Settings] Service
- __Gestore di librerie esterne e configurazioni aggiuntive__: [npm](https://www.npmjs.com/);
- __Linguaggio utilizzato__: Javascript;
- __IDE utilizzato/utilizzabile__: Visual Studio Code, WebStorm;
- __Testing__: [supertest](https://www.npmjs.com/package/supertest)
- __Framework utilizzato__: [Express.js](https://expressjs.com/it/)
- __Librerie__:
  - [Mongoose](https://mongoosejs.com/): utilizzata per l'interazione con le basi di dati.

### Web Client
- __Gestore di librerie esterne e configurazioni aggiuntive__: [npm](https://www.npmjs.com/);
- __Linguaggio utilizzato__: Javascript;
- __Framework utilizzato__: [React.js](https://it.reactjs.org/)
- __IDE utilizzato/utilizzabile__: Visual Studio Code, WebStorm;
- __Librerie__:
  - [Bootstrap](https://getbootstrap.com/): utilizzata per semplificare la creazione dell'interfaccia utente.
  - [Redux](https://redux.js.org/): un contenitore di stato del sistema, utile per semplificare il processo più spinoso offerto da React.
