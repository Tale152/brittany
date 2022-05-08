---
title: Sviluppi futuri
parent: Conclusioni
has_children: false
---

# Sviluppi Futuri

Brittany è un sistema che si presta facilmente ad essere esteso; quest'ultima caratteristica è ottenuta grazie all'architettura pensata proprio per poter effettuare aggiunte in modo semplice e veloce.  

Verranno ora illustrate alcune idee che illustrano ciò che potrebbe essere aggiunto:

## Auth, Persistence, Settings Service

I servizi offerti da Brittany possono sempre essere espansi per offrire più personalizzazione, soprattutto per quanto concerne le configurazioni.  

Il sistema di autenticazione e di gestione utenti potrebbe essere migliorato aggiungendo un sistema di ruoli e di divisione dei compiti.  

Anche il sistema di persistence potrebbe essere ampliato, lasciando scegliere all'utente la modalità in cui vorrebbe salvare i dati.  

Al fine di incrementare oltre la scalabilità, integrare una tecnologia come Kubernetes al fine di disporre, su necessità, di molteplici repliche dei server.

## Edge

Edge è uno dei sottoprogetti che più si presta all'ampliamento, soprattutto per quanto riguarda l'aggiunta di componenti fisici e di moduli.  

Al momento Brittany dispone solo di un sistema di gestione di temperatura e di illuminazione.
Alcuni esempi di componenti mancanti e che potranno sicuramente essere aggiunti sono:

- Irrigatori
- Sensori di movimento
- Sensori di umidità e temperatura del suolo
- Ventilazione
- Sensori per misurare la pressione dell'acqua
- Sensori per misurare la qualità dell'aria
- Luci analogiche, in cui sia possibile impostare parametri aggiuntivi come colore, intensità, ecc...
- Sensori di temperatura della pianta.

## Greenhouse Core

L'aggiunta di componenti a Edge richiede necessariamente la creazione di nuovi moduli software nel sottoprogetto Greenhouse Core, così che esso sia in grado di adoperare le potenzialità fornite dai nuovi edge.  

L'architettura di questo componente è già predisposta all'espansione, richiedendo semplicemente l'aggiunta di nuovi agenti che collaborino con quelli già esistenti.

### Web Client

In generale il Web Client subisce modifiche qualora vengano effettuate modifiche anche negli altri sottoprogetti. Si tratta della parte del sistema più passiva e dipendente dagli altri moduli.

È sempre possibile efftuare comunque dei miglioramenti:

1. Migliorando la user experience;
2. Estendendo il web client, creando versioni funzionananti anche per dispositivi mobili;
3. Aggiungere ulteriori grafici e/o semplificando la visualizzazione dei dati.


### Altro...
Brittany potrebbe essere esteso anche per funzionare come gestionale della serra, aggiungendo funzionalità che comprendano la documentazione dello stato di salute delle piante o che integrino sistemi già esistenti.