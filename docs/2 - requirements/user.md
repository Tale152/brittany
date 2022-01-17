---
title: Requisiti Utente
parent: Requisiti
has_children: false
nav_order: 2
---

# Requisiti Utente

I requisiti utente esprimono i bisogni degli utenti e descrivono quali sono le azioni che l’utente deve poter effettuare interagendo con il sistema.

Per dettagli sulla sessione di Knowledge Crunching è possibile consultare la relativa sezione all'interno del capitolo relativo al Domain Knowledge.

<div align="center">
<img src="https://images2.imgbox.com/00/ea/GOLMcx7m_o.png" alt="Use case">
<p align="center">Diagramma dei casi d'uso - Utilizzo del sistema</p>
</div>

### Descrizione dei casi d'uso

L'utente finale può registrarsi al portale. Una volta ottenute le credenziali potrà quindi effettuare l'accesso in un qualsiasi momento.
Il portale deve offrire la possibilità di creare una nuova serra e di poterla configurare aggiungendo o togliendo ambienti. Come verrà successivamente spiegato, le serre sono infatti composte da più ambienti configurabili.
Per ogni ambiente l'utente può specificare una determinata configurazione, ovvero impostare il valore desiderato per ciascun parametro.
Sarà poi il sistema che cercherà, in base agli attuatori di cui dispone, a cercare di portare i parametri reali al valore desiderato.
Oltre alla configurazione, l'utente può anche visionare i dati raccolti dal sistema.

Nel diagramma riportato viene anche illustrato un attore che rappresenta un agente, ovvero un entità che manipola gli attuatori in funzione della configurazione specificata dall'utente.