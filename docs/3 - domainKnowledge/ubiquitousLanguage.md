---
title: Ubiquitous Language
parent: Domain Knowledge
has_children: false
---

# Ubiquitous Language

## Agricoltore
Persona proprietaria della [Serra](#serra) o collaboratore autorizzato.

## Pianta 
Unità vegetale contenuta all'interno di un [Ambiente](#ambiente) della [Serra](#serra).

## Ambiente
Sezione di una [Serra](#serra) che contiene più [Piante](#pianta). Una serra è composta da almeno un ambiente.

## Serra
Stabile suddiviso in [Ambienti](#ambiente) adibito alla coltivazione di [Piante](#pianta) che richiedano la stessa [Configurazione dell'ambiente](#configurazione-dellambiente).

## Famiglia
Uno dei livelli di classificazione scientifica utilizzato dalle [Piante](#pianta). Piante con caratteristiche simili vengono solitamente racchiuse all'interno della stessa famiglia.

## Ciclo vitale
L'insieme ordinato di tutte le [Fasi fenologiche](#fase-fenologica) di una [Pianta](#pianta) che costituisce il suo percorso di vita.

## Fase Fenologica
Stadio del [Ciclo vitale](#ciclo-vitale) delle [Piante](#pianta), associato ad una certa [Configurazione della pianta](#configurazione-della-pianta) e [dell'ambiente](#configurazione-dellambiente).

## Parametro 
Un valore impostato dall'[Agricoltore](#agricoltore) che il sistema utilizza per prendere decisioni su come comportarsi in modo autonomo.

## Configurazione
Insieme di [Parametri](#parametro) impostati dall'[Agricoltore](#agricoltore) validi durante una determinata [Fase Fenologica](#fase-fenologica). Si possono suddividere in [Configurazione della pianta](#configurazione-della-pianta) e [Configurazione dell'ambiente](#configurazione-dellambiente).

### Configurazione della Pianta
Sottoinsieme di [Parametri](#parametro) relativi alla singola [Pianta](#pianta) in una determinata [Fase fenologica](#fase-fenologica). Nello specifico i parametri da specificare possono essere:
- [Irrigazione](#irrigazione)
- [Umidità suolo](#umidità-suolo)
- [Temperatura Pianta](#temperatura-pianta)

### Irrigazione
Un [Parametro](#parametro) della [Configurazione della Pianta](#configurazione-della-pianta) volto alla regolazione della distribuzione dell'acqua ad una [Pianta](#pianta).

### Umidità suolo
Un [Parametro](#parametro) della [Configurazione della Pianta](#configurazione-della-pianta) che controlla la percentuale di umidità del suolo attraverso l'utilizzo di sensori.

### Temperatura Pianta
Un [Parametro](#parametro) della [Configurazione della Pianta](#configurazione-della-pianta) che controlla la temperatura interna della [Pianta](#pianta) attraverso l'utilizzo di sensori.
  
### Configurazione dell'Ambiente
Sottoinsieme di [Parametri](#parametro) relativi al singolo [Ambiente](#ambiente). Nello specifico i parametri da specificare possono essere:

- [Temperatura dell'aria](#temperatura-dellaria)
- [Umidità dell'aria](#umidità-dellaria)
- [Illuminazione artificiale](#illuminazione-artificiale)
- [Ventilazione](#ventilazione)
- [Composizione dell'aria](#composizione-dellaria)
- [Pressione dell'acqua](#pressione-dellacqua)
- [Sensori di movimento](#sensore-di-movimento)

### Temperatura dell'Aria
Un [Parametro](#parametro) della [Configurazione dell'Ambiente](#configurazione-dellambiente) che specifica i gradi centrigradi (C°) rilevati nell'aria all'interno dell'[Ambiente](#ambiente).
È campionata attraverso Sensori e modificata attraverso attuatori.
La temperatura dell'aria può essere regolata tramite un sistema di raffreddamento/riscaldamento.

### Umidità dell'Aria
Un [Parametro](#parametro) della [Configurazione dell'Ambiente](#configurazione-dellambiente) che specifica, attraverso sensoristica, la quantità di vapore acqueo presente nell'aria in percentuale all'interno dell'[Ambiente](#ambiente).
È campionata attraverso Sensori e modificata attraverso attuatori.

### Illuminazione Artificiale
Un [Parametro](#parametro) della [Configurazione dell'Ambiente](#configurazione-dellambiente) che permette di controllare:
- [Temperatura colore](#temperatura-colore)
- [Intensità](#intesità)
- [Tempo Diurno](#tempo-diurno)
- [Tempo Notturno](#tempo-notturno)
  
#### Temperatura colore
Una caratteristica controllabile dell'[Illuminazione Artificiale](#illuminazione-artificiale) associata ad una grandezza fisica che descrive la tonalità della luce.

#### Intensità
Una caratteristica controllabile dell'[Illuminazione Artificiale](#illuminazione-artificiale) associata alla potenza della luce.

#### Tempo Diurno
Una caratteristica controllabile dell'[Illuminazione Artificiale](#illuminazione-artificiale) che misura il quantitativo di minuti in cui l'illuminazione è accesa.

#### Tempo Notturno
Una caratteristica controllabile dell'[Illuminazione Artificiale](#illuminazione-artificiale) che misura il quantitativo di minuti in cui l'illuminazione è spenta.

### Ventilazione
Un [Parametro](#parametro) della [Configurazione dell'Ambiente](#configurazione-dellambiente) che permette di controllare se attivare il ricircolo dell'aria.

### Composizione dell'Aria
Un [Parametro](#parametro) della [Configurazione dell'Ambiente](#configurazione-dellambiente) che rileva la miscela di sostanze aeriformi. 

### Pressione dell'Acqua
Un [Parametro](#parametro) della [Configurazione dell'Ambiente](#configurazione-dellambiente) che rileva la pressione dell'acqua nei contenitori preposti all'[Irrigazione](#irrigazione).
Nel caso di rotture del sistema di [Irrigazione](#irrigazione) l'[Agricoltore](#agricoltore) può ricevere un [Warning](#warning).

### Sensore di movimento
Un [Parametro](#parametro) della [Configurazione dell'Ambiente](#configurazione-dellambiente) che specifica una sensibilità per intercettare movimenti significativi all'interno della [Serra](#serra). In caso di movimenti sospetti può essere inviata un [Warning](#warning) all'[Agricoltore](#agricoltore), e potrebbe essere richiesto una [Manutenzione Straordinaria](#manutenzione-straordinaria).

## Notifica
Un avviso per l'[Agricoltore](#agricoltore) che può essere di tipo:
- [Warning](#warning)
- [Reminder](#reminder)

### Warning
Una [Notifica](#notifica) che avvisa l'[Agricoltore](#agricoltore) di una circostanza insolita che potrebbe richiedere una [Manutenzione Straordinaria](#manutenzione-straordinaria).

### Reminder
Una [Notifica](#notifica) che ricorda all'[Agricoltore](#agricoltore) l'esigenza di una [Manutenzione Saltuaria](#manutenzione-saltuaria).

## Storico
Raccolta di dati persistenti che provengono dal campionamento effettuato dai sensori installati nella [Serra](#serra).

## Manutenzione
Operazione che richiede un intervento manuale da parte dell'[Agricoltore](#agricoltore).  
Si suddivide in:
- [Manutenzione Ordinaria](#manutenzione-ordinaria)
- [Manutenzione Saltuaria](#manutenzione-saltuaria)
- [Manutenzione Straordinaria](#manutenzione-straordinaria)

### Manutenzione Ordinaria
Una tipologia di [Manutenzione](#manutenzione) che viene eseguita a intervalli di tempo regolari.  
I tipi di interventi possibili sono:
- [Controllo visivo](#controllo-visivo)
- [Controllo ugelli](#controllo-ugelli)

#### Controllo visivo
Un tipo di [Manutenzione Ordinaria](#manutenzione-ordinaria) che prevende il controllo della condizione della [Pianta](#pianta) all'interno della [Serra](#serra) da parte dell'[Agricoltore](#agricoltore).

#### Controllo ugelli
Un tipo di [Manutenzione Ordinaria](#manutenzione-ordinaria) che prevende il controllo della condizione del sistema di irrigazione all'interno della [Serra](#serra) da parte dell'[Agricoltore](#agricoltore).

### Manutenzione Saltuaria 
Una tipologia di [Manutenzione](#manutenzione) che non ha un andamento o una periodicità costante.
I tipi di interventi possibili sono:
- [Potatura](#potatura)
- [Fertirrigazione](#fertirrigazione)
- [Travaso](#travaso)
- [Cambio terriccio](#cambio-terriccio)
- [Impollinazione](#impollinazione)

#### Potatura
Un tipo di [Manutenzione Saltuaria](#manutenzione-saltuaria) che prevede la rimozione di fogliame dalla [Pianta](#pianta) in eccesso qualora necessario.

#### Fertirrigazione
Un tipo di [Manutenzione Saltuaria](#manutenzione-saltuaria) che prevede l'aggiunta di fertilizzanti all'interno del sistema di [Irrigazione](#irrigazione).

#### Travaso
Un tipo di [Manutenzione Saltuaria](#manutenzione-saltuaria) che prevede lo spostamento in una nuova locazione della [Pianta](#pianta) all'interno della [Serra](#serra) da parte dell'[Agricoltore](#agricoltore).

#### Cambio terriccio
Un tipo di [Manutenzione Saltuaria](#manutenzione-saltuaria) che prevede la sostituzione del terriccio in cui si trova la [Pianta](#pianta) al fine di ripristinare le sostanze nutritive necessarie nel caso in cui si esauriscano.

#### Impollinazione
Un tipo di [Manutenzione Saltuaria](#manutenzione-saltuaria) che prevede l'impiego di varie metodologie volte alla riproduzione delle [Piante](#pianta).  
Le metodologie possibili sono:
- [Insetti Impollinatori](#insetti-impollinatori)
- [Impollinazione manuale](#impollinazione-manuale)

##### Insetti Impollinatori
Una metodologia di [Impollinazione](#impollinazione) che prevede l'impiego di appositi insetti per effettuare l'operazione di impollinazione.

##### Impollinazione manuale
Una metodologia di [Impollinazione](#impollinazione) in cui l'[Agricoltore](#agricoltore) si occupa manualmente di distribuire il polline all'interno degli [Ambienti](#ambiente) della [Serra](#serra).

### Manutenzione Straordinaria
Una tipologia di [Manutenzione](#manutenzione) che viene eseguita manualmente dell'[Agricoltore](#agricoltore) a seguito di un [Warning](#warning) inviato nel caso in cui il sistema non sia in grado di gestire il problema.  
I tipi di interventi possibili sono:
- [Trappole a feromoni](#trappole-a-fermoni)
- [Pesticidi](#pesticidi)
- [Guasti impianto](#guasti-impianto)

#### Trappole a feromoni
Un tipo di [Manutenzione Straordinaria](#manutenzione-straordinaria) in cui l'[Agricoltore](#agricoltore) posiziona negli [Ambienti](#ambiente) delle trappole al fine di evitare la proliferazione di insetti nocivi per la [Pianta](#pianta).

#### Pesticidi
Un tipo di [Manutenzione Straordinaria](#manutenzione-straordinaria) in cui l'[Agricoltore](#agricoltore) utilizza negli [Ambienti](#ambiente) dei prodotti al fine di evitare la proliferazione di insetti nocivi per la [Pianta](#pianta).

#### Guasti impianto
Un tipo di [Manutenzione Straordinaria](#manutenzione-straordinaria) in cui l'[Agricoltore](#agricoltore) interviene ripristinando il corretto funzionamento della strumentazione della [Serra](#serra).