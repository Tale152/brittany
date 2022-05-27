---
title: Organizzazione
parent: Web Client
grand_parent: Design
nav_order: 1
---

# Organizzazione

## Root del progetto
All'interno di un progetto React vi sono due directory principali:
- __src__: contiene al suo interno i sorgenti del progetto
- __public__: contiene file come il manifest, il punto d'ingresso html, l'icona da visualizzare nella tab del browser, ecc...  

React Testing Library non permette di utilizzare file di test contenuti all'esterno della cartella _src_; è convenzione del linguaggio dunque tenere i file di test nella stessa directory dei componenti testati (piuttosto che in una directory _test_ come in altri framework).  

Sempre parlando di convenzioni, i progetti React sono noti per non avere una struttura standardizzata. Si è scelto di dividere i sorgenti contenuti in _src_ in tre directory:
- __js__: contiene codice procedurale in JavaScript, principalmente riguardanti le chiamate HTTP
- __react__: contiene i componenti grafici da renderizzare a schermo
- __redux__: contiene le definizioni delle strutture dati Redux e le funzioni per manipolarle

<div align="center">
<img src="https://images2.imgbox.com/c1/c0/4nUzy3bR_o.png" alt="Diagramma dei package - root">
<p align="center"> Diagramma dei package - root </p>
</div>

## js e redux

Le due directory sono state accumunate in questo capitolo in quanto risultano una lo specchio dell'altra.  

Le strutture dati contenute nella cartella _redux_ vengono popolate attraverso i risultati ottenuti dalle chiamate HTTP effettuate tramite le funzioni definite nella directory _js_; analogamente, un cambio nello stato interno di Redux si rifletterà in chiamate HTTP volte a comunicare il cambiamento ai Services.

<div align="center">
<img src="https://images2.imgbox.com/f1/bc/OmaPKxPt_o.png" alt="Diagramma dei package - js">
<p align="center"> Diagramma dei package - js </p>
</div>

<div align="center">
<img src="https://images2.imgbox.com/50/bb/9nyXFJt2_o.png" alt="Diagramma dei package - redux">
<p align="center"> Diagramma dei package - redux </p>
</div>

## react
In quest'ultima directory sono contenute le definizioni dei componenti grafici React che popolano la GUI.  

Come intuibile dal nome, la directory _common_ contiene componenti comuni riutilizzati da altri componenti; le directory rimanenti, invece, trovano una corrispondenza con le varie pagine che l'utente può visitare.

<div align="center">
<img src="https://images2.imgbox.com/fb/db/xXaZw7fn_o.png" alt="Diagramma dei package - react">
<p align="center"> Diagramma dei package - react </p>
</div>
