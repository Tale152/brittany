---
title: Services
has_children: false
parent: Strumenti utilizzati
---

# Strumenti utilizzati - Services

In questo capitolo verranno descritti tutti gli strumenti e le tecnologie utilizzate per la costruzione dei services:
- Auth service
- Persistence Service
- Settings Service

## [Auth - Persistence - Settings] Services
### Node Packet Manager
Node.js è una runtime di JavaScript multipiattaforma per l’esecuzione di codice JavaScript, costruita
sul motore JavaScript V8 di Google Chrome.
Node.js dispone di una grande quantità di moduli scritti completamente in Javascript. Essendo il progetto
open source è inoltre possibile per gli sviluppatori aggiungere i propri moduli in modo da renderli disponibili pubblicamente.
Il gestore di pacchetti predefinito per l’ambiente di runtime JavaScript Node.js si chiama Node Package
Manager (npm). npm può essere richiamato tramite linea di comando usando la seguente sintassi:
```shell
npm <command> [args]
```
Il comando base per ottenere un pacchetto è:
```shell
npm install [packet_name]
```
Tutte le dipendenze e i conflitti vengono gestiti automaticamente.  

<div align="center">
<img src="https://upload.wikimedia.org/wikipedia/commons/d/db/Npm-logo.svg" width="150px" height="150px" alt="npm Logo">
<p align="center">Logo di npm</p>
</div>

### Node.js 
Come runtime JavaScript guidato da eventi asincroni, Node.js è progettato per creare applicazioni di rete scalabili; molte connessioni, difatti, possono essere gestite contemporaneamente.
Ad ogni connessione verrà invocata una callback, rendendo Node attivo solo al momento necessario.
Nonostante in questo progetto Node sia stato utilizzato per sviluppare dei server, è importante sottolineare che Node.js non è un web server, ma una piattaforma in grado di eseguire codice javascript lato server e, tramite apposite librerie, sviluppare per l’appunto un web server.

Node.js implementa un’architettura event-driven, facendo dunque affidamento su un event loop. Non
esiste alcuna chiamata per avviare il ciclo:
Node.js entra semplicemente nel ciclo degli eventi dopo aver eseguito lo script di input e, analogamente, esce dal ciclo di eventi quando non ci sono più callback da eseguire.  
Questo comportamento è simile a JavaScript in browser: il ciclo degli eventi è nascosto all’utente.  
Per natura dell’event loop, Node è single-threaded, ma è possibile, su neccessità, effettuare delle fork per sfruttare al meglio i core offerti dalla macchina creando nuovi thread.

<div align="center">
<img src="https://upload.wikimedia.org/wikipedia/commons/7/7e/Node.js_logo_2015.svg" width="300px" height="80px" alt="Node.js logo">
<p align="center">Logo di Node.js</p>
</div>

### MongoDB
MongoDB è un DBMS NoSQL, cioè non utilizza un meccanismo di persistenza relazionale come un tradizionale SQL.
Il modello NoSQL non è unico e può dunque utilizzare varie strutture dati per sostiturire le tabelle con
campi uniformi usate in SQL.
In particolare mongoDB utilizza un modello orientato al documento, dove le informazioni sono memorizzate in una struttura gerarchica ad albero ed un qualsiasi numero di campi con qualsiasi lunghezza può essere aggiunto. I campi a loro volta possono anche contenere pezzi multipli di dati.
I DBMS orientati al documento offrono alcuni vantaggi, specialmente in ambito web, rispetto ai tradizionali
RDBMS:
- Maggiore flessibilità dei dati, utile per avere meno rigidità in fase di sviluppo o, in generale, per scenari in cui i dati memorizzati non sono sempre uniformi.
- Facilità nella trasposizione in strutture dati javascript in quanto i JSON (i documenti utilizzati internamente in mongoDB e, ormai, standard de facto) trovano una corrispondenza uno a uno con esse.

D’altro canto è pur vero che una struttura meno rigida aumenta il rischio di duplicazione di dati ed inconsistenze; è dunque richiesta al progettista una maggiore cautela nella manipolazione di dati.

<div align="center">
<img src="https://nodejstutorial.it/images/mongodb-logo-rgb-j6w271g1xn.jpg/920" width="250px" height="80px" alt="MongoDB logo">
<p align="center">Logo di MongoDB</p>
</div>

### Mongoose

Mongoose è una libreria per Node.js che permette di creare degli Schema per rappresentare i dati da
archiviare nel sistema.  
Ogni Schema è associato ad una collezione nel Database di MongoDB.  
Mongoose viene utilizzato per la creazione del proprio model, è infatti possibile creare delle istanze dallo Schema attraverso delle Factory ed utilizzarli come dei semplici oggetti Javascript.
Oltre ad offrire metodi aggiuntivi già pronti per salvare i dati dentro il Database è possibile creare funzioni che sono oggetti appartenenti ad un relativo schema possono richiamare, rendendo la modellazione molto object-oriented.  
La creazione di uno schema di esempio per archiviare gattini su Mongoose avviene nel seguente modo:
```js
const kittySchema = new mongoose.Schema({
    name: String
});
```
Dopo aver creato uno Schema è necessario creare una costante che rappresenta il model e collegarlo alloSchema appena creato:
```js
const Kitten = mongoose.model('Kitten', kittySchema);
```
Ora è possibile creare dei nuovi gattini utilizzando una sintassi object oriented:
```js
let jojo = new Kitten({ name: 'JoJo' });
console.log(jojo.name); // 'JoJo'
```
È anche possibile creare funzioni da associare al model appena creato:
```js
kittySchema.methods.meow = function () {
const greeting = this.name
    ? "Meow name is " + this.name
    : "I don't have a name";
console.log(greeting);
jojo.meow(); // 'Meow name is JoJo'
```
Per salvare il gattino nella collezione basterà richiamare il metodo save().
Si consiglia di utilizzare i metodi then() e catch() per avere controllo sul risultato dell’operazione:
```js
jojo.save() //save jojo in the collection
.then() //do something when operation is completed
.catch() //do something if an error occurred
```

<div align="center">
<img src="https://miro.medium.com/max/1296/1*iDvsmUwzZQxJSKdL0xzwIA.png" width="300px" height="100px" alt="Mongoose logo">
<p align="center">Logo di Mongoose</p>
</div>

### Jest
Jest è uno dei principali framework per il testing in progetti JavaScript. Il punto forte di Jest è la facilità di utilizzo e, inoltre, i test possono essere parallelizzati per ottenere il massimo dell'efficienza.  

Con l'aggiunta dell'argomento --coverage, è possibile ottenere la coverage dei test all'interno del progetto.

Un semplice test può essere impostato nel seguente modo:
```js
describe('My work', () => {
  test('works', () => {
    expect(2).toEqual(2)
  })
})
```
É inoltre possibile, attraverso una semplice sintassi, esprimere del codice che debba essere eseguito in diversi momenti del testing:
```js
describe("Calculator tests", () => {
  var input1 = 0
  var input2 = 0
 
  beforeAll(() => {
    console.log("beforeAll called")
  })
 
  afterAll(() => {
    console.log("afterAll called")
  })

  beforeEach(() => {
    console.log("beforeEach called")
    input1 = 1
    input2 = 2
  })

  afterEach(() => {
    console.log("afterEach called")
  })
 
  test('adding 1 + 2 should return 3', () => {
    var result = mathOperations.sum(input1,input2)
    expect(result).toBe(3)
  })
})
```
<div align="center">
<img src="https://blog.kakaocdn.net/dn/ZUme7/btrkG2FCG22/VgVbdkjuGHgbqJA3MlScLK/img.png" width="300px" height="280px" alt="Jest logo">
<p align="center">Logo di Jest</p>
</div>

### SuperTest
SuperTest è una libreria Node.js volta al testing delle API. In combinazione con un qualsiasi altro framework di testing (come Jest), permette di eseguire una nuova istanza del server da testare per ogni test da condurre.  

In ogni test vengono eseguite programmaticamente delle chiamate HTTP da un client fittizio, andando a controllare che la risposta ricevuta sia coerente con il comportamento previsto.

```js
import request from 'supertest'
import server from '../app'

describe('Example root test', () => {
    it('should respond with 200', () => {
        return request(server)
            .get('/')
            .expect(200)
    })
})
```
