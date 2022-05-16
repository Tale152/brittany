---
title: Architettura Brittany Workspace
parent: Architettura Environment
grand_parent: Design
nav_order: 1
---

# Brittany Workspace
Il workspace __Brittany__ può essere definito come il workspace di default del progetto JaCaMo.  
Questo workspace contiente gli artefatti che non rientrano negli altri Workspace che verranno introdotti in seguito, constituendo quindi un ambiente tramite cui accedere ad artefatti di uso generale.

Gli artefatti esposti dal Brittany workspace sono i seguenti:
- CommonArtifact
- SamplingCoordinatorArtifact
- SamplingArtifact
- DiscoverComponentsArtifact

## CommonArtifact
Il CommonArtifact è un Artefatto che viene osservato da tutti gli agenti e svolge il compito di punto di riferimento per la condivisione di informazioni comuni.  

Questo artefatto espone tre operazioni, le quali sono identificate dal tag __@OPERATION__:
- __shareComponents__  
  Questa operazione viene chiamata dal _discoverComponentsAgent_, il quale reperisce i componenti connessi agli Edge per mezzo dell'analisi dei dati ricevuti. La seguente operazione permette di convidere con tutti gli agenti che hanno accesso a questo artefatto la lista dei componenti. Questo viene aggiornando una proprietà osservabile denominata __setupComponents__.
- __shareSettings__  
  L'operazione shareSettings, analogamente all'operazione precedente, viene utilizzata al fine di condividere a tutti gli agenti interessati le configurazioni attuali. Questa operazione viene chiamata dal _setupAgent_, il quale, tramite la comunicazione con il _Settings Service_, è in grado appunto di reperire la configurazione attualmente valida. Quest'ultima viene resa osservabile tramite la proprietà __setupSettings__.
- __shareThingDescriptors__  
  Infine, l'ultima operazione, similmente alle precedenti, serve per la condivisione di Thing Descriptor trovati, per mezzo della proprietà __setupThingDescriptors__. Questa operazione viene chiamata dal _discoverComponentsAgent_, che riceve da Edge il Thing Descriptor.  

In base alle esigenze specifiche, ogni agente ha dei __plan__ denominati con gli stessi nomi delle proprietà osservabili; in questo modo, quando tali proprietà vengono modificate, il piano dell'agente viene azionato, dando inizio a una serie di specifiche operazioni.

## SamplingCoordinatorArtifact
Il SamplingCoordinatorArtifact viene utilizzato per fornire un supporto per la coordinazione delle operazioni di campionamento e per decidere se rendere i dati campionati persistente e/o se attivare o disattivare un attuatore.  

Questo artefatto, oltre alle operazioni utilizzate per salvare la lista di componenti e le configurazioni attuali, rende disponibili le seguenti operazioni:
- __sampleOperation__  
  Quando chiamata, questa operazione filtra i componenti fisici trovati in base a una specifica categoria e rende disponibile una proprietà osservabile __sampling__ che aziona l'agente dedicato al campionamento.
- __updateOperation__
  La seguente operazione viene utilizzata per analizzare i dati appena campionati; una volta calcolata la media, questa viene confrontata con la media dell'ultimo campionamento effettuato e nel caso in cui la differenza superi un certo delta prestabilito, allora viene condivisa la proprietà osservabile __uploadPersisence__, il cui obiettivo è quello di condividere la media del campionamento corrente all'agente che si occupeà di renderla persistente.  
  UpdateOperation ha anche il compito di verificare che la media corrente rientri tra il valore minimo e massimo stabilito da una possibile configurazione attiva; nel caso in cui non sia così allora viene utilizzata la proprietà osservabile __actuate__, il cui compito è di scatenare l'azione che gestirà gli attuatori per fare rientrare lo stato della serra in quello prestabilito dalle configurazioni.

## SamplingArtifact
Il compito di SamplingArtifact è quello di esporre una operazione chiamata __getSamples__.  
Tale operazione riceve un lista di componenti e comunica con ognuno di essi utilizzando i Thing Descriptor. Ogni componente contattato restituirà lo stato registrato dal sensore e, una volta raccolti tutti, vengono condivisi all'agente che osserva la proprietà __checkSamples__.

## DiscoverComponentsArtifact
Il DiscoverComponentsArtifact è utilizzato per la gestione della ricerca di Edge, i quali devono restituire un Thing Descriptor valido.

L'operazione utilizzata per azionare la ricerca di Edge si chiama __discoverComponents__; questa sfrutta un meccanismo messo a disposizione dal framework Cartago, ovvero un __@INTERNAL_OPERATION__, che in questo caso si chiama __broadcastRequest__. Una _Internal Operation_ viene utilizzata quando si vuole eseguire un'operazione in modo asincrono, soprattutto nel caso in cui la sua esecuzione richieda molto tempo. BroadcastRequest ha lo scopo di ciclare su tutti gli indirizzi IP nella sottorete, al fine di trovare Edge, il che richiede molto tempo.  
Ogni volta che viene ricevuta una risposta valida da un certo indirizzo IP, il Thing Descriptor ricevuto viene analizzato per estrarre una lista di componenti. Successivamente vengono create due proprietà osservabili: __components__ (per condividere la lista dei componenti) e __thingDescriptors__ (per distribuire i Thing Descriptor).  
Una cosa particolare da notare è che al termine di ogni richiesta viene chiamata la seguente primitiva esposta da Cartago:
```
await_time(TICK_TIME);
```
Questa primitiva è necessaria per fermare momentaneamente l'esecuzione dell'operazione a lungo termine, per dare il tempo alle proprietà osservabili di essere effettivamente condivise. Trascorso il tempo specificato, l'operazione riprende ad eseguire.