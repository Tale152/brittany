---
title: Interazione con i Services
parent: Services
grand_parent: Design
nav_order: 2
---

# Interazione con i Services

## Autenticazione
Seppur i service risultino indipendenti tra loro a livello di esecuzione e deployment, è necessario autenticarsi con successo all'interno dell'ecosistema per poter usufruire dei servizi offerti.  

In particolare, le entità che interagiscono con i servizi sono due: i Farmer (attraverso il Client) e gli Agent (attraverso Greenhouse Core); questi ultimi, una volta autenticati, ottengono rispettivamente un Farmer Token ed un Agent Token, generati utilizzando segreti diversi. Ne segue che un Farmer non potrà effettuare richieste dedicate esclusivamente ad un Agent e viceversa.  

Il servizio dedicato all'autenticazione (e dunque all'ottenimento dei Token) è Auth Service. Come è possibile vedere dalle prossime sezioni, dedicate alla descrizione dettagliata delle API di ogni servizio, i Token sono richiesti per ogni operazione eccetto quelle per effettuare il login o la registrazione.  

## Esempio di interazione
Nel seguente diagramma di sequenza è possibile vedere un'esempio in cui un Greenhouse Core Agent interagisce con i Services.

<div align="center">
<img src="https://images2.imgbox.com/30/96/hDNHen2t_o.png" alt="Diagramma di sequenza - Esempio di interazione con i Services">
<p align="center"> Diagramma di sequenza - Esempio di interazione con i Services </p>
</div>

L'Agent innanzitutto effettua una richiesta HTTP GET verso l'Auth Service presso l'API dedicata al login di un Agent; nel caso l'autenticazione sia completata con successo il Service restituisce un agentToken.  

A questo punto, l'Agent utilizza il suo Token per richiedere al Settings Service gli ultimi settings attivi collegati al suo Environment all'interno della Greenhouse (le informazioni per identificare il giusto Environment sono contenute nel Token, dunque inaccessibili all'Agent).  

Infine, l'Agent registra una nuova temperatura campionata attraverso una richiesta HTTP POST verso il Persistence Service, fornendo il dato campionato e il token di autenticazione.
