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
Una volta ottenuto il _token_, il relativo _plan_ viene azionato, il quale va a richiamara l'operazione _getSettings_ presente nel __SettingsArtifact__: questa piano ha l'obiettivo di andare a recuperare le configurazioni valide e di iniziare un ciclo di richieste, al fine di aggiornare le configurazioni nel caso in cui avvengano dei cambiamenti. Per iniaziare il ciclo appena citato, viene utilizzato il piano _wait_, il quale richiama _updateSettings_ ogni 20 secondi. Il piano _updateSettings_ recupera il _token_ presente nella _Belief Base_ dell'agente, chiama nuovamente _getSettings_ per recuperare le configurazioni e termina ripetendo la chiamata a _wait_, creando quindi il ciclo.  

Infine, ogni volta che le configurazioni vengono recuperate, viene scatenato un altro _plan_, ovvero _settings_, che chiama l'operazione _shareSettings_ presente nel __CommonArtifact__, la quale ha il compito di condividere con gli altri agenti le configurazioni trovate.

### discoverComponentsAgent
Il __discoverComponentsAgent__ viene utilizzato per scoprire se sulla stessa rete LAN del sistema multi-agente sono presenti degli __Edge__ con i quali comunicare.  

Per fare questo, dopo la sua creazione l'agente inizia a cercare di adempiere al suo scopo, stabilito tramite l'_initial goal_ _discover_. Questo porta alla chiamata dell'operazione _discoverComponents_, la quale si trova nel __DiscoverComponentsArtifact__. Questa operazione itera su tutti gli indirizzi della rete locale in cui si trova il sistema, ricercando componenti che siano in grado di restituire un Thing Descriptor valido.  
Come detto in precedenza, un requisito del sistema multi-agente è quello di essere in grado di aggiungere dinamicamente nuovi __Edge__ connessi; per questa ragione, una volta terminata l'operazione di ricerca, tramite l'uso del piano _wait_, si attendono 20 secondi, e poi il piano _discover_ viene nuovamente chiamato. Questo crea un ciclo che permette al sistema di aggiornarsi nel caso in cui sia necessario.

Quando un __Edge__ viene identificato tramite la ricerca su tutti gli indirizzi locali, allora il Thing Descriptor restituito viene analizzato: tramite il TD infatti è possibile estrarre tutti i componenti fisici, che siano attuatori o sensori, con i quali il sistema multi-agente può comunicare, e quali sono le azioni e le proprietà che possono essere richiamate.  
Una volta ottenute tutte le informazioni necessarie, utilizzando le operazioni nel __CommonArtifact__, queste verranno condivise a tutti gli agenti interessati; la chiamata delle operazione nel __CommonArtifact__  viene fatta utilizzando il piano _components_ e il piano _thingDescriptors_ del __discoverComponentsAgent__.

### samplingCoordinatorAgent
Il __samplingCoordinatorAgent__ gestisce in che modo compiere il campionamento dei dati e prende decisioni su come reagire ai dati appena ottenuti.  

Nel MAS sono stati creati più __samplingCoordinatorAgent__, ognuno dei quali si occupa di coordinare il campionamento di una categoria diversa di sensori.  
Per questo, quando vengono creati, viene anche aggiunto un _initial belief_, che andrà a costituire la categoria di cui tale agente è responsabile.  
Per esempio, nel sistema implementato sono presenti due agenti di questo tipo:  
- uno ha come _belief_ __temperature__, quindi si dedicherà alla coordinazione del campionamento di tutti i sensori che trattano la temperatura;
- il _belief_ dell'altro agente è __airHumidity__, quindi è dedicato alla gestione del campionamento riguardante l'umidità dell'aria.

L'_initial goal_ di un __samplingCoordinatorAgent__ è _sample_, il quale si occupa di recuperare la categoria a cui è assegnato dalla _BB_ e chiama l'operazione _sampleOperation_ presente nel __SamplingCoordinatorArtifact__. In questo modo l'agente sta richiedendo di campionare i dati di un certo tipo di sensori, senza sapere quale agente adempierà effettivamente alla sua richiesta.  
Oltre a ciò, viene anche chiamato _wait_, di modo da iniziare un ciclo che ogni 5 secondi ripeterà il piano _sample_.  

Come detto in precedenza, il __samplingCoordinatorAgent__ è l'unico ad avere informazioni a sufficienza per riuscire a stabilire come comportarsi alla ricezione dei dati campionati. Quando il campionamento è completato, viene scatenato il piano _checkSamples_, il quale, se la categoria dei dati ricevuti è quella presente nella sua _BB_, chiama l'operazione _updateOperation_ presente nel __SamplingCoordinatorArtifact__.  
L'operazione va a stabilire se rendere i dati persistenti e se è opportuno azionare degli attuatori. Questo comportamento è stato descritto nel dettaglio nella sezione precedente relativa al __SamplingCoordinatorArtifact__.

### samplingAgent
Il __samplingAgent__ ha l'unico scopo di comunicare con un determinata lista di componenti fisici collegati a __Edge__.  
Per questa ragione, non ha un _initial goal_, ma rimane semplicemente in attesa che il suo piano _sampling_ venga azionato. Questo piano utilizza l'operazione __getSamples__ esposta dal __SamplingArtifact__, la quale effettua l'effettiva operazione di campionamento.  

All'interno del MAS è presente un unico __samplingAgent__ al momento, poiché è stato ritenuto sufficiente in fase di verifica del funzionamento del sistema. Aggiungere nuovi agenti di questo tipo è comunque una cosa molto agevole, l'unica cosa necessaria sarebbe stabilire quali categorie dovrebbe prendere in carico un agente, al fine di evitare che più agenti richiedano i dati agli stessi componenti.

### persistenceAgent
Il __persistenceAgent__ viene utilizzato per rendere persitenti i dati e deve comunicare con il __Persistence Service__ per tale scopo.

Questo agente ha un comportamento molto simile al __samplingAgent__ appena descritto: infatti anche lui non ha un _initial goal_, semplicemente attende passivamente che il suo piano venga azionato, in questo caso _uploadPersistence_.  
Quando il suo unico piano viene azionato, l'agente recupera dalla sua _BB_ il _token_ necessario per la comuncazione con i servizi e chiama poi l'operazione __uploadPersistence__ presente nel __PersistenceArtifact__. In questo modo invia effettivamente i dati al __Persistence Service__, rendendoli permanenti.

Anche in questo caso, come nel precedente, esiste nel sistema un unico __persistenceAgent__, ma rimane molto semplice aggiungerne altri nel caso in cui il lavoro sia troppo per essere gestito da un solo agente.

### sampleBasedActuatorAgent

### timeBasedActuatorAgent
