---
title: Thing Descriptor
parent: Edge
grand_parent: Design
nav_order: 3
---

# Thing Descriptor

Fondamentale è stata la creazione dei Thing Descriptor.  
Un Thing Descriptor (TD, o W3C WoT Thing Descriptor) è un modello di rappresentazione royalty-free basato sul linguaggio JSON ed utilizzato nell Internet of Things (IoT).
Il TD fornisce un modo univoco per descrive un oggetto o un servizio, in funzione delle sue capacità, dei protocolli che usa, ed altri metadati.
Usare un Thing Descriptor semplifica notevolmente l'integrazione di dispositivi IoT all'interno di sistemi che ne fanno uso.

<div align="center">
<img src="https://upload.wikimedia.org/wikipedia/commons/e/e1/ThingDescription_Logo.png" alt="Thing Descriptor Logo" width="120" height="150">
<p align="center">Thing Descriptor Logo</p>
</div>

## Creazione del Thing Descriptor
La seguente è una configurazione hardware valida di un edge che comanda due luci:

<div align="center">
<img src="https://images2.imgbox.com/30/61/jHL2Vsxd_o.png" alt="Thing Descriptor Logo" width="200" height="250">
<p align="center">Esempio di una configurazione hardware di Edge</p>
</div>

In questo caso Edge è composto da due componenti, una luce verde (denotiamo con G) e una luce rossa (denotiamo con R).
Sono state prese in considerazione più strategie per la creazione dei Thing Descriptor. Verranno ora illustrate le due modalità pensate e le motivazioni che hanno spinto ad usarne una al posto dell'altra.

### Metodo scartato
Dato che Edge è composto da due componenti potrebbe essere logico pensare di avere più di un Thing Descriptor, di preciso tanti quanti sono i componenti. I vantaggi di questo approccio sono:
- semplicità e rapidità nella creazione del TD;
- alta possibilità di riuso;
  
Vi sono tuttavia anche dei difetti:
- il numero di TD e quindi di richiese cresce linearmente rispetto al numero dei componenti;
- organizzazione più difficile da mantenere.
- maggiore difficoltà nell'utilizzo di librerie per manipolare ed utilizzare il TD.
  
Si è quindi deciso di abbandonare questo approccio, in quanto i difetti che presentava sono risultati piuttosto critici.

### Metodo utilizzato

Ogni Edge possiede un Thing Descriptor che viene creato dinamicamente in funzione dei componenti che possiede.
In particolare, dato che un Edge è composto da Moduli che sono a loro volta costituiti da componenti e operazioni, è possibile costruire il Thing Descriptor mano a mano che vengono aggiunti moduli.
I vantaggi sono i seguenti:
- Con una sola richiesta è possibile sapere tutto 
Il componente che si occupa di costruire il TD si chiama _ThingDescriptorBuilder_.


## Descrizione della struttura del Thing Descriptor

Il Thing Descriptor non è altro che un oggetto Json in grado di supportare anche JSON-LD che utilizza però delle precise convenzioni, descritte approfonditamente sul sito di [W3](https://www.w3.org/TR/wot-thing-description/).
Viene qui riportato un breve sommario di come è stato strutturato il Thing Descriptor di Edge:

- _@context_: Il campo è necessario e serve a definire lo standard in uso.
- _id_: Il campo è obbligatorio e di tipo stringa. Un identificativo univoco viene assegnato a Edge, di base si tratta dell'indirizzo IP.
- _title_: Si tratta di una descrizione sommaria di ciò che può fare Edge. Deve essere human readable.
- _security_: specifica quale securityDefinition utilizzare.
- _securityDefinitions_: Vengono qui definiti i meccanismi di sicurezza che possono poi essere utilizzati in _security_.
- _modules_: Questo campo non è originariamente presente nelle specifiche del Thing Descriptor. Si tratta di un campo ulteriore che fornisce indicazioni su quali moduli sono presenti all'interno di Edge e quali componenti sono compresi in questi ultimi.
- _properties_: Contiene le interazioni che espongono lo stato di Edge, per esempio se una determinata luce è accesa oppure no.  
Ogni property è composta da:
  - _forms_: indicazioni su come effettuare la richiesta per ottenere un risultato.
  - _module_: Il nome modulo a cui appartiene la property. Questo campo non è presente da convenzione.
  - _type_: Il tipo del risultato.
- _actions_: Contiene le interazioni che permettono di effettuare operazioni sullo stato di Edge. Ogni action è composta da:
  - _forms_: indicazioni su come effettuare la richiesta per ottenere un risultato.
  - _module_: Il nome modulo a cui appartiene la action. Questo campo non è presente da convenzione.
  - _output_: Campo utilizzato per contenere a sua volta il tipo del risultati e altre informazioni sull'output.
  - _input_: Campo utilizzato per contenere informazioni sull'input.
### Esempio di Thing Descriptor

Il Thing Descriptor risultante sarebbe molto simile al seguente:
``` json
{
    "@context": "https://www.w3.org/2019/wot/td/v1",
    "id": "http://IP_ADDRESS:PORT",
    "title": "Mock Title",
    "security": ["no_sec"],
    "securityDefinitions": {
        "no_sec": {
            "in": "header",
            "scheme": "nosec"
        }
    },
    "modules": [{
        "components": ["G","R"],
        "module": "light"
    }],
    "properties": {
        "isOn-G": {
            "forms": [{
                "contentType": "application/json",
                "href": "http://IP_ADDRESS:PORT/isOn?id=G"
            }],
            "module": "light",
            "type": "boolean"
        },
        "isOn-R": {
            "forms": [{
                "contentType": "application/json",
                "href": "http://IP_ADDRESS:PORT/isOn?id=R"
            }],
            "module": "light",
            "type": "boolean"
        }
    },
    "actions": {
        "turnOff-G": {
            "forms": [{
                "contentType": "application/json",
                "href": "http://IP_ADDRESS:PORT/turnOff?id=G"
            }],
            "module": "light",
            "output": {"type": "string"}
        },
        "turnOff-R": {
            "forms": [{
                "contentType": "application/json",
                "href": "http://IP_ADDRESS:PORT/turnOff?id=R"
            }],
            "module": "light",
            "output": {"type": "string"}
        },
        "turnOn-G": {
            "forms": [{
                "contentType": "application/json",
                "href": "http://IP_ADDRESS:PORT/turnOn?id=G"
            }],
            "module": "light",
            "output": {"type": "string"}
        },
        "turnOn-R": {
            "forms": [{
                "contentType": "application/json",
                "href": "http://IP_ADDRESS:PORT/turnOn?id=R"
            }],
            "module": "light",
            "output": {"type": "string"}
        }
    }
}
```

