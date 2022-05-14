---
title: Boundex Context
parent: Domain Knowledge
has_children: false
nav_order: 3
---

# Boundex Context

A seguito dell’individuazione dei casi d’uso, si è andata a espandere l’analisi al
fine di individuare i principali bounded context associati al progetto.

<div align="center">
<img src="https://images2.imgbox.com/42/58/VlTjyhVu_o.png" alt="Boundex context graph">
<p align="center">Grafico per la rappresentazione dei bounded context</p>
</div>

Nel grafico verranno riportati i bounded context. L'asse delle _x_ indica quanto il context è importante per il business mentre l'asse delle _y_ rappresenta quanto il modello è complesso da realizzare.

<div align="center">
<img src="https://images2.imgbox.com/40/9a/ET0W3TO8_o.png" alt="Boundex context graph with context">
<p align="center">Grafico dei bounded context</p>
</div>

### Context map

Lo studio del problema ha portato a definire quattro aree critiche che compongono il sistema, le quali necessitano un importante isolamento, al fine di garantire indipendenza e chiara suddivisione dei moduli durante la fase di sviluppo.  
Una corretta suddivisione dei bounded context in fase iniziale permette di scomporre in maniera più chiara il lavoro.

Sono stati individuati i seguenti bounded context:

- __Core Bounded Context__: gli aspetti più cruciali e da cui tutto il resto del sistema dipende molto fortemente;
- __Service Bounded Context__: gli aspetti più orientati alla gestione dei dati ottenuti.
- __Client Bounded Context__: gli aspetti che riguardano l'interazione dell'utente finale con il sistema.
- __DevOps Bounded Context__: gli aspetti dedicati alle attività della metodologia DevOps;

Di seguito è riportata la context map del progetto.

<div align="center">
<img src="https://images2.imgbox.com/03/1f/U8vn2P79_o.png" alt="Context map">
<p align="center">Context Map</p>
</div>

##### Core Bounded Context
Il bounded context per gli aspetti core comprende due moduli del progetto:
- _Edge_: aspetti più legati alla sensoristica, al raccogliemento di dati, all'eseguire azioni in un determinato ambiente.
- _Greenhouse core_: aspetti legati all'effettivo comportamento tenuto dalla serra in funzione di ciò che _Edge_ trasmette.

Insieme, questi due moduli sono già sufficienti per far funzionare il sistema in una sua versione base.  
In particolare, _Edge_ offre una API a _Greenhouse core_, la quale comprende come è fatto _Edge_ e di conseguenza, come comportarsi e come orchestrare la situazione.

##### Service Bounded Context

Il bounded context dei Service comprende aspetti strettamente legati ai dati.    
In particolare per ogni service esiste:
- Una API utilizzata per l'interazione con Greenhouse core;
- Una modalità per immagazzinare e reperire successivamente dati.

##### Client Bounded Context
Il bounded context Client comprende aspetti legati all'esperienza utente e al modo in cui quest'ultimo può interagire col sistema.  
In pratica si tratta di un portale in cui l'utente può effettuare operazioni o visionare dati.  
Grazie alle API offerte dai service il client potrà essere implementato su una qualsiasi piattaforma.

##### DevOps Bounded Context

È stato definito un bounded context anche per ciò che concerne la metodologia DevOps. Graficamente non è stato riportato alcun collegamento per semplicità. Gli aspetti legati al DevOps sono infatti estremamente pervasivi e influenzano in maniera indiretta tutti gli altri bounded context.
