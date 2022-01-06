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
a breve) semplificando la costruzione della user interface. Attraverso JSX possiamo richiamare un componente React tramite con un meccanismo analogo ai tag in html;
- __Componenti__: Attraverso un componente andiamo a definire quella che risulta essere a tutti gli effetti una classe. Il nostro componente, definito da uno o più costruttori, contiene uno stato; questo stato verrà man-
tenuto, ed eventualmente aggiornato, durante tutto il ciclo di vita (lifecycle) del componente. È possibile ricevere dati ed istruzioni da altri componenti attraverso le props;
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

### Redux

Redux è un contenitore di stato per applicazioni JavaScript.
Gode di quattro caratteristiche fondamentali per progetti portata medio-grande:
- __Deterministico__: Un aspetto fondamentale nelle applicazioni web di ogni genere è il determinismo.
L’oneroso compito di far collaborare tutti i componenti al fine di ottenere un comportamento predi-
cibile viene largamente semplificato dal framework Redux;
- __Centralizzato__: Avere stato e logica centralizzati permette di ottenere rapidamente delle feature di fondamentale
importanza, come funzioni di "annulla" e "ripeti" che ci permettono di muoverci agilmente tra lo
storico degli stati.
Inoltre un approccio centralizzato garantisce un consistenza maggiore dei dati, rendendo possibi-
le modificarli solamente attraverso specifiche funzioni (azioni) create durante la definizione della struttura dati;
• __Debug oriented__: Attraverso semplici plugin browser come Redux DevTools risulta immediato il debug dell’applicazio-
ne. Difatti attraverso questi tool otteniamo una visione completa dello stato dei dati e della sua evoluzione nel tempo, riuscendo ad identificare con precisione quando e soprattutto perchè lo stato abbia subito delle modifiche;
- __Flessibile__: Redux funziona con ogni layer di User Interface e, essendo ormai uno strumento consolidato, dispone di un solido supporto e un vasto parco di plugin e pacchetti aggiuntivi per ogni esigenza. 

Per comprendere come queste caratteristiche si concretizzino risulta fondamentale comprendere tre con-
cetti chiave nella struttura di Redux:
- __Store__: Lo store è un oggetto che contiene l’intera struttura ad albero dello stato.
Fornisce metodi per la lettura dello stato corrente;
- __Reducer__: I reducer definiscono la struttura dello store.
Vi possono essere più reducer all’interno di una stessa applicazione, al fine di meglio suddividere lo stato;
- __Azioni__: Le azioni permettono di modificare il contenuto dello store. Essendo queste l’unico modo per alterare lo stato attuale, qualsiasi componente che voglia agire sullo stato deve passare per le azioni definite.

Ma perchè utilizzare un contenitore di stato se ogni componente React possiede già uno stato? React, pur essendo uno strumento molto potente, ci pone davanti a delle limitazioni:
- Innanzitutto non è raro che più componenti debbano fare riferimento allo stesso dato; la presenza di uno stato comune evita di dover implementare meccanismi ad hoc di sincronia tra gli stati dei due componenti. Lo stato di ogni componente, attraverso tool ready to use, sarà dunque sincronizzato con la struttura
principale;
- In secondo luogo React, data la sua natura orientata al reactive programming, incoraggia la propagazione dell’informazione solo in una direzione: da un componente padre verso un componente figlio (utilizzato dunque dal padre).
La presenza delle azioni Redux risolvono questo problema in quanto ogni cambiamento apportato
allo stato Redux si rifletterà su tutti i componenti React che utilizzano quel particolare dato.

<div align="center">
<img src="https://redux.js.org/img/redux-logo-landscape.png" width="300px" height="150px" alt="Redux logo">
<p align="center">Logo di Redux</p>
</div>

