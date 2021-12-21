---
title: API
parent: Auth Service
grand_parent: Design
---

# Auth Service - API

### **POST** /organization/**create**
Parametri body:
* organizationName  
Tipo: Stringa  
Obbligatorio: sì  
Descrizione Nome *univoco* dell'Organization da creare.
* name  
Tipo: Stringa  
Obbligatorio: sì  
Nome del primo titolare di un account Farmer collegato all'Organization da creare.
* surname  
Tipo: Stringa  
Obbligatorio: sì  
Cognome del primo titolare di un account Farmer collegato all'Organization da creare.
* mail  
Tipo: Stringa  
Obbligatorio: sì  
Mail del primo titolare di un account Farmer collegato all'Organization da creare.
* birthdate  
Tipo: Data  
Formato: *"1997-12-31T00:00:00.000+00:00"*  
Obbligatorio: sì  
Mail del primo titolare di un account Farmer collegato all'Organization da creare.
* password  
Tipo: Stringa  
Obbligatorio: sì  
Password del primo titolare di un account Farmer collegato all'Organization da creare.

Risultato atteso: **201**
* token  
<u>Farmer token</u> ottenuto autenticandosi con il nuovo account Farmer creato.

### **GET** /organization/**info**
Header richiesti:
* token  
<u>Farmer token</u> ottenuto autenticandosi con un account Farmer.

Risultato atteso: **200**
* name  
Nome dell'Organization collegata all'account autenticato.
---

## Farmer

### **GET** /farmer/**login**
Parametri query:
* mail
* password

Risultato atteso: **200**
* token

### **GET** /farmer/**info**
Header richiesti:
* token

Parametri query:
* id

Risultato atteso: **200**
* farmers

### **GET** /farmer/**list**
Header richiesti:
* token

Risultato atteso: **200**
* farmers

### **POST** /farmer/**register**
Header richiesti:
* token

Parametri query:
* name
* surname
* mail
* birthdate
* password

Risultato atteso: **201**
* id
---

## Greenhouse

### **GET** /greenhouse/**list**
Header richiesti:
* token

Risultato atteso: **200**
* greenhouses

### **POST** /greenhouse/**create**
Header richiesti:
* token

Parametri query:
* name

Risultato atteso: **201**
* id
---

## Environment

### **GET** /environment/**list**
Header richiesti:
* token

Parametri query:
* id

Risultato atteso: **200**
* environments

### **GET** /environment/**info**
Header richiesti:
* token

Parametri query:
* id

Risultato atteso: **200**
* id_greenhouse
* name

### **POST** /environment/**create**
Header richiesti:
* token

Parametri query:
* name
* password
* greenhouseId

Risultato atteso: **201**
* id
---

## Agent

### **GET** /agent/**login**
Parametri query:
* organizationName
* greenhouseName
* environmentName
* environmentPassword

Risultato atteso: **200**
* token