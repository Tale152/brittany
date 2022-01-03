---
title: API
parent: Persistence Service
grand_parent: Design
---

# Persistence Service - API

## Temperature

## &#9658; **<font color="green">POST</font>** /temperature/**register**
### **Header richiesti:**
* **token**  
<u>Agent token</u> ottenuto autenticandosi ad un Environment presso l'auth-service.

### **Parametri body:**
* **timestamp**  
Tipo: Data  
Formato: *"1997-12-31T00:00:00.000+00:00"*  
Obbligatorio: sì  
Data e orario del campionamento; la data e l'orario fanno riferimento all'<u>UTC</u> (Universal Time Coordinated).
* **value**  
Tipo: Numerico  
Obbligatorio: si  
Valore campionato.

### **Risultato atteso:** **201**
* **id**  
Identificativo del campionamento effettuato.

## &#9658; **<font color="blue">GET</font>** /temperature/**latest**
### **Header richiesti:**
* **token**  
<u>Farmer token</u> ottenuto autenticandosi con un account Farmer presso l'auth-service.

### **Risultato atteso:** **200**
* **timestamp**  
Data e orario del campionamento; la data e l'orario fanno riferimento all'<u>UTC</u> (Universal Time Coordinated).  
Formato: *"1997-12-31T00:00:00.000+00:00"* 

* **value**  
Valore campionato.

## &#9658; **<font color="blue">GET</font>** /temperature/**list**
### **Header richiesti:**
* **token**  
<u>Farmer token</u> ottenuto autenticandosi con un account Farmer presso l'auth-service.

### **Parametri query:**
* **id**  
Tipo: Stringa  
Obbligatorio: sì  
Id dell'Environment (ottenuto dall'auth-service) della quale si vuole ottenere la lista di campionamenti.

### **Risultato atteso:** **200**
* **list**  
Lista ordinata (dal più recente al più vecchio) di campionamenti della temperatura effettuati per il Setting specificato.

---

## Air Humidity

## &#9658; **<font color="green">POST</font>** /airHumidity/**register**
### **Header richiesti:**
* **token**  
<u>Agent token</u> ottenuto autenticandosi ad un Environment presso l'auth-service.

### **Parametri body:**
* **timestamp**  
Tipo: Data  
Formato: *"1997-12-31T00:00:00.000+00:00"*  
Obbligatorio: sì  
Data e orario del campionamento; la data e l'orario fanno riferimento all'<u>UTC</u> (Universal Time Coordinated).
* **value**  
Tipo: Numerico  
Obbligatorio: si  
Valore campionato.

### **Risultato atteso:** **201**
* **id**  
Identificativo del campionamento effettuato.

## &#9658; **<font color="blue">GET</font>** /airHumidity/**latest**
### **Header richiesti:**
* **token**  
<u>Farmer token</u> ottenuto autenticandosi con un account Farmer presso l'auth-service.

### **Risultato atteso:** **200**
* **timestamp**  
Data e orario del campionamento; la data e l'orario fanno riferimento all'<u>UTC</u> (Universal Time Coordinated).  
Formato: *"1997-12-31T00:00:00.000+00:00"* 

* **value**  
Valore campionato.

## &#9658; **<font color="blue">GET</font>** /airHumidity/**list**
### **Header richiesti:**
* **token**  
<u>Farmer token</u> ottenuto autenticandosi con un account Farmer presso l'auth-service.

### **Parametri query:**
* **id**  
Tipo: Stringa  
Obbligatorio: sì  
Id dell'Environment (ottenuto dall'auth-service) della quale si vuole ottenere la lista di campionamenti.

### **Risultato atteso:** **200**
* **list**  
Lista ordinata (dal più recente al più vecchio) di campionamenti dell'umidità dell'aria effettuati per il Setting specificato.
