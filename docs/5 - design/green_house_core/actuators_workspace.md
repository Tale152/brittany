---
title: Architettura Actuator Workspace
parent: Greenhouse Core
grand_parent: Design
nav_order: 4
---

# Actuator Workspace
Il workspace chiamato __Actuator Workspace__ racchiude gli artefatti che vengono utilizzati dagli agenti per azionare gli attuatori fisici presenti nella serra.  

Gli artefatti esposti dal'Actuator workspace sono i seguenti:
- SampleBasedActuatorArtifact
- TimeBasedActuatorArtifact

La ragione per la quale sono presenti due artefatti separati per la gestione degli attuatori è dovuta al fatto che sono due le possibili occorrenze che causano la necessità di azionare un attuatore: la prima è nel caso in cui i dati campionati non rientrino tra il valore minimo e massimo impostati, e la seconda è nel caso in cui un determinato attuatore debba essere azionato in una fascia oraria specifica.  
Ora questi due artefatti verrano descritti nel dettaglio.

## SampleBasedActuatorArtifact
Come anticipato in precedenza, un utente può impostare delle configurazioni che vanno a regolare lo stato desiderato per una specifica categoria, che vada ad influenzare la pianta o l'ambiente in cui essa si trova.  

Un tipo di configurazione che l'utente può creare va a stabilire per una determinata categoria il valore minimo e il valore massimo accettabile.  
Quando vengono estratti i dati campionati e ne viene calcolata la media, quest'ultima viene confrontata con la configurazione relativa; nel caso in cui qualcosa non vada, allora viene scatenato un plan per attivare un attuatore al fine di risolvere lo stato non previsto.  

All'interno di questo artefatto, l'operazione fondamentale è __actuate__. Le altre operazioni presenti servono all'unico scopo di impostare i componenti e i Thing Descriptor.  
L'operazione __actuate__ riceve sia il dato campionato che esce dall'intervallo previsto, sia la configurazione che è stato stabilito che non rispetta. La configurazione viene passata come argomento per evitare incongruenze nel caso in cui le configurazioni siano appena state aggiornate.  
All'interno di questa operazione, in base alla categoria del dato campionato ricevuto, viene controllato se il valore è troppo alto o troppo basso: da questo dipende che tipo di azione dovrà essere richiesta agli attuatori. Una volta stabilito quali attuatori dovranno essere spenti e quali accesi per rientrare in uno stato accettabile, vengono usati i Thing Descriptor per richiamare tali azioni tramite __Edge__.

## TimeBasedActuatorArtifact
__TimeBasedActuatorArtifact__ è un artefatto utilizzato nel caso in cui esistano delle configurazioni che prevedano l'azione degli attuatori per certi intervalli di tempo.  
Questo artefatto viene utilizzato periodicamente per controllare se è richiesto o meno un cambio di stato per gli attuatori.  
Oltre alle operazioni per salvare i componenti, le configurazioni e i Thing Descriptor, l'altra operazione presente è chiamata __checkSettings__. Data un certa categoria, viene controllato da questa operazione se esiste una configurazione basata sull'orario relativo: nel caso esista, viene acceso o spento l'attuatore della categoria, a seconda delle configurazioni e dell'orario attuale. Come nell'artefatto precendente, l'azione viene chiamata grazie alla cominicazione con __Edge__ e l'utilizzo dei Thing Descriptor.  