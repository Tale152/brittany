---
title: Organizzazione
parent: Greenhouse Core
grand_parent: Design
nav_order: 1
---

# Organizzazione
L'organizzazione di Greenhouse Core è stata effettuata utilizzando il plug-in di JaCaMo. La struttura dei package è quindi specifica del framework utilizzato, che è come anticipato JaCaMo.

Quando creato, un progetto JaCaMo è composto da tre package principali: __agt__, __env__ e __org__.

Come si può notare, nel diagramma dei package proposto, il package _org_ non è presente: questa decisione è stata presa perché non sono state utilizzate le _organization_ messe a disposizione da JaCaMo, e nello specifico dalla tecnologia __Moise__. Il modello per la gestione di sistemi multi-agente proposta da Moise prevede che ci sia una gerarchia molto precisa di agenti, ognuno con il proprio ruolo, gruppo e missione da compiere; questo, per il modo in cui il progetto è stato pensato, sarebbe stato troppo vincolante, poiché gli agenti creati collaborano tra loro a pari livello, senza che ci sia un agente che domini sugli altri.

<div align="center">
<img src="https://images2.imgbox.com/b6/84/Tyx8fIsi_o.png" alt="Package diagram - greenhouse core">
<p align="center">Diagramma dei Package - Greenhouse Core</p>
</div>

Di seguito si andranno a definire lo scopo dei package presenti e la loro struttura interna.

## agt

Il package __agt__ ha lo scopo di contenere gli agenti che fanno parte del sistema utilizzando la tecnologia basata su __Jason__.

Per ogni agente, nel seguente package, è specificato in che modo dovrà comportarsi e che tipo di azione dovrà compiere nel caso in cui riceva un messaggio da un altro agente.  
In questo modo è possibile creare agenti in grado di seguire un certo ciclo di vita, basato anche sulle informazione che ricevono dall'esterno.

Il package non è stato suddiviso ulteriormente.

## env

Il package __env__ è stato sviluppato sulla base del framework __Cartago__, che permette di sviluppare degli ambienti virtuali ai quali gli agenti possono fare riferimento, denominati __Artefatti__.  
Al loro interno non è specificato il life cycle degli agenti, ma è presente l'implementazione delle operazioni che possono compiere e le informazioni che possono salvare internamente. 

<div align="center">
<img src="https://images2.imgbox.com/de/03/z9iRXy3A_o.png" alt="Package diagram - env - greenhouse core">
<p align="center">Diagramma dei Package - env - Greenhouse Core</p>
</div>

Come si può vedere dal diagramma dei package sopra, il package è stato suddiviso come segue:
- __actuators__  
  Lo scopo di questo package è quello di contenere gli artefatti utilizzati dagli agenti che operano come attuatori.
- __common__  
  Questo package viene utilizzato come artefatto comune, poiché viene osservato da tutti gli agenti e permette di condividere le informazioni necessarie per tutte le operazioni, ovvero le configurazioni impostate dall'utente, la lista dei componenti fisici connessi e i Thing Descriptor.
- __communication__  
  Il package communication contiene gli artefatti che sono utilizzati dagli agenti per la comunicazione con il mondo esterno; sono infatti presenti gli artefatti per contattare i __Service__ (Authentication, Settings e Persistence) e per ricercare gli __Edge__ connessi al fine di reperire i Thing Descriptor.
- __sampling__  
  All'interno del package sampling si trovano gli artefatti sviluppati al fine di coordinare e effettuare il campionamento dei dati dai dispositivi connessi.
- __utility__  
  Infine, il packege utility contiene classi Java utilizzate per rappresentare determinate le strutture dati più complesse, o classi con metodi statici utilizzabili in ogni evenienza in cui siano ritenute necessarie, evitanto la ripetizione di codice.
  - __component__: è contenuta al suo interno la classe che rappresenta i componenti fisici connessi a Edge, il Builder per tale classe e un classe con metodi di utilità per la gestione dei componenti.
  - __sample__: package contenente la classe per rappresentare i dati campionati e una classe con metodi di utilità per la loro gestione.
  - __setting__: package per la gestione delle configurazioni, le quali possono essere costruite tramite una Factory.