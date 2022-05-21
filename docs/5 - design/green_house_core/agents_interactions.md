---
title: Comunicazione tra Agenti
parent: Greenhouse Core
grand_parent: Design
nav_order: 7
---

# Sequenze di comunicazione degli agenti
Come detto precedentemente, la comunicazione degli agenti permette l'esecuzione di alcuni piani, che vanno ad costituire l'effettivo funzionamento del sistema.  

Per andare a spiegare nel dettaglio quali messaggi gli agenti si scambiano, è necessario fare una premessa: di seguito saranno presenti quattro diagrammi di sequenza, ognuno dei quali avrà lo scopo di mettere in evidenza solo i messaggi che ogni agente manda all'esterno. Questo è stato fatto per una questione di semplicità di tali diagrammi e anche perché il comportamento interno di ogni agente è già stato descritto in precedenza.  

I diagrammi di seguito saranno divisi in base a delle fasi che verranno descritte per ogni capitolo, sempre per mantenere una certa semplicità nella comprensione.  

Infine, all'interno dei diagrammi si sequenza proposti metteno in evidenza anche le comunicazioni con i __Service__ e con __Edge__, andando a fornire un certo grado di completezza anche sotto questo punto di vista.

## Fase di inizializzazione
Rientrano in questa fase i comportamenti dei due agenti principali che si dedicano a recuperare periodicamente dati utili per l'intero sistema, ovvero __setupAgent__ e __discoverComponentsAgent__.  
Nonostante il loro comportamento sia ripetuto a intervalli regolari di tempo, verrà mostrato un'unica iterazione.  

<div align="center">
<img src="https://images2.imgbox.com/58/d5/0xWU7d7Z_o.png" alt="Sequence diagram - settings setup">
<p align="center">Diagramma di Sequenza - Inizializzazione configurazioni</p>
</div>

<div align="center">
<img src="https://images2.imgbox.com/f2/90/xGndWEUf_o.png" alt="Sequence diagram - components and thing descriptors setup">
<p align="center">Diagramma di Sequenza - Inizializzazione componenti e Thing Descriptor</p>
</div>

## Fase di campionamento

<div align="center">
<img src="https://images2.imgbox.com/14/38/8T2EqfYm_o.png" alt="Sequence diagram - sampling">
<p align="center">Diagramma di Sequenza - Campionamento</p>
</div>

<div align="center">
<img src="https://images2.imgbox.com/4b/67/ceBxFAom_o.png" alt="Sequence diagram - time based settings check">
<p align="center">Diagramma di Sequenza - Gestione configurazioni a tempo</p>
</div>