---
title: Strumenti Comuni
has_children: false
parent: Strumenti utilizzati
nav_order: 1
---

# Strumenti utilizzati - Strumenti Comuni

### Gradle

Gradle è un Tool per il Building di applicativi che permette di scaricare dipendenze, compilare e testare il codice con uno sforzo minimo.

L’interfaccia da riga di comando è uno dei metodi principali per interagire con Gradle. L’utilizzo del Gradle Wrapper è fortemente incoraggiato. Sarebbe opportuno sempre sostituire ./gradlew
o gradlew.bat con gradle qualora si usasse un wrapper.

L’esecuzione di Gradle da riga di comando è conforme alla seguente struttura. Le opzioni sono
consentite prima e dopo i nomi delle attività.
```shell
$ gradle [taskName...] [--option-name...]
```
È possibile inizializzare una gradle build attraverso il seguente comando:
```shell
$ gradle init
```
Le dipendenze potranno poi essere aggiunte nel file generato build.gradle.

Gradle è stato utilizzato per la suddivisione del progetto in sottoprogetti eper semplificare le procedure di deploy e test.

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

Docker è un sistema open-source tramite il quale è possibile automatizzare, tra le altre cose, il processo di deployment di applicazioni all’interno di contenitori software.
Docker implementa API di alto livello per gestire container che eseguono processi in ambienti isolati.  

Utilizzando i container dunque le risorse possono essere isolate, i servizi limitati e i processi avviati in modo da avere una prospettiva completamente privata del sistema operativo, col loro proprio identificativo, file system e interfaccia di rete. Più container condividono lo stesso kernel, ma ciascuno di essi può essere
costretto a utilizzare una certa quantità di risorse, come la CPU, la memoria e l’I/O.

Al fine di creare un container Docker sarà necessario specificare un Dockerfile per ogni servizio erogato.
Similmente ai gitignore per il versioning git, è possibile definire dei dockerignore per segnalare a docker quali file ignorare durante la copia dei file all’interno del container.


<div align="center">
<img src="https://upload.wikimedia.org/wikipedia/commons/4/4e/Docker_%28container_engine%29_logo.svg" width="400px" height="100px" alt="Docker Logo">
<p align="center">Logo di Docker</p>
</div>
