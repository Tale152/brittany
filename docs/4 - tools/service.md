---
title: Services
has_children: false
parent: Strumenti utilizzati
---

# Strumenti utilizzati - Services

In questo capitolo verranno descritti tutti gli strumenti e le tecnologie utilizzate per la costruzione dei services:
- Auth service
- Persistence Service
- Settings Service

## [Auth - Persistence - Settings] Services
### Node Packet Manager
Node.js è una runtime di JavaScript multipiattaforma per l’esecuzione di codice JavaScript, costruita
sul motore JavaScript V8 di Google Chrome.
Node.js dispone di una grande quantità di moduli scritti completamente in Javascript. Essendo il progetto
open source è inoltre possibile per gli sviluppatori aggiungere i propri moduli in modo da renderli disponibili pubblicamente.
Il gestore di pacchetti predefinito per l’ambiente di runtime JavaScript Node.js si chiama Node Package
Manager (npm). npm può essere richiamato tramite linea di comando usando la seguente sintassi:
```shell
npm <command> [args]
```
Il comando base per ottenere un pacchetto è:
```shell
npm install [packet_name]
```
Tutte le dipendenze e i conflitti vengono gestiti automaticamente.  

<div align="center">
<img src="https://upload.wikimedia.org/wikipedia/commons/d/db/Npm-logo.svg" width="150px" height="150px" alt="npm Logo">
<p align="center">Logo di npm</p>
</div>

### Node.js 
Come runtime JavaScript guidato da eventi asincroni, Node.js è progettato per creare applicazioni di rete scalabili; molte connessioni, difatti, possono essere gestite contemporaneamente.
Ad ogni connessione verrà invocata una callback, rendendo Node attivo solo al momento necessario.
Nonostante in questo progetto Node sia stato utilizzato per sviluppare dei server, è importante sottolineare che Node.js non è un web server, ma una piattaforma in grado di eseguire codice javascript lato server e, tramite apposite librerie, sviluppare per l’appunto un web server.

Node.js implementa un’architettura event-driven, facendo dunque affidamento su un event loop. Non
esiste alcuna chiamata per avviare il ciclo:
Node.js entra semplicemente nel ciclo degli eventi dopo aver eseguito lo script di input e, analogamente, esce dal ciclo di eventi quando non ci sono più callback da eseguire.  
Questo comportamento è simile a JavaScript in browser: il ciclo degli eventi è nascosto all’utente.  
Per natura dell’event loop, Node è single-threaded, ma è possibile, su neccessità, effettuare delle fork per sfruttare al meglio i core offerti dalla macchina creando nuovi thread.

<div align="center">
<img src="https://upload.wikimedia.org/wikipedia/commons/7/7e/Node.js_logo_2015.svg" width="300px" height="80px" alt="Node.js logo">
<p align="center">Logo di Node.js</p>
</div>
