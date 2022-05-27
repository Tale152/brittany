---
title: Organizzazione
parent: Services
grand_parent: Design
nav_order: 1
---

# Organizzazione del codice
Per esplicare la struttura del codice verrà utilizzato l'Auth Service come esempio ma, come anticipato nell'introduzione, essa rimane costante nei tre server.  

## Root del progetto
<div align="center">
<img src="https://images2.imgbox.com/68/a6/w02reIer_o.png" alt="Diagramma delle classi - Root - Auth Service">
<p align="center"> Diagramma dei package - root - Auth Service </p>
</div>

Come in ogni progetto Node, nella root del progetto troviamo il file __package.json__ che, oltre a specificare le dipendenze del progetto ed altre proprietà, ci rivela il punto di partenza dell'applicazione: __index.js__, situato anch'esso nella route del progetto; all'interno di esso troviamo il codice per l'avvio di Mongoose.  
Sempre all'interno della root troviamo le due cartelle principali: __src__ e __test__.

## src
<div align="center">
<img src="https://images2.imgbox.com/74/c0/UKhmDxOO_o.png" alt="Diagramma delle classi - src - Auth Service">
<p align="center"> Diagramma dei package - src - Auth Service </p>
</div>

Dentro questa cartella troviamo:
### __server.js__  
Come precedentemente affrontato, in _index.js_ viene specificato il codice per avviare Mongoose, ma quest'ultimo dipende dall'avvio dell'istanza di un server Express. In questo file viene per l'appunto definito l'avvio di tale server (Express funziona in maniera indipendente da Mongoose) e tale codice viene richiamato da _index.js_ all'avvio dell'applicativo.
### __conf.js__  
Qui risiedono alcune configurazioni utilizzate da _index.js_, visto in precedenza.
### __mongoose__  
Nell'utilizzare Mongoose, vanno definiti degli Schema; essi specificano la struttura dei dati da salvare all'interno di MongoDB. Questa cartella contiene per l'appunto le definizioni di tali Schema e delle factory per creare le istanze dei dati da salvare.
### __routes__  
All'interno di questa cartella sono presenti i file che definiscono le route per macro-aree e referenziano le implementazioni delle singole route per tale macro-area.  
All'interno della cartella __controllers__ dunque si possono trovare le implementazioni delle singole routes.  
Prendiamo ad esempio la macro area _farmer_ all'interno della quale sono disponibili quattro route:
- POST /farmer/register
- GET /farmer/login
- GET /farmer/list
- GET /farmer/info  

__farmer.js__ sarà dunque il punto d'accesso a questa macro-area mentre, all'interno di __controllers > farmer__ troveremo i quattro file contenenti le implementazioni delle quattro route.

### __setup__
All'interno di questa cartella vi è il codice centralizzato che referenzia i punti di ingresso delle routes e imposta altri aspetti come le CORS policies. Tale codice viene utilizzato in _server.js_.

## test
<div align="center">
<img src="https://images2.imgbox.com/06/fb/4EFhCC4F_o.png" alt="Diagramma dei package - test - Auth Service">
<p align="center"> Diagramma dei package - test - Auth Service </p>
</div>

La cartella test mantiene un'organizzazione in linea con la cartella routes precedentemente affrontata, in quanto l'obiettivo dei test nel sistema è appunto verificare il funzionamenti di tali routes.  
All'interno della cartella della macro area dunque troveremo dei file contenenti i test specifici per le varie API; continuando l'esempio dei farmer, all'interno dell'omonima cartella troveremo:
- get.info.test.js
- get.list.test.js
- get.login.test.js
- post.register.test.js
