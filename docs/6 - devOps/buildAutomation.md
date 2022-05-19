---
title: Build Automation
parent: Documentazione DevOps
has_children: false
---

# Build Automation

## Gradle

Una volta definiti i bounded context, si è proseguito andando a definire l’architettura di progetto.
È stata predisposta la repository di base ed è stata chiamata ```brittany```.  
Per strutturare il progetto è stato utilizzato il build tool Gradle.
Gradle è stato pensato per funzionare principalmente su linguaggi Java like, ma anche altri linguaggi sono supportati.

### Struttura multi progetto
Si è predisposta una struttura multi progetto il più possibile aderente all’analisi DDD effettuata. Sono stati definiti i seguenti sottoprogetti:

- __greenhouse_core__: si tratta del sottoprogetto più core. È la parte del sistema che si occupa di orchestrare i vari edge e inoltrare le informazioni ottenute ai service;
- __edge__: il sottoprogetto che agisce su sensori ed attuatori all'interno della serra. Il sottoprogetto contiene più configurazioni ed è possibile personalizzare ogni edge in base alle proprie esigenze.
- __auth-service__: il servizio che si occupa di far registare ed autenticare gli utenti al sistema.
- __persistence-service__: il servizio che si occupa dell'immagazzinamento dei dati che vengono inoltrati da greenhouse-core.
- __settings-service__: il servizio che si occupa della gestione delle configurazioni delle serre.
- __web-client__: l'applicazione front-end che permette all'utente di interagire col sistema.

### Task personalizzati

Per ogni sottoprogetto sono stati creati dei task personalizzati e sono stati inseriti all'interno dei relativi file ```build.gradle.kts```.

In particolare per ogni sottoprogetto è stato creato un task di test denominato appunto _test_.  
In questo modo a partire dalla root del progetto è possibile per esempio lanciare il comando:
```shell
$ gradle test --parallel
```
In questo modo tutti i task di test dei sottoprogetti verranno lanciati in parallelo, permettendo di effettuare un test dell'intero sistema molto velocemente.

Per avere una visione completa riguardo i task rilevanti all'interno del progetto è possibile leggere la sezione [__How to launch the project__](https://github.com/Tale152/brittany#how-to-launch-the-project) disponibile all'interno del README del repository.
