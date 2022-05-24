---
title: Architettura Agenti
parent: Greenhouse Core
grand_parent: Design
nav_order: 6
---

# Struttura agenti
Gli agenti sviluppati tramite l'utilizzo del framework JaCaMo prevedono una certa struttura che è importante specificare al fine di poter descrivere in modo chiaro le scelte che sono state prese.  

Le principali caratteristiche sono:
- _initial goal_  
  Un agente può o meno avere un obiettivo iniziale. Nel caso in cui sia presente, tale agente darà inizio a un certo flusso di esecuzione appena la sua inizializzazione sarà completata.
- _initial belief_  
  Le credenze iniziali entrano a far parte della conoscienza dell'agente e verranno salvata nella _Belief Base (BB)_. Durante l'esecuzione è possibile consultare la _BB_ al fine di poter porre delle condizioni sull'esecuzione di alcuni flussi.
- _plan_  
  Un piano non è altro che un flusso di esecuzione che può essere azionato da un evento interno, ovvero a causa dell'agente stesso, o esterno, nel caso in cui sia causato dalla percezione dell'agente all'ambiente in cui si trova.  

Questi tre elementi sopra elencati costituiscono il modo per permettere agli agenti all'interno del sistema di interagire tra loro, comunicando tramite messaggi che andranno a scatenare l'esecuzione di piani. Un agente può sempre accedere alle operazioni degli __Artefatti__ che gli appartengono, creando quindi la possibilità di eseguire comportamente complessi.  

## Agenti nel MAS
Nel sistema multi-agente sono previsti un totale di 7 diversi tipi di agenti. Prima di andare a spiegare le comunicazioni che intercorrono tra agenti, è importante spiegare il ruolo di ogni agente all'interno del sistema.

### setupAgent
Il __setupAgent__ ha lo scopo di occuparsi dell'autenticazione con i __Services__, di reperire le configurazioni attualmente valide periodicamente e di condividerle con gli altri agenti.  

Nel MAS esiste un unico __setupAgent__, in quanto un solo agente è in grado di svolgere questo compito in modo efficiente. 

Al fine di adempiere al suo scopo, il __setupAgent__ utilizza operazioni presenti nell'__AuthenticationArtifact__, nel __SettingsArtifact__ e nel __CommonArtifact__.  

Questo agente ha un _iniatial goal_, che viene utilizzato per iniziare il suo flusso di esecuzione nel momento in cui l'agente è stato creato.  
L'_initial goal_ citato prende il nome di _authentication_, e permette di andare a chiamare l'operazione _retrieveAuthenticationData_ esposta dall'__AuthenticationArtifact__ al fine di autenticarsi con l'__Auth Service__.  
Una volta ottenuto il _token_, il relativo _plan_ viene azionato, il quale va a richiamara l'operazione __getSettings__ presente nel __SettingsArtifact__: questa piano ha l'obiettivo di andare a recuperare le configurazioni valide e di iniziare un ciclo di richieste, al fine di aggiornare le configurazioni nel caso in cui avvengano dei cambiamenti. Per iniaziare il ciclo appena citato, viene utilizzato il piano _wait_, il quale richiama _updateSettings_ ogni 20 secondi. Il piano _updateSettings_ recupera il _token_ presente nella _Belief Base_ dell'agente, chiama nuovamente _getSettings_ per recuperare le configurazioni e termina ripetendo la chiamata a _wait_, creando quindi il ciclo.  

Infine, ogni volta che le configurazioni vengono recuperate, viene scatenato un altro _plan_, ovvero _settings_, che chiama l'operazione _shareSettings_ presente nel __CommonArtifact__, la quale ha il compito di condividere con gli altri agenti le configurazioni trovate.

### discoverComponentsAgent

### samplingCoordinatorAgent

### samplingAgent

### persistenceAgent

### sampleBasedActuatorAgent

### timeBasedActuatorAgent
