---
title: Testing
parent: Edge
grand_parent: Design
nav_order: 4
---

# Testing

## Modalità di Testing

L’utilizzo di test si è rivelato fondamentale per la corretta realizzazione di Edge, in quanto ha permesso di ridurre notevolmente il tempo di sviluppo.
Si è cercato di scrivere test che premettessero di garantire la qualità del sistema realizzato e che fossero anche utilizzabili anche come documentazione dello stesso.

### Test Automatizzati
Per quanto riguarda il testing automatizzato si è cercato si seguire un approccio quanto più possibile TDD (Test Driven Development), cercando di seguire il ciclo Red - Green - Refactor.
La natura dell'applicativo ed una corretta divisione dei compiti ha permesso di mantenere questo approccio fino alla fine della creazione dell'architettura.

Come già anticipato, esistono due cartelle di test:

- _brittany_: Viene testato principlamente il funzionamento dell'architettura utilizzando componenti di mock.
- _brittany-concrete_: Vengono testati i componenti fisici, serve necessariamente il chip hw per far funzionare questi test.

Per effettuare il testing di Edge è stata utilizzata la libreria ``unity.h`` già inclusa in PlatformIO.

### Testing non automatizzato

Non sono stati realizzati dei test esaustivi sul funzionamento della comunicazione tra client e server in quanto particolarmente tediosi da realizzare.  
La difficoltà è stata più legata al fatto che un test di questo tipo richiederebbe costantemente l'uso di un ESP8266, rendendo più difficile anche la creazione di una pipeline efficiente ed esaustiva all'interno delle GitHub Actions.  
Inoltre, la maggior parte di questi test si sarebbe incentrata sulla formattazione di parametri e risposte. Molti di questi elementi sono già stati testati nelle classi di OperationHandler.  
Per questo motivo le interazioni tra client e server sono state testate utilizzando il tool Postman.

## Coverage

#### lcov
PlatformIO non possiede un software o un plugin per veirificare la coverage.  
Nonostante esistano attualmente [Pull Request](https://github.com/platformio/platformio-core/issues/882) aperte che ne richiedano l'aggiunta, non esistono quindi strumenti built-in che permettono di verificare la percentuale di codice attraversato dai test rispetto al totale della code base.  
È tuttavia possibile effettuare queste verifiche attraverso il tool ``lcov``.  
Aggiungengo i due flag ``-lgcov`` e ``--coverage`` durante il processo di build (attraverso il file ``platformio.ini``) e creando un ulteriore extra script Python verranno generati diversi file utili a capire in quali righe di codice i test non sono sicuramente passati.  
L'interfaccia generata è in formato HTML e navigabile con un qualsiasi browser web.

<div align="center">
<img src="https://images2.imgbox.com/92/51/DYu7h56z_o.png" alt="lcov">
<p align="center"> Esempio di risultati del strumento di Coverage - LCOV </p>
</div>
