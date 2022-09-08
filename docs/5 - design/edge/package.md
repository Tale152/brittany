---
title: Organizzazione
parent: Edge
grand_parent: Design
nav_order: 1
---

# Organizzazione

Per semplificare ed organizzare meglio lo sviluppo di Edge è stato utilizzato il tool PlatformIO.  
PlatformIO offre la possibilità di creare dei file di configurazione in cui vengono specificate le configurazioni di diversi "environment".  
Tutte le impostazioni vengono inserite all'interno del file ``platfomio.ini``.

## Environments

Sono stati inizialmente creati solamente due environment, ``native`` e ``nodemcuv2``.

- ``native``: la piattaforma che utilizza questo environment si chiama appunto "native". Il codice sorgente è quindi in grado di essere compilato ed eseguito da qualsiasi sistema operativo Desktop. Come verrà successivamente spiegato, questo environment viene utilizzato principalmente per semplificare i processi di test.
- ``nodemcuv2``: la piattaforma utilizzata in questo caso è "espressif8266" ed è quindi la configurazione destinata al codice che verrà effettivamente compilato ed eseguito sugli ESP8266.

È importante effettuare sin da subito questa distinzione, in quanto alcune librerie non sono ovviamente supportato dai sistemi desktop. Ad esempio ``Arduino.h`` mette a disposizione delle funzioni come "pinMode", che non hanno senso su dispositivi non dotati di pin.

Terminata l'architettura di Edge sono stati creati altri environment. Grazie all'architettura scelta è possibile creare un nuovo environment per ogni configurazione hardware che desideriamo abbia ESP8266.
Grazie alla chiave ``extends`` è infatti possibile creare un nuovo environment a partire da uno già esistente.

In ogni environment è quindi possibile personalizzare Edge in un modo diverso.

## Organizzazione del codice

Quando si crea un progetto PlatformIO vengono create diverse cartelle, in particolare:

- ``src``: la classica cartella in cui viene inserito il codice sorgente.
- ``lib``: simile a main, questa cartella viene utilizzata per la creazioni di librerie create dall'utente ed utilizzate all'interno di src.
- ``test``: la cartella in cui vengono scritti i test dell'applicazione.

### src
La cartella src contiene il file ``main.cpp`` e una cartella in cui ci sono degli header file. All'interno di ognuno di questi ultimi vi sono le diverse configurazioni di Edge. Una volta scelto l'environment viene infatti scelto il file header corrispondente e viene importato all'interno del file main.

### lib
Edge è composto da tre librerie utente. Da questo momento in avanti verranno usati tre colori diversi per identificarle:  
- <span style="background-color: #add8e6"> _brittany_ </span>: la libreria in cui vi sono componenti comuni e utilizzabili senza problemi in qualunque caso, indipendentemente dall'environment.
- <span style="background-color: pink"> _brittany-concrete_ </span>: I componenti di questa libreria non sono utilizzabili nell'environment ``native``. Ad esempio l'implementazione reale di un sensore di temperatura si trova in questa libreria.
- <span style="background-color: #FFFF99"> _brittany-mock_ </span>: I componenti di questa liberia sono utilizzabili anche nell'environment ``native`` e contengono implementazioni di mock, a solo fine di testing.

#### Diagrammi dei package

Viene ora illustrata la divisione in package di ciascuna libreria:

##### brittany

<div align="center">
<img src="https://images2.imgbox.com/b3/3c/sG7VAt8C_o.png" alt="Package diagram - brittany">
<p align="center">Diagramma dei Package - brittany</p>
</div>

I package della libreria ``brittany`` hanno i seguenti scopi:

- __hw__: contiene le classi comuni utili a creare componenti hardware
    - __feature__: contiene classi utili per creare componenti più complessi. Alcuni componenti potrebbero avere infatti feature in comune, per esempio la possibilità di essere accesi o spenti. 
    - __interfaces__: contiene interfacce di partenza per creare degli effettivi componenti o componenti di mock.
- __edge__: contiene le implementazioni della classe edge e altri componenti relativi ad esse.
- __operation-handler__: contiene le classi utili per poter creare degli OperationHandler.
  - __interfaces__: come nel caso di hw, contiene classi utili per poter creare operation handler più complessi a partire da caratteristiche più semplici.
  - __types__: package utilizzato principalmente per informazioni addizionali sugli handler, in particolare informazioni utili per generare un thing descriptor robusto.
- __web-server__: contiene le classi utili per poter creare implementazioni di Web Server ed altre funzioni di utilità a loro collegate.
- __thing-descriptor__: contiene classi utili per generare un Thing Descriptor.
- __modules__: contiene classi utili per creare dei moduli.

##### brittany-mock

<div align="center">
<img src="https://images2.imgbox.com/61/3f/Ypyj15zU_o.png" alt="Package diagram - brittany-mock">
<p align="center">Diagramma dei Package - brittany-mock</p>
</div>

I package della libreria ``brittany-mock`` hanno una struttura solida solo a partire dal secondo layer.  
Nel primo layer ogni package rappresenta un componente di mock. Nel diagramma vengono riportati due esempi di componenti di mock, ``mock-digital-light`` e ``mock-temp-hum-sensor``.
I package scalano ovviamente in funzione al numero di componenti di mock che si aggiungono al sistema.  
Ogni componente è poi suddiviso in:
- __hw__: le implementazioni mock dei relativi componenti hardware.
- __operation-handler__: le implementazioni di mock dei relativi operation handler.
- __modules__: le implementazioni di mock dei relativi moduli.
  
##### brittany-concrete

<div>
<img src="https://images2.imgbox.com/7f/93/md5iN7DL_o.png" alt="Package diagram - brittany-concrete">
<p align="center">Diagramma dei Package - brittany-concrete</p>
</div>

Come per ``brittany-mock``, anche nella libreria ``brittany-concrete`` vi è una divisione per componenti, ma con un livello di dettaglio in più.
Esistono infatti diversi tipi di componenti hardware che effettuano le stesse operazioni ma possono avere implementazioni diverse, a differenza di una classe di mock.  
Nel caso del diagramma, anche in questo caso vi è una divisione in componenti, in particolare ``digital-light`` e ``temp-hum-sensor``. Esistono però diversi tipi di sensori per la misurazione di temperatura ed umidità, per cui è necessaria una ulteriore distinzione, in questo caso tra i sensori di tipo ``dht11`` e ``dht22``.  
Si arriva dunque alle foglie, che anche in questo caso sono:
- __hw__: le implementazioni effettive e reali dei relativi componenti hardware.
- __operation-handler__: le implementazioni effettive e reali dei relativi operation handler.
- __modules__: le implementazioni effettive e reali dei relativi moduli.

### test
Anche per i test vi sono due cartelle principali:
- __test_brittany__: i test all'interno di questa cartella possono venire eseguiti su qualunque sistema operativo desktop. Viene principalmente testato il funzionamento dell'architettura utilizzando componenti di mock.
- __test_brittany-concrete__: i test all'interno di questa cartella possono essere eseguiti solo se caricati su un ESP8266. Servono a fare il testing degli effettivi componenti hardware.