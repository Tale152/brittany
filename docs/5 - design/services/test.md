---
title: Testing
parent: Services
grand_parent: Design
nav_order: 6
---

# Testing

## Modalità di Testing
Il testing in ambiente Node si è rivelato relativamente semplice in quanto, essendo un ambiente molto utilizzato, dispone di molto supporto sia a livello di tool da utilizzare che a livello di documentazione.  

L'obiettivo principale nel testing dei Services è verificare il corretto funzionamento delle API offerte da quest'ultimi.

### Test Automatizzati
Come anticipato nella sezione _Strumenti Utilizzati_, i test automatizzati sono stati realizzati utilizzando una combinazione dei framework Jest (per fare assertions sui risultati) e Supertest (per creare un Client fittizio che esegua richieste HTTP).  

Ogni qual volta venga effettuato il push di un servizio nel versioning GitHub, viene scatenato il trigger per l'esecuzione dei test. Questi test possono (e devono) essere eseguiti anche in locale prima di un push, ma al fine di preservare le best practices DevOps è stato fondamentale implementare un sistema automatizzato per il testing.  

Per assicurare un testing il più esaustivo possibile, i test di ogni Service vengono eseguiti su GitHub utilizzando tutte le combinazioni di due vettori; il primo vettore contiene tre versioni di Node (12, 14 e 16), mentre il secondo contiene tre versioni di MongoDB (3.6, 4.0 e 4.2).

### Testing non automatizzato

Occasionalmente durante il development ci si è affidati al tool Postman per verificare il corretto funzionamento delle API, oltre che prove dirette di interazione con Web Client e Greenhouse Core.

## Coverage
TODO