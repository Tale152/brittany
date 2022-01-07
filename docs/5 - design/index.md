---
title: Design
has_children: true
nav_order: 6
---

# Design
In questo capitolo verrà illustrato il design del sistema.

## Architettura generale
Il sistema è suddiviso in micro servizi:

- __Edge__: Si tratta del componente che manipola i sensori e gli attuatori all'interno degli ambienti della serra. In un ambiente possono esserci _n_ Edge;
- __Greenhouse Core__: Si tratta di un ambiente in cui degli agenti hanno un loro lifecycle, agiscono sugli Edge e contattano i Service qualora necessario.
- __Auth Service__: Si tratta del servizio di autenticazione, che permette di effettuare le operazioni di registrazione e login al sistema.
- __Settings Service__: Il servizio che consente di creare, modificare o eliminare determinate impostazioni utilizzate all'interno di Grennhouse Core, come ad esempio ogni quanto tempo campionare determinati tipi di dato.
- __Persistence Service__: Il servizio che permette di salvare e recuperare dati campionati.
- __Web Client__: Il servizio che offre possibilità ad un client di interagire con il sistema.

Greenhouse core deve necessariamente essere collocato nella stessa rete LAN in cui si trovano gli apparecchi di tipo Edge.

<div align="center">
<img src="https://images2.imgbox.com/c2/f8/8As4vvbQ_o.png" alt="System Architecture">
<p align="center">Architettura del Sistema</p>
</div>
