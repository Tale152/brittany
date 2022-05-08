---
title: Services
parent: Design
has_children: true
---

# Services

All interno dell'ecosistema Brittany vi sono tre microservizi nel cloud che vengono contattati dal Web Client e da Greenhouse Core.  

I tre server HTTP sono seguono una filosofia REST, mantenendo indipendenza tra loro e, in particolar modo, operando in maniera stateless.  

In linea con la filosofia a microservizi, seppure i tre server siano altamente simili nella loro struttura, si è preferita la duplicazione di codice piuttosto che il riuso per non vincolare tra loro i progetti.  
Nonostante il riuso però, si è cercato quanto più possibile di mantenere uno standard tra i tre servizi, così che sia facile orientarsi all'interno degli stessi.

Come stack tecnologico si è scelto di sviluppare i server utilizzando __Node.js__, scegliendo npm come gestore delle dipendenze. Per la persistenza si è scelto di utilizzare __MongoDB__ in combinazione con __Mongoose__, di modo da ottenere un approccio facile e veloce alla struttura dei dati su DB.  

Nel testing è stata utilizzata una combinazione di due framework: __Jest__ (popolare ambiente di testing su JavaScript) e __SuperTest__ (per istanziare server e mock client che effettuassero richieste HTTP il quale risultato viene verificato a fini di testing).  

Per ogni push sul branch master, viene creata un'immagine __Docker__ per ognuno dei tre servizi attraverso le Github Actions (previa aver superato tutti i test all'interno delle stesse action); di queste immagini dunque viene automaticamente effettuato il deploy sul servizio di hoisting __Heroku__. Queste istanze online comunicano con delle istanze all'interno del servizio online __MongoDB Atlas__.

## Auth Service
Responsabile per l'autenticazione di Agricoltori all'interno del sistema tramite client.  

Questo servizio inoltre contiene i dati delle Serre (e relativi Ambienti) per ogni Azienda registrata nel sistema; la scelta di far risiedere qui questi ultimi dati è dovuta alla necessità di far autenticare non solo gli Agricoltori, ma anche gli Agenti (che operano all'interno di un determinato Ambiente).

## Settings Service
Questo gestizio gestisce la persistenza delle impostazioni relative ad uno specifico Ambiente all'interno di una data Serra.  

Attraverso il client web gli Agricoltori, precedentemente autenticati,possono controllare le impostazioni correnti, modificandole o creandone di nuove.  

Un Agente, tramite un token fornitogli nell'autenticazione, può richiedere le impostazioni correnti per il determinato Ambiente in cui opera; attraverso queste impostazioni, gli Agenti di Greenhouse Core adatteranno il loro comportamento per rispettare i vincoli imposti dagli Agricoltori.

## Persistence Service
Nell'ultimo dei tre microservizi è possibile reperire i dati campionati dai sensori in Edge e che, a discrezione degli Agenti in Greenhouse Core, sono stati resi persistenti.  

Esattamente come per Settings service, è necessario anche in questo caso autenticasi prima di poter interagire con questo sistema.  

Un Agente effettuerà richieste POST per caricare dati campionati mentre i client effettueranno delle GET per accedere a tali dati e mostrarli nella UI.
