---
title: Strumenti Comuni
has_children: false
parent: Strumenti utilizzati
nav_order: 1
---

# Strumenti utilizzati - Strumenti Comuni

### Gradle

Gradle è un Tool per il Building di applicativi che permette di scaricare dipendenze, compilare e testare il codice con uno sforzo minimo.

L’interfaccia da riga di comando è uno dei metodi principali per interagire con Gradle. L’utilizzo del Gradle Wrapper è fortemente incoraggiato. Sarebbe opportuno sempre sostituire ./gradlew o gradlew.bat con gradle qualora si usasse un wrapper.

L’esecuzione di Gradle da riga di comando è conforme alla seguente struttura. Le opzioni sono consentite prima e dopo i nomi delle attività.
```shell
$ gradle [taskName...] [--option-name...]
```
È possibile inizializzare una gradle build attraverso il seguente comando:
```shell
$ gradle init
```
Le dipendenze potranno poi essere aggiunte nel file generato build.gradle.

Gradle è stato utilizzato per la suddivisione del progetto in sottoprogetti e per semplificare le procedure di deploy e test.

Eseguendo il seguente comando dalla radice del progetto vengono per esempio eseguiti tutti i test di tutti i sottoprogetti, previa corretta configurazione dei build.gradle:
```shell
$ gradle test
```
Gradle offre la possibilità di creare task personalizzati.

<div align="center">
<img src="https://upload.wikimedia.org/wikipedia/commons/c/cb/Gradle_logo.png" width="300px" height="100px" alt="Gradle Logo">
<p align="center">Logo di Gradle</p>
</div>

### Docker

Docker è un sistema open-source tramite il quale è possibile automatizzare, tra le altre cose, il processo di deployment di applicazioni all’interno di contenitori software, denominati container; in questi container vengono eseguite delle immagini Docker, che contengono il software da eseguire all'interno del container.  

Utilizzando i container dunque le risorse possono essere isolate, i servizi limitati e i processi avviati in modo da avere una prospettiva completamente privata del sistema operativo, col loro proprio identificativo, file system e interfaccia di rete. Più container condividono lo stesso kernel, ma ciascuno di essi può essere
costretto a utilizzare una certa quantità di risorse, come la CPU, la memoria e l’I/O.

Al fine di creare un'immagine Docker sarà necessario specificare un Dockerfile per ogni servizio erogato.  
Similmente ai gitignore per il versioning git, è possibile definire dei file .dockerignore per segnalare a docker quali file ignorare durante la copia dei file all’interno dell'immagine.
```dockerfile
FROM node:alpine
COPY package.json .
COPY package-lock.json .
RUN	npm install --silent
COPY . .
CMD node index.js
```
Come si può vedere in questo esempio, la sintassi è molto semplice: nella prima riga troviamo la dichiarazione dell'immagine di partenza che intendiamo "estendere" (in questo caso utilizziamo un'immagine che monta una distro Linux Alpine con al suo interno preinstallato Node). Le immagini sono reperibili attraverso Docker Hub, dove organizzazioni e singoli developer possono pubblicare le proprie immagini compilate.  

Attraverso il comando COPY possiamo copiare dei sorgenti all'interno della nostra immagine, specificando (in ordine):
- il percorso di partenza (relativo alla posizione del Dockerfile) nel file system dove l'immagine viene compilata;
- la destinazione all'interno dell'immagine compilata.

A seguire troviamo un esempio di utilizzo del comando RUN, che specifica istruzioni da eseguire durante la compilazione dell'immagine.  

L'ordine delle istruzioni, nella costruzione di immagini Docker, è rilevante se si vogliono sfruttare al meglio le potenzialità di caching durante la compilazione.  
In questo caso, ad esempio, all'interno di un progetto Node vi sono i due file di package che specificano le dipendenze software da installare; generalmente durante il development le dipendenze cambiano meno frequentemente rispetto al codice specifico del progetto. Specificando i comandi in questo ordine i comandi fino a "NPM install --silent" dovranno essere eseguiti una sola volta durante la compilazione (a meno di una variazione nei file delle dipendenze), permettendo di risparmiare tempo passando direttamente alla copia dei sorgenti del progetto ("COPY . .", assumendo la presenza di un .dockerignore che specifichi cosa escludere).  

In ultimo troviamo il comando CMD, che specifica l'istruzione da eseguire quando l'immagine verrà eseguita all'interno di un container Docker (in questo caso avviare l'applicativo). Vi può essere un solo CMD per Dockerfile e deve essere necessariamente posto come ultimo comando all'interno di un Dockerfile.  

In caso di esigenze particolari, è possibile creare dei Dockerfile che specifichino delle multistage build, dove vengono specificate delle istruzioni per creare un'immagine che verrà utilizzata dalle istruzioni successive per creare una nuova immagine, continuando iterativamente per i vari stage secondo le necessità del caso.
```dockerfile
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
CMD ["java", "-jar", "jacamo-greenhouse_core-1.0.jar"]
``` 

Specialmente durante il development locale, accade frequentement di dover lanciare più immagini Docker allo stesso tempo. Docker semplifica questo processo attraverso la specifica di un file docker-compose, che evita all'utente il tedioso processo di lanciare manualmente le varie immagini una alla volta.  
All'interno del docker-compose inoltre, si possono specificare gli stessi parametri aggiuntivi che è possibile fornire al lancio di un'immagine.

```yml
services:
  auth:
    build:
      context: .
      dockerfile: Dockerfile
    environment:
      - DB=mongodb://database:27017/brittany_auth
      - PORT=80
      - FARMER_TOKEN_SECRET=devFarmerTokenSecret
      - AGENT_TOKEN_SECRET=devAgentTokenSecret
    ports:
      - 81:80
    image: auth
  database:
    image: mongo
    volumes:
      - database_data:/data/db

volumes:
  database_data:
```
In questo esempio viene specificata l'esecuzione dell'immagine definita dal Dockerfile visto in precedenza, oltre che l'esecuzione di un'immagine (ricavata direttamente da Docker Hub) volta a fornire i servizi di MongoDB (specificando inoltre un volume per mantenere la persistenza dei dati anche dopo la fine dell'esecuzione del container).

<div align="center">
<img src="https://upload.wikimedia.org/wikipedia/commons/4/4e/Docker_%28container_engine%29_logo.svg" width="400px" height="100px" alt="Docker Logo">
<p align="center">Logo di Docker</p>
</div>