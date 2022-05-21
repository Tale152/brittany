---
title: Comunicazione tra Agenti
parent: Greenhouse Core
grand_parent: Design
nav_order: 7
---

# Sequenze di comunicazione degli agenti
Come detto precedentemente, la comunicazione degli agenti permette l'esecuzione di alcuni piani, che vanno a costituire l'effettivo funzionamento del sistema.  

Prima andare a spiegare nel dettaglio quali messaggi gli agenti si scambiano, è necessario fare una premessa: di seguito saranno presenti quattro diagrammi di sequenza, ognuno dei quali avrà lo scopo di mettere in evidenza solo i messaggi che ogni agente manda all'esterno. Questo è stato fatto per una questione di semplicità di tali diagrammi e anche perché il comportamento interno di ogni agente è già stato descritto in precedenza.  

All'interno dei diagrammi di sequenza proposti si metteno in evidenza anche le comunicazioni con i __Service__ e con __Edge__, andando a fornire un certo grado di completezza anche sotto questo punto di vista.

I diagrammi di seguito saranno divisi in base a delle fasi che verranno descritte per ogni capitolo, sempre per mantenere una certa semplicità nella comprensione.  

## Fase di inizializzazione
Rientrano in questa fase i comportamenti dei due agenti che si dedicano a recuperare periodicamente dati utili per l'intero sistema, ovvero __setupAgent__ e __discoverComponentsAgent__.  
Nonostante il loro comportamento sia ripetuto a intervalli regolari di tempo, verrà mostrato un'unica iterazione.  

Il primo diagramma di sequenza mostra i messaggi che vengono scambiati con il fine di condividere le configurazioni con tutti gli agenti che ne prevedono l'utilizzo.  
Il flusso viene iniziato da __setupAgent__, il quale manda una richiesta di autenticazione verso l'__Auth Service__; questo viene fatto al fine di ottenere un _token_ che permetta al sistema multi-agente di essere riconosciuto dai __Service__.  
Una volta ottenuto il _token_, __setupAgent__ invia un'altra richiesta HTTP, ma in questo caso indirizzata a __Settings Service__; il servizio, se la richiesta va a buon fine, restituisce l'ultima configurazione creata dall'utente ancora valida.  
Una volta che il __setupAgent__ crea le configurazioni riconosciute dal sistema da quelle ricevute dal __Settings Service__, manda un messaggio che viene ricevuto da tutti gli agenti interessati. Questo messaggio prende il nome di _setupSettings_ e viene recapitato a __samplingCoordinatorAgent__ e __timeBasedActuatorAgent__.  
A parte l'effettiva autenticazione, il recupero e la condivisione delle configurazioni viene ripetuta regolarmente, al fine di aggiornarle nel caso in cui vengano modificate e di propagare tale cambiamento.  

<div align="center">
<img src="https://images2.imgbox.com/58/d5/0xWU7d7Z_o.png" alt="Sequence diagram - settings setup">
<p align="center">Diagramma di Sequenza - Inizializzazione configurazioni</p>
</div>

Il secondo diagramma di sequenza riportato per la fase di inizializzazione riguarda il recupero e la condivisione dei componenti fisici nella serra e dei Thing Descriptor.  
In questo caso, l'agente che si occupa di iniziare questo flusso è il __discoverComponentsAgent__; per prima cosa viene mandato un messaggio a __Edge__, di modo da poter ottenere il Thing Descriptor. Tramite questo, __discoverComponentsAgent__ è in grado di estrarre anche i componenti fisici nella serra con i quali è possibile comunicare, che sia tramite azioni o accedendo a delle proprietà.  
A questo punto vengono creati due messaggi:
- _setupComponents_: condivide la lista dei componenti a __sampleBasedActuatorAgent__, __timeBasedActuatorAgent__ e __samplingCoordinatorAgent__.
- _setupTds_: gli agenti ai quali vengono propagati i Thing Descriptor sono __sampleBasedActuatorAgent__, __timeBasedActuatorAgent__ e __samplingAgent__.  

Nella sua interezza, la sequenza di messaggi appena descritta viene ripetura regolarmente, al fine di riuscire ad intercettare eventuali cambiamenti. Questo permette di riuscire a modificare dinamicamente la lista di componenti e Thing Descriptor senza dover mettere mano al codice, inserendo nuovi attuatori e sensori in modo molto agile.  

<div align="center">
<img src="https://images2.imgbox.com/f2/90/xGndWEUf_o.png" alt="Sequence diagram - components and thing descriptors setup">
<p align="center">Diagramma di Sequenza - Inizializzazione componenti e Thing Descriptor</p>
</div>

## Fase di campionamento
La fase di campionamento riguarda il comportamento centrale del sistema e coinvolge diversi agenti. Il campionamento viene svolto periodicamente, a intervalli di tempo molto brevi, di modo che il sistema possa monitorare dati aggiornati e compiere azioni nel caso sia ritenuto necessario.  

Il flusso di esecuzione in questo caso viene iniziato dal __samplingCoordinatorAgent__: quest'ultimo richiede ad un __samplingAgent__ di occuparsi dell'effettivo recupero dei dati. Al fine di ottenere i nuovi dati, __samplingAgent__ manda una richiesta a __Edge__, che può essere effettuata grazie all'uso dei Thing Descriptor. __Edge__ restituisce quindi i dati, e __samplingAgent__ li consegna al __samplingCoordinatorAgent__ per mezzo del messaggio chiamato _checkSamples_.  
Una volta ottenuta la media dei nuovi dati campionati, viene verificato se la differenza tra gli ultimi dati e quelli appena recuperati supera un certo delta: nel caso in cui sia così, allora è previsto che tali dati vengano resi persistenti. Per fare in modo che questo avvengo, __samplingCoordinatorAgent__ manda un messaggio chiamato _uploadPersistence_ a __persistenceAgent__. Questo agente si occupa di mandare una HTTP Post a __Persistence Service__, effettuando così la richiesta che tali dati campionati vengano salvati sul database.  
Un altro flusso di messaggi opzionale è quello che viene eseguito nel caso in cui la media dei dati campionati non rientri tra il valore minimo e massimo delle configurazioni attuali. Se ciò avviene, allora è richiesto che uno o più attuatori vengano azionati perché tali dati possano poi tornare nell'intervallo di valori previsto. Per fare ciò __samplingCoordinatorAgent__, manda il messaggio _actuate_ a __sampleBasedActuatorAgent__, il quale, per mezzo dei Thing Descriptor, potrà comunicare con __Edge__ per fare in modo che dei componenti fisici svolgano determinate azioni.

<div align="center">
<img src="https://images2.imgbox.com/14/38/8T2EqfYm_o.png" alt="Sequence diagram - sampling">
<p align="center">Diagramma di Sequenza - Campionamento</p>
</div>

## Fase di attuazione a tempo


<div align="center">
<img src="https://images2.imgbox.com/4b/67/ceBxFAom_o.png" alt="Sequence diagram - time based actuation">
<p align="center">Diagramma di Sequenza - Attuazione a tempo</p>
</div>