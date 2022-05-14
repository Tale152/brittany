---
title: Testing
parent: Web Client
grand_parent: Design
nav_order: 3
---

# Testing

## Modalità di Testing
Il testing in ambiente React si è rivelato relativamente semplice seppur non siano però mancate delle piccole difficoltà derivate semplicemente dalla natura dei test.  

L'obiettivo principale nel testing nel Web Client è verificare il corretto funzionamento della UI simulando l'interazione di un utente reale.  

Le piccole difficoltà riscontrate derivano per l'appunto dalla natura dei test in quanto per i componenti del team si è trattato della prima esperienza nel campo del testing delle UI.

### Test Automatizzati
Come anticipato nella sezione _Strumenti Utilizzati_, i test automatizzati sono stati realizzati utilizzando il framework _React Testing Library_; quest'ultimo simula le interazioni dei un utente reale, interagendo con il DOM.  

Come per gli altri sistemi, ogni qual volta venga effettuato il push del client nel versioning GitHub, viene scatenato il trigger per l'esecuzione dei test (che possono essere eseguiti anche in locale dal developer).

Per assicurare un testing il più esaustivo possibile, i test del Web Client vengono eseguiti su GitHub utilizzando tre versioni di Node (12, 14 e 16).

### Testing non automatizzato
Trattandosi di un client dotato di UI, durante il development sono stati svolti test di utilizzo frequenti (interagendo con i Services).