---
title: Web Client
parent: Design
has_children: true
---

# Web Client

Pensato per l'utilizzo da parte degli Agricoltori, il Web Client permette la gestione di Serre e Ambienti, consentendo di visionare i dati campionati oltre che di regolare le impostazioni dei singoli Ambienti.  

Lo stack tecnologico utilizzato comprende __React__ come framework base con il supporto di __Redux__ per la gestione degli stati interni e __React-Bootstrap__ per lo stile dei componenti; npm è stato scelto come gestore delle dipendenze.

Nel testing si è preferito affidarsi alla libreria standard di test in ambiente React: __React Testing Library__; attraverso questo tool, sono state simulate in modo automatizzato le interazioni dell'utente con la GUI.

Ad ogni push sul branch master, viene creata un’immagine Docker attraverso le Github Actions (previa aver superato tutti i test all’interno della stessa action); a seguito della creazione dell'immagine dunque viene effettuato il deploy sul servizio di hoisting Heroku. L'istanza online del Web Client detiene i riferimenti agli indirizzi dei Services, di modo che possa interagirvi attraverso richieste HTTP.
