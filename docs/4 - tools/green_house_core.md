---
title: Greenhouse Core 
has_children: false
parent: Strumenti utilizzati
---

# Strumenti utilizzati - Grenhouse core

In questo capitolo verranno descritti tutti gli strumenti e le tecnologie utilizzate per la costruzione del servizio Greenhouse core.

## JaCaMo
[JaCaMo](http://jacamo.sourceforge.net/) è un framework ideato per lo sviluppo di sistemi multi-agente.  

Un sistema multi-agente è caratterizzato da un insieme di agenti, i quali sono entità autonome e in grado di compiere determinate azioni. Gli agenti nel sistema si trovano in un ambiente e possono interagire in base a regole prestabilite.  

Il framework utilizzato combina tre diverse tecnologie, ovvero:
- Jason: utilizzato per la programmazione di agenti autonomi;
- Cartago: che permette di programmare artefatti;
- Moise: per la programmazione di organizzazioni multi-agente.

L'inclusione di queste tre tecnologie permette di create un ambiente in cui gli agenti possono esistere in modo molto flessibile, definendo quale comportamento un agente deve tenere, a quali informazioni può accedere e il modo in cui può interagire all'occorrenza con altri agenti.

I dettagli di design su come questo framework è stato utilizzato per sviluppare il servizio Greenhouse core verranno dati nella sezione specifica.

## JaCaMo Plug-In
Al fine di riuscire a lavorare al meglio con JaCaMo è stato necessario l'utilizzo del plug-in disponibile per __Eclipse IDE__.  

Una volta installato sull'IDE, è possibile creare un progetto JaCaMo in modo molto agile, avendo immediatamente a disposizione la struttura del progetto che JaCaMo richiede.  

Lo strumento essenziale messo a disposizione dal plug-in per uno sviluppo guidato per JaCaMo è denominato __JaCaMo Navigator__: questo permette di navigare il progetto e di creare agenti, artefatti e organizzazioni nel modo prestabilito. Inoltre è offerto anche un supporto grafico per la gestione delle organizzazioni, evitando di doversi districare in file XML di grandi dimensioni per aggiungere eventuali comportamenti.