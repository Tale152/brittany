---
title: Organizzazione
parent: Edge
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

### test
Anche per i test vi sono due cartelle principali:

- _brittany_: I test all'interno di questa cartella possono venir eseguiti su qualunque sistema operativo desktop. Viene principalmente testato il funzionamento dell'architettura utilizzando componenti di mock.
- _brittany-concrete_: I test all'interno di questa cartella possono essere eseguiti solo se caricati su un ESP8266. Servono a fare il testing degli effettivi componenti hardware.
