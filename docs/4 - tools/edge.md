---
title: Edge
has_children: false
parent: Strumenti utilizzati
---

# Strumenti utilizzati - Edge

Verrano di seguito illustrati gli strumenti ed i framework utilizzati nel servizio di Edge del sistema.

## PlatformIO

Per programmare su schede Arduino si è soliti utilizzare il famoso IDE di Arduino, in quanto molto semplice da utilizzare, e adatto a principianti.
Le operazioni messe a disposizione sono però minime e spesso non sufficienti per utenti esperti.  
Esistono molti ambienti di sviluppo professionali che aggiungono numerose funzionalità, modalità di autocompletamento e tanto altro ancora.
Uno degli ambienti più diffusi è PlatformIO, sviluppato in Python.
PlatformIO favorisce notevolmente lo sviluppo di sistemi embedded in C/ C++.  
L’estensione è gratuita ed Open Source.
Il supporto alle schede è molto vasto e la semplicità di configurazione è uno dei punti forti dell'ambiente.

La creazione di un progetto è molto semplice ed è possibile tramite IDE o riga di comando.
Alla creazione di un progetto PlatformIO vengono create le cartelle per sorgenti, test, etc.
ed il file di configurazione ``platformio.ini`` che permette di configurare ogni aspetto del progetto.

Il file di configurazione è diviso in "ambienti". In questo modo è possibile creare diversi tipi di configurazione per lo stesso sistema, in modo da favorire il riuso del codice e molto altro.

<div align="center">
<img src="https://cdn.platformio.org/images/platformio-logo.17fdc3bc.png" width="200px" height="200px" alt="PlatformIO Logo">
<p align="center">Logo di PlatformIO</p>
</div>
