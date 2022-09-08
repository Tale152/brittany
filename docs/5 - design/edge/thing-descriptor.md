---
title: Thing Descriptor
parent: Edge
grand_parent: Design
nav_order: 3
---

# Thing Descriptor

Fondamentale è stata la creazione dei Thing Descriptor.  
Un Thing Descriptor (TD, o W3C WoT Thing Descriptor) è un modello di rappresentazione royalty-free basato sul linguaggio JSON ed utilizzato nell'Internet of Things (IoT).
Il TD fornisce un modo univoco per descrive un oggetto o un servizio, in funzione delle sue capacità, dei protocolli che usa, ed altri metadati.
Usare un Thing Descriptor semplifica notevolmente l'integrazione di dispositivi IoT all'interno di sistemi che ne fanno uso.

<div align="center">
<img src="https://upload.wikimedia.org/wikipedia/commons/e/e1/ThingDescription_Logo.png" alt="Thing Descriptor Logo" width="120" height="150">
<p align="center">Thing Descriptor Logo</p>
</div>

## Creazione del Thing Descriptor
La seguente è una configurazione hardware valida di un dispositivo edge che comanda due luci:

<div align="center">
<img src="https://images2.imgbox.com/30/61/jHL2Vsxd_o.png" alt="Thing Descriptor Logo" width="200" height="250">
<p align="center">Esempio di una configurazione hardware di Edge</p>
</div>

In questo caso Edge è composto da due componenti, una luce verde (denotiamo con G) e una luce rossa (denotiamo con R).
Sono state prese in considerazione più strategie per la gestione dei Thing Descriptor. Verranno ora illustrate le due modalità pensate. Non esistono motivi veramente determinanti per preferirne uno all'altro. I vantaggi e gli svantaggi dei due approcci non comportano cambiamenti radicali alle strutture delle applicazioni che fanno uso dei Thing Descriptor. La vera differenza nei due approcci

### Metodo scartato
Dato che Edge è composto da due componenti potrebbe essere logico pensare di avere più di un Thing Descriptor, in particolare tanti quanti sono i componenti. In questo caso quindi sono proprio i componenti ad assumere il ruolo di "Thing".  
I vantaggi di questo approccio sono:

- La creazione dei Thing Descriptor risulta più semplice e rapida;
- I Thing Descriptor risultano più piccoli e compatti;
- Le strutture dei Thing Descriptor seguono un certo template in base al tipo di componente, aumentando la possibilità di riuso.
  
Vi sono tuttavia anche dei difetti:

- Il numero dei Thing Descriptor cresce linearmente rispetto al numero dei componenti;
- Risulta più difficile capire in che modo si può manipolare un Edge, in quanto bisogna prendere in considerazione tutti i suoi Thing Descriptor;
- Necessaria una logica applicativa leggermente più complessa per gestire i Thing Descriptor una volta recuperati;
- Confusione su come ottenere in primo luogo i Thing Descriptor. Sono infatti possibili più soluzioni:
  - Effettuare una singola richiesta ed ottenere una collezione di Thing Descriptor;
  - Effettuare più richieste, una per ogni Thing Descriptor. 

### Metodo utilizzato

Ogni Edge possiede un solo ed unico Thing Descriptor che viene creato dinamicamente in base ai componenti posseduti. In questo caso quindi sono i dispositivi Edge ad assumere il ruolo di "Thing".  
I vantaggi sono i seguenti:

- Esiste un solo Thing Descriptor per ogni Edge, il quale è quindi legato anche ad un singolo IP univoco;
- La costruzione del Thing Descriptor non risulta molto più complessa. Infatti dato che un Edge è composto da moduli che sono a loro volta costituiti da componenti e operazioni, è possibile costruire il Thing Descriptor in maniera iterativa;
- Le indicazioni sui componenti e le operazioni sono tutte contenute in un singolo Thing Descriptor legato al relativo Edge. Risulta quindi estremamente più chiaro in che modo è possibile manipolare un Edge.

Gli svantaggi sono i seguenti:

- I Thing Descriptor contengono molte più informazioni e tendono a non essere facilmente leggibili;
- Necessario strutturare maggiormente il Thing Descriptor per poter recuperare tutte le informazioni necessarie.

Il componente che si occupa di costruire il TD si chiama _ThingDescriptorBuilder_.


## Descrizione della struttura del Thing Descriptor

Il Thing Descriptor non è altro che un oggetto Json in grado di supportare anche JSON-LD che utilizza però delle precise convenzioni, descritte approfonditamente sul sito di [W3](https://www.w3.org/TR/wot-thing-description/).
Viene qui riportato un breve sommario di come è stato strutturato il Thing Descriptor di Edge:

- **@context**: Il campo è necessario e serve a definire lo standard in uso.
- **id**: Il campo è obbligatorio e di tipo stringa. Un identificativo univoco viene assegnato a Edge, di base si tratta dell'indirizzo IP.
- **title**: Si tratta di una descrizione sommaria di ciò che può fare Edge. Deve essere human readable.
- **security**: specifica quale securityDefinition utilizzare.
- **securityDefinitions**: Vengono qui definiti i meccanismi di sicurezza che possono poi essere utilizzati in _security_.
- **modules**: Questo campo non è originariamente presente nelle specifiche del Thing Descriptor. Si tratta di un campo ulteriore che fornisce indicazioni su quali moduli sono presenti all'interno di Edge e quali componenti sono compresi in questi ultimi.
- **properties**: Contiene le interazioni che espongono lo stato di Edge, per esempio se una determinata luce è accesa oppure no.  
Ogni property è composta da:
  - **forms**: indicazioni su come effettuare la richiesta per ottenere un risultato.
  - **module**: Il nome modulo a cui appartiene la property. Questo campo non è presente da convenzione.
  - **type**: Il tipo del risultato.
- **actions**: Contiene le interazioni che permettono di effettuare operazioni sullo stato di Edge. Ogni action è composta da:
  - **forms**: indicazioni su come effettuare la richiesta per ottenere un risultato.
  - **module**: Il nome modulo a cui appartiene la action. Questo campo non è presente da convenzione.
  - **output**: Campo utilizzato per contenere a sua volta il tipo del risultati e altre informazioni sull'output.
  - **input**: Campo utilizzato per contenere informazioni sull'input.
### Esempio di Thing Descriptor

Segue un esempio di Thing Descriptor in grado di gestire attuatori che agiscono sulla temperatura e l'umidità dell'aria:

``` json
{
    "@context": "https://www.w3.org/2019/wot/td/v1",
    "id": "http://192.168.3.193:80",
    "title": "Mock Temperature Edge for handling temperature and humidity.",
    "security": [
        "no_sec"
    ],
    "securityDefinitions": {
        "no_sec": {
            "in": "header",
            "scheme": "nosec"
        }
    },
    "modules": [
        {
            "components": [
                "humidifier",
                "dehumidifier",
                "hum"
            ],
            "module": "airHumidity"
        },
        {
            "components": [
                "heater",
                "cooler",
                "temp"
            ],
            "module": "temperature"
        }
    ],
    "properties": {
        "airHumidity-hum": {
            "forms": [
                {
                    "contentType": "application/json",
                    "href": "http://192.168.3.193:80/airHumidity?id=hum"
                }
            ],
            "module": "airHumidity",
            "type": "number"
        },
        "isCoolOn-cooler": {
            "forms": [
                {
                    "contentType": "application/json",
                    "href": "http://192.168.3.193:80/isCoolOn?id=cooler"
                }
            ],
            "module": "temperature",
            "type": "boolean"
        },
        "isDehumidifyOn-dehumidifier": {
            "forms": [
                {
                    "contentType": "application/json",
                    "href": "http://192.168.3.193:80/isDehumidifyOn?id=dehumidifier"
                }
            ],
            "module": "airHumidity",
            "type": "boolean"
        },
        "isHeatOn-heater": {
            "forms": [
                {
                    "contentType": "application/json",
                    "href": "http://192.168.3.193:80/isHeatOn?id=heater"
                }
            ],
            "module": "temperature",
            "type": "boolean"
        },
        "isHumidifyOn-humidifier": {
            "forms": [
                {
                    "contentType": "application/json",
                    "href": "http://192.168.3.193:80/isHumidifyOn?id=humidifier"
                }
            ],
            "module": "airHumidity",
            "type": "boolean"
        },
        "temperature-temp": {
            "forms": [
                {
                    "contentType": "application/json",
                    "href": "http://192.168.3.193:80/temperature?id=temp"
                }
            ],
            "module": "temperature",
            "type": "number"
        }
    },
    "actions": {
        "coolOff-cooler": {
            "forms": [
                {
                    "contentType": "application/json",
                    "href": "http://192.168.3.193:80/coolOff?id=cooler"
                }
            ],
            "module": "temperature",
            "output": {
                "type": "string"
            }
        },
        "coolOn-cooler": {
            "forms": [
                {
                    "contentType": "application/json",
                    "href": "http://192.168.3.193:80/coolOn?id=cooler"
                }
            ],
            "module": "temperature",
            "output": {
                "type": "string"
            }
        },
        "dehumidifyOff-dehumidifier": {
            "forms": [
                {
                    "contentType": "application/json",
                    "href": "http://192.168.3.193:80/dehumidifyOff?id=dehumidifier"
                }
            ],
            "module": "airHumidity",
            "output": {
                "type": "string"
            }
        },
        "dehumidifyOn-dehumidifier": {
            "forms": [
                {
                    "contentType": "application/json",
                    "href": "http://192.168.3.193:80/dehumidifyOn?id=dehumidifier"
                }
            ],
            "module": "airHumidity",
            "output": {
                "type": "string"
            }
        },
        "heatOff-heater": {
            "forms": [
                {
                    "contentType": "application/json",
                    "href": "http://192.168.3.193:80/heatOff?id=heater"
                }
            ],
            "module": "temperature",
            "output": {
                "type": "string"
            }
        },
        "heatOn-heater": {
            "forms": [
                {
                    "contentType": "application/json",
                    "href": "http://192.168.3.193:80/heatOn?id=heater"
                }
            ],
            "module": "temperature",
            "output": {
                "type": "string"
            }
        },
        "humidifyOff-humidifier": {
            "forms": [
                {
                    "contentType": "application/json",
                    "href": "http://192.168.3.193:80/humidifyOff?id=humidifier"
                }
            ],
            "module": "airHumidity",
            "output": {
                "type": "string"
            }
        },
        "humidifyOn-humidifier": {
            "forms": [
                {
                    "contentType": "application/json",
                    "href": "http://192.168.3.193:80/humidifyOn?id=humidifier"
                }
            ],
            "module": "airHumidity",
            "output": {
                "type": "string"
            }
        }
    }
}
```
