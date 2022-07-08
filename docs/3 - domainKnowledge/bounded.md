---
title: Bounded Context
parent: Domain Knowledge
has_children: false
nav_order: 4
---

# Bounded Context

### Context map

Lo studio del problema ha portato a definire quattro aree critiche che compongono il sistema, le quali necessitano un importante isolamento, al fine di garantire indipendenza e chiara suddivisione dei moduli durante la fase di sviluppo.  
Una corretta suddivisione dei bounded context in fase iniziale permette di scomporre in maniera più chiara il lavoro.

Di seguito è riportata la context map del progetto.

<div align="center">
<img src="https://images2.imgbox.com/c4/66/nDbaKvXz_o.png" alt="Context map">
<p align="center">Context Map</p>
</div>

Sono stati individuati i seguenti bounded context:

- __Edge__: La parte di sistema più fisica e dedicata alla sensoristica. Riguarda i componenti hardware che verranno installati all'interno delle serre.
- __Greenhouse Core__: La parte di sistema che interroga i componenti hardware esamina le risposte ed eventualmente prende decisioni.
- __Auth Service__: La parte di sistema dedicata all'autenticazione degli utenti.
- __Persistence Service__: La parte di sistema dedicata alla memorizzazione dei dati.
- __Settings Service__:  La parte di sistema dedicata alla gestione delle impostazioni.
- __Client__: La parte dedicata all'iterazione tra l'utente finale ed il sistema.


<div align="center">
<img src="https://images2.imgbox.com/2c/b1/oyvUIDhB_o.png" alt="Context map">
<p align="center">Context Map più dettagliata</p>
</div>
