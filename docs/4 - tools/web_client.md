---
title: Web Client
has_children: false
parent: Strumenti utilizzati
---

# Strumenti utilizzati - Web Client

In questo capitolo verranno descritti tutti gli strumenti e le tecnologie utilizzate per la costruzione del Web Client.

### React.js

React è un framework open-source che permette di implementare applicazioni web seguendo i principi
della programmazione ad oggetti. In modo particolare risulta essenziale comprendere tre concetti chiave:
- __JSX__: È un’estensione della sintassi di JavaScript. Permette di unire gli aspetti di html come linguaggio di template agli aspetti di JavaScript come linguaggio di scripting in una forma che ne aumenta semplicità e leggibilità. Gli elementi JSX vengono utilizzati nelle definizioni delle funzioni di rendering (che verranno trattate
a breve) semplificando la costruzione della user interface. Attraverso JSX possiamo richiamare un componente React tramite con un meccanismo analogo ai tag in html.
- __Componenti__: Attraverso un componente andiamo a definire quella che risulta essere a tutti gli effetti una classe. Il nostro componente, definito da uno o più costruttori, contiene uno stato; questo stato verrà man-
tenuto, ed eventualmente aggiornato, durante tutto il ciclo di vita (lifecycle) del componente. È possibile ricevere dati ed istruzioni da altri componenti attraverso le props.
- __Stato__: Lo stato è un insieme di proprietà di un componente. Queste proprietà possono variare a seguito dell’interazione con altri componenti o come azione del componente stesso nel caso esso esegua delle azioni a cadenza temporale.
In React inoltre lo stato risulta fondamentale ai fini di ottenere un rendering a schermo performante;  ogni componente React infatti deve obbligatoriamente definire una funzione render().
Attraverso di essa verrà ritornato il contenuto da renderizzare a schermo.
React cambierà il contenuto a schermo (consumando quindi risorse) solamente quando vi saranno
delle modifiche nel contenuto ritornato dalla funzione render(); utilizzando dunque le proprietà che definiscono lo stato del componente all’interno della funzione render() del componente stesso riusciremo a ridurre al minimo indispensabile il numero di volte in cui l’applicazione verrà renderizzata, riflettendo i cambiamenti di stato del componente.

React introduce anche i componenti funzione, che di fatto svolgono la stessa funzione dei componenti precedentemente spiegati (componenti classe), ma con una sintassi più concisa.

<div align="center">
<img src="https://upload.wikimedia.org/wikipedia/commons/a/a7/React-icon.svg" width="200px" height="200px" alt="React logo">
<p align="center">Logo di React.js</p>
</div>
