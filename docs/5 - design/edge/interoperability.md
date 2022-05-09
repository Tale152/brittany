---
title: Interoperabilità
parent: Edge
grand_parent: Design
nav_order: 5
---

# Interoperabilità con gli altri sistemi

## Edge ⇆ Greenhouse core
Edge è un componente completamente passivo. Per come è stata impostata l'architettura, un dispositivo Edge si collega ad un router e da quel momento acquisisce un indirizzo IP che gli permette di essere identificato in modo univoco nella rete.

<div align="center">
<img src="https://images2.imgbox.com/24/c4/dlzNAr5C_o.png" alt="Chip ESP8266" width="435" height="215">
<p align="center">Collegamenti di Edge che permettono interoperabilità</p>
</div>

Ogni Edge secondo l'architettura comunica solo con Greenhouse core, ma non esiste nessun tipo di collegamento diretto. Il sistema ad agenti Greenhouse core e tutti i dispositivi Edge si trovano infatti sulla stessa rete. Greenhouse Core riesce a capire con chi può comunicare grazie ai Thing Descriptor che solo i dispositivi Edge espongono.  
Ci sono più motivi per cui è stata scelta questa architettura:

- **Meno dipendenze**: I dispositivi Edge non dipendono in modo diretto da Greenhouse core. Se esistesse un collegamento diretto tra Edge e Greenhouse core, un eventuale cambio di API di un sistema causerebbe la necessità di aggiornamento anche nell'altro;
- **Aderenza agli standard W3C**: I dispositivi Edge forniscono una rappresentazione JSON di ciò che rappresentano grazie al Thing Descriptor. In questo modo non solo Greenhouse Core ma anche eventuali componenti che verranno aggiunti in futuro potranno utilizzare i dispositivi Edge con semplicità;
- **Sicurezza**: Attraverso il Thing Descriptor è possibile anche impostare quale Security Schema utilizzare per le interazioni. Esistono molteplici opzioni disponibili, una lista esaustiva è disponibile presso la [Web of Things (WoT) Security Ontology](https://www.w3.org/2019/wot/security#SecurityScheme). Inoltre è smpre possibile aggiungere meccanismi di sicurezza ad un livello più alto, per esempio sulla rete a cui gli Edge sono connessi.
