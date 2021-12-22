---
title: API
parent: Settings Service
grand_parent: Design
---

# Settings Service - API

## Settings

## &#9658; **<font color="green">POST</font>** /settings/**create**
### **Header richiesti:**
* **token**  
<u>Farmer token</u> ottenuto autenticandosi con un account Farmer presso l'auth-service.

### **Parametri body:**
* **idEnvironment**  
Tipo: Stringa  
Obbligatorio: sì  
Id dell'Environment (ottenuto dall'auth-service) della quale si vogliono creare i Settings.
* **expires**  
Tipo: Data  
Formato: *"1997-12-31T00:00:00.000+00:00"*  
Obbligatorio: sì  
Data in cui i Settings non saranno più validi; la data e l'orario fanno riferimento all'<u>UTC</u> (Universal Time Coordinated) e devono necessariamente essere successivi al momento della creazione dei Settings.
* **temperature**  
Tipo: Oggetto  
Obbligatorio: no  
Settings riguardanti la gestione della temperatura; l'oggetto sarà composto obbligatoriamente da *min* e *max* (entrambi numerici), vincolando min ad essere necessariamente minore o uguale di max.
* **airHumidity**  
Tipo: Oggetto  
Obbligatorio: no  
Settings riguardanti la gestione dell'umidità dell'aria; l'oggetto sarà composto obbligatoriamente da *min* e *max* (entrambi numerici), vincolando min ad essere necessariamente minore o uguale di max.
* **light**  
Tipo: Oggetto  
Obbligatorio: no  
Settings riguardanti la gestione dell'illuminazione nell'Environment; l'oggetto sarà composto obbligatoriamente da 4 cambi numerici: fromH, fromM, toH, toM. La prima coppia rappresenta l'orario di accensione delle luci mentre la seconda l'orario di spegnimento. I campi "H" dovranno essere compresi tra 0 e 23 mentre i campi "M" tra 0 e 59.

### **Risultato atteso:** **201**
* **id**  
Identificativo dei nuovi Settings creati.

## &#9658; **<font color="green">POST</font>** /settings/**latestActiveState**
### **Header richiesti:**
* **token**  
<u>Farmer token</u> ottenuto autenticandosi con un account Farmer presso l'auth-service.

### **Parametri body:**
* **idEnvironment**  
Tipo: Stringa  
Obbligatorio: sì  
Id dell'Environment (ottenuto dall'auth-service) della quale si vuole ottenere il Setting più recente per cambiarne lo stato.
* **active**  
Tipo: Booleano    
Obbligatorio: sì  
Mentre i Settings datati vengono considerati automaticamente non più attivi, il Setting più recente (quindi quello corrente) può essere reso non attivo attraverso questo flag (un Setting può anche scadere se viene raggiunto l'expire, indipendentemente da questo flag).

### **Risultato atteso:** **201**
* **_id**  
Id univoco del Setting più recente per l'Environment specificato dall'Agent token. 
* **created**  
Data di creazione del Setting.  
Formato: *"1997-12-31T00:00:00.000+00:00"*
* **expires**  
Data di scadenza del Setting.  
Formato: *"1997-12-31T00:00:00.000+00:00"*
* **active**  
Stato attuale del Setting.
* **data**  
Impostazioni del Setting. Questo campo potrebbe non esistere se nessun setting è stato specificato. Opzionalmente possono essere presenti al suo interno: *temperature*, *airHumidity*, *light* (vedi POST /settings/create per composizione di questi campi).

## &#9658; **<font color="blue">GET</font>** /settings/**list**
### **Header richiesti:**
* **token**  
<u>Farmer token</u> ottenuto autenticandosi con un account Farmer presso l'auth-service.

### **Parametri query:**
* **id**  
Tipo: Stringa  
Obbligatorio: sì  
Id dell'Environment (ottenuto dall'auth-service) della quale si vuole ottenere la lista di tutti i Settings creati.

### **Risultato atteso:** **200**
* **settings**  
Lista ordinata (per data di creazione, dal più recente al più vecchio) contenente i Setting creati per l'Environment specificato.

## &#9658; **<font color="blue">GET</font>** /settings/**latest**
### **Header richiesti:**
* **token**  
<u>Agent token</u> ottenuto autenticandosi ad un Environment presso l'auth-service.

### **Risultato atteso:** **200**
* **_id**  
Id univoco del Setting più recente per l'Environment specificato dall'Agent token. 
* **created**  
Data di creazione del Setting.  
Formato: *"1997-12-31T00:00:00.000+00:00"*
* **expires**  
Data di scadenza del Setting.  
Formato: *"1997-12-31T00:00:00.000+00:00"*
* **active**  
Stato attuale del Setting.
* **data**  
Impostazioni del Setting. Questo campo potrebbe non esistere se nessun setting è stato specificato. Opzionalmente possono essere presenti al suo interno: *temperature*, *airHumidity*, *light* (vedi POST /settings/create per composizione di questi campi).
