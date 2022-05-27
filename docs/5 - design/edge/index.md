---
title: Edge
parent: Design
has_children: true
---

# Edge
Edge è il nome utilizzato per definire gli end point del sistema. Un edge è un dispositivo in grado di acquisire dati tramite sensori ed eseguire azioni tramite attuatori.  
I componenti Edge sono stati sviluppati utilizzando la filosofia ed alcuni standard del [W3C Web Of Things](https://www.w3.org/WoT/).  

Un dispositivo Edge può avere funzionalità specifiche in base ai componenti che riesce a manipolare e al luogo in cui si trova. Per poter coprire tutti i casi possibili è stato necessario rendere l'architettura il più modulare possibile.

<div align="center">
<img src="https://images2.imgbox.com/f9/f0/qtyFHYUJ_o.jpg" alt="Chip ESP8266" width="150" height="150">
<p align="center">Chip ESP8266</p>
</div>

Per quando riguarda l'hardware e gli stack tecnologici utilizzati si è deciso di optare per dei dispositivi adatti all'IoT. Per sviluppare il software sono stati utilizzati degli ESP8266 (NoveMCU v2) ma qualunque scheda in grado di supportare le piattaforme Arduino like non dovrebbero dare alcun tipo di problema. Il linguaggio utilizzato è C++17.
