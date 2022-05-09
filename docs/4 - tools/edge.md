---
title: Edge
has_children: false
parent: Strumenti utilizzati
---

# Strumenti utilizzati - Edge

Verrano di seguito illustrati gli strumenti ed i framework utilizzati nel servizio di Edge del sistema.

## PlatformIO

Per programmare su schede Arduino si è soliti utilizzare il famoso IDE di Arduino, in quanto molto semplice da utilizzare, e adatto a principianti.
Le operazioni messe a disposizione sono però minime e spesso non sufficienti per utenti esperti.  
Esistono molti ambienti di sviluppo professionali che aggiungono numerose funzionalità, modalità di autocompletamento e tanto altro ancora.
Uno degli ambienti più diffusi è PlatformIO, sviluppato in Python.
PlatformIO favorisce notevolmente lo sviluppo di sistemi embedded in C/ C++.  
L’estensione è gratuita ed Open Source.
Il supporto alle schede è molto vasto e la semplicità di configurazione è uno dei punti forti dell'ambiente.

La creazione di un progetto è molto semplice ed è possibile tramite IDE o riga di comando.
Alla creazione di un progetto PlatformIO vengono create le cartelle per sorgenti, test, etc.
ed il file di configurazione ``platformio.ini`` che permette di configurare ogni aspetto del progetto.

Il file di configurazione è diviso in "ambienti". In questo modo è possibile creare diversi tipi di configurazione per lo stesso sistema, in modo da favorire il riuso del codice e molto altro.

<div align="center">
<img src="https://cdn.platformio.org/images/platformio-logo.17fdc3bc.png" width="200px" height="200px" alt="PlatformIO Logo">
<p align="center">Logo di PlatformIO</p>
</div>

## unity.h
Un'installazione di PlatformIO comprende anche una libreria base di tesing che è possibile includere e utilizzare nei sorgenti attraverso la classica direttiva ``#include <unity.h>``.
La libreria è piuttosto semplice:

1. Vengono create delle apposite funzioni di test.
2. Nel main, per ognuna di esse specifichiamo un comando ``RUN_TEST(func)``.

Le funzioni di test possono contenere un qualsiasi tipo di asset, ne esistono di diversi tipi in base al tipo di dato che si vuole verificare, ad esempio ``TEST_ASSERT_EQUAL_INT(expected, actual)`` è per i valori interi mentre ``TEST_ASSERT_TRUE(condition)`` serve a verificare se una condizione è vera. La lista esaustiva è consultabile nella [documentazione](https://docs.platformio.org/en/stable/plus/unit-testing.html).

## LCOV
PlatformIO non possiede un software o un plugin per verificare la coverage.
Nonostante esistano attualmente Pull Request aperte che ne richiedano l’aggiunta, non esistono quindi strumenti built-in che permettono di verificare la percentuale di codice attraversato dai test rispetto al totale della code base. È stato quindi utilizzato il tool LCOV.  

LCOV è un front-end grafico per il testing di ambienti che utilizzano il compilatore gcc. I dati generati da gcov, ovvero lo strumento di coverage effettivo, vengono collezionati, eventualmente filtrati ed infine presentati all'utente attraverso pagine HTML contenenti informazioni circa i sorgenti su cui sono state effettuate le verifiche.

Generalmente per il setup sono richiesti i seguenti step:

1. Aggiungere ``--coverage`` e i corretti linker flag (ad esempio CFLAGS and LDFLAGS) al comando di compilazione.
2. Collezionare i dati di coverage in un file:
   ```lcov --capture --directory project-dir --output-file coverage.info```
3. Generare il codice HTML:
    ```genhtml coverage.info --output-directory out```
