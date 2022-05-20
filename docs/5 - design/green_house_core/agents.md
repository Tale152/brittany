---
title: Architettura Agenti
parent: Greenhouse Core
grand_parent: Design
nav_order: 6
---

# Struttura agenti
Gli agenti sviluppati tramite l'utilizzo del framework JaCaMo prevedono una certa struttura che è importante specificare al fine di poter descrivere in modo chiaro le scelte che sono state prese.  

Le principali caratteristiche sono:
- _initial goal_  
  Un agente può o meno avere un obiettivo iniziale. Nel caso in cui sia presente, tale agente darà inizio a un certo flusso di esecuzione appena la sua inizializzazione sarà completata.
- _initial belief_  
  Le credenze iniziali entrano a far parte della conoscienza dell'agente e verranno salvata nella _Belief Base (BB)_. Durante l'esecuzione è possibile consultare la _BB_ al fine di poter porre delle condizioni sull'esecuzione di alcuni flussi.
- _plan_  
  Un piano non è altro che un flusso di esecuzione che può essere azionato da un evento interno, ovvero a causa dell'agente stesso, o esterno, nel caso in cui sia causato dalla percezione dell'agente all'ambiente in cui si trova.  

Questi tre elementi sopra elencati costituiscono il modo per permettere agli agenti all'interno del sistema di interagire tra loro, comunicando tramite messaggi che andranno a scatenare l'esecuzione di piani. Un agente può sempre accedere alle operazioni degli __Artefatti__ che gli appartengono, creando quindi la possibilità di eseguire comportamente complessi.  

## Agenti nel MAS

### setupAgent

### discoverComponentsAgent

### samplingCoordinatorAgent

### samplingAgent

### persistenceAgent

### sampleBasedActuatorAgent

### timeBasedActuatorAgent
