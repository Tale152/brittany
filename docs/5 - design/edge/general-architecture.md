---
title: Architettura Generale
parent: Edge
grand_parent: Design
nav_order: 2
---

# Architettura Generale

Ogni Edge è quello che nel Web Of Things viene definito Thing, ossia un oggetto che espone delle operazioni e che può essere manipolato attraverso chiamate API.  

## Edge
Nei seguenti diagrammi delle classi, il componente chiamato ``Edge`` è la classe centrale che può eseguire dei comandi, i quali vanno a recuperare informazioni o ad agire sullo stato dello stesso.

<div align="center">
<img src="https://images2.imgbox.com/d1/db/RTbTBRU6_o.png" alt="High-Level organizaiton">
<p align="center"> Diagramma delle classi - Edge</p>
</div>

Ogni ``Edge`` viene quindi utilizzato per la creazione di un ``WebServer`` REST. Le API disponibili sono variabili e dipendono dai componenti affidati all'Edge.

Per creare una API è necessario creare un ``OperationHandler``. Si tratta di una classe utile a descrivere un'operazione da eseguire ed ha quindi caratteristiche molto simili a quelle di una API Rest:
- un nome che descrive brevemente lo scopo dell'operazione.
- una route, ovvero un percorso a cui l'operazione è associata.
- un handler, ovvero l'effettiva funzione da eseguire se un OperationHandler viene evocato.

Gli ``OperationHandler`` sono contenuti all'interno di ``Module``.
Un ``Module`` non è altro che una raccolta di ``OperationHandler`` che agiscono sugli stessi componenti.

<div align="center">
<img src="https://images2.imgbox.com/ca/5d/42ZI1GTZ_o.png" alt="High-Level organizaiton">
<p align="center"> Diagramma di Sequenza - Edge</p>
</div>

Per effettuare una richiesta al ``WebServer``, il client esegue una normalissima HTTP Request. Il ``WebServer`` riceverà quindi la richiesta ed eseguirà la funzione _execute_, la quale itererà sui ``Module`` posseduti da ``Edge`` e contatterà l'``OperationHandler`` corretto che verrà quindi eseguito. Una volta ottenuto il risultato dalla computazione il risultato tornerà ad ``Edge`` e poi al ``WebServer``, il quale preparerà il risultato per la trasmissione e lo invierà come HTTP Response.

## ComponentHw
Dato che il linguaggio di programmazione di destinazione si conosceva già dalla fase di analisi, si è deciso di utilizzare un construtto presente.
Per la creazione di componenti fisici si è sfruttata infatti l'ereditarietà multipla, presente in C++.
La classe principale da cui deve estendere un componente hardware è ``ComponentHw``, che forza tutti i componenti ad avere almeno un ID di tipo stringa.  
Nel diagramma delle classi seguente viene illustrata la creazione di un componente per una luce di tipo digitale (che può assumere solo gli stati accesa e spenta).  
Ogni componente viene creato con modalità simili, dipendentemente dalle sue proprietà. L'ereditarietà multipla è un ottimo meccanismo per favorire il riuso di classi, in modo che componenti con le stesse caratteristiche siano più semplici e veloci da realizzare.

<details>
  <summary>Legenda package (click me!)</summary>

- <span style="background-color: #add8e6"> brittany</span>
- <span style="background-color: pink"> _brittany-concrete_ </span>
- <span style="background-color: #FFFF99">brittany-mock</span>
</details>

<div align="center">
<img src="https://images2.imgbox.com/a4/31/u51b9lwO_o.png" alt="High-Level organizaiton">
<p align="center"> Diagramma delle classi - ComponentHw</p>
</div>

Per comodità conviene sempre creare una classe di ``Template`` che verrà estesa dalle implementazioni effettive.
La classe di ``Mock`` viene utilizzata solamente a finalità di test, mentre la classe di implementazione effettiva viene utilizzata per manovrare il componente reale.

## Module
Un ``Module`` è una classe composta da più OperationHandler che hanno componenti in comune. Nel seguente diagramma è riportato un esempio di Modulo che utilizza il componente menzionato nella sezione precedente.

<details>
  <summary>Legenda package (click me!)</summary>

- <span style="background-color: #add8e6"> brittany</span>
- <span style="background-color: pink"> _brittany-concrete_ </span>
- <span style="background-color: #FFFF99">brittany-mock</span>
</details>

<div align="center">
<img src="https://images2.imgbox.com/72/1e/6WKzoirp_o.png" alt="High-Level organizaiton">
<p align="center"> Diagramma delle classi - Module</p>
</div>

``DigitalLightModule`` in questo caso è un modulo che contiene due ``OperationHandler`` che agiscono sugli stessi componenti di tipo ``DigitalLightHw``.
Oltre alle implementazioni effettive, anche in questo caso è possibile creare delle classi di Mock per testare il funzionamento dell'architettura. In questo caso è necessario che i componenti manovrabili siano a loro volta classi di Mock.

