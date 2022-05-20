---
title: Architettura Services Workspace
parent: Greenhouse Core
grand_parent: Design
nav_order: 5
---

# Services Workspace
__Service Workspace__ racchiude gli artefatti necessari per comunicare con in __Services__; nello specifico sono stati creati tre differenti artefatti, ognuno dei quali si dedica alla comunicazione con un diverso servizio:  
- AuthenticationArtifact
- SettingsArtifact
- PersistenceArtifact

L'__URL__ per la comunicazione con i servizi è disponibile in delle variabile d'ambiente. In questo modo, nel caso in cui sia necessario cambiare l'indirizzo che permette di contattare i servizi, questo non deve essere fatto a livello di codice, mantenendo quindi un certo livello di generalità.  

## AuthenticationArtifact
L'__AuthenticationArtifact__ è l'artefatto utilizzato per la comunicazione con l'__Auth Service__.  
L'unica operazione esposta è denominata __retrieveAuthenticationData__, che si occupa di ottenere i dati necessari per autenticarsi e ricevere un _token_, che permetterà di comunicare con successo con gli altri servizi.

## SettingsArtifact
__SettingsArtifact__ si occupa di fornire operazioni che coinvolgono la comunicazione con il __Settings Service__. Nello specifico, l'operazione esposta prende il nome di __getSettings__: questa crea una richiesta HTTP da mandare al __Settings Service__ con lo scopo di recuperare le configurazioni attualmente valide create dall'utente. Questa richiesta va a buon fine solo nel caso in cui sia stato precendentemente recuperato il _token_, necessario perché il sistama venga riconosciuto dal servizio contattato.  

Questo artefatto si occupa della creazione dei due tipi di configurazioni citate in precedenza, che vanno a distiguere le configurazioni che prevendono un valore minimo e massimo stabilito e le configurazioni che devono essere applicate in un certo intervallo di tempo.

## PersistenceArtifact
