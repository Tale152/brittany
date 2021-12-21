---
title: API
parent: Auth Service
grand_parent: Design
---

# Auth Service - API

## &#9658; <font color="green">**POST**</font> /organization/**create**
### **Parametri body:**
* **organizationName**  
Tipo: Stringa  
Obbligatorio: sì  
Descrizione Nome *univoco* dell'Organization da creare.
* **name**  
Tipo: Stringa  
Obbligatorio: sì  
Nome del primo titolare di un account Farmer collegato all'Organization da creare.
* **surname**  
Tipo: Stringa  
Obbligatorio: sì  
Cognome del primo titolare di un account Farmer collegato all'Organization da creare.
* **mail**  
Tipo: Stringa  
Obbligatorio: sì  
Mail del primo titolare di un account Farmer collegato all'Organization da creare.
* **birthdate**  
Tipo: Data  
Formato: *"1997-12-31T00:00:00.000+00:00"*  
Obbligatorio: sì  
Mail del primo titolare di un account Farmer collegato all'Organization da creare.
* **password**  
Tipo: Stringa  
Obbligatorio: sì  
Password del primo titolare di un account Farmer collegato all'Organization da creare.

### **Risultato atteso:** **201**
* **token**  
<u>Farmer token</u> ottenuto autenticandosi con il nuovo account Farmer creato.

## &#9658; <font color="blue">**GET**</font> /organization/**info**
### **Header richiesti:**
* **token**  
<u>Farmer token</u> ottenuto autenticandosi con un account Farmer.

### **Risultato atteso:** **200**
* **name**  
Nome dell'Organization collegata all'account autenticato.
---

## Farmer

## &#9658; <font color="blue">**GET**</font> /farmer/**login**
### **Parametri query:**
* mail
* password

### **Risultato atteso:** **200**
* token

## &#9658; <font color="blue">**GET**</font> /farmer/**info**
### **Header richiesti:**
* token

### **Parametri query:**
* id

### **Risultato atteso:** **200**
* farmers

## &#9658; <font color="blue">**GET**</font> /farmer/**list**
### **Header richiesti:**
* token

### **Risultato atteso:** **200**
* farmers

## &#9658; <font color="green">**POST**</font> /farmer/**register**
### **Header richiesti:**
* token

### **Parametri query:**
* name
* surname
* mail
* birthdate
* password

### **Risultato atteso:** **201**
* id
---

## Greenhouse

## &#9658; <font color="blue">**GET**</font> /greenhouse/**list**
### **Header richiesti:**
* token

### **Risultato atteso:** **200**
* greenhouses

## &#9658; <font color="green">**POST**</font> /greenhouse/**create**
### **Header richiesti:**
* token

### **Parametri query:**
* name

### **Risultato atteso:** **201**
* id
---

## Environment

## &#9658; <font color="blue">**GET**</font> /environment/**list**
### **Header richiesti:**
* token

### **Parametri query:**
* id

### **Risultato atteso:** **200**
* environments

## &#9658; <font color="blue">**GET**</font> /environment/**info**
### **Header richiesti:**
* token

### **Parametri query:**
* id

### **Risultato atteso:** **200**
* id_greenhouse
* name

## &#9658; <font color="green">**POST**</font> /environment/**create**
### **Header richiesti:**
* token

### **Parametri query:**
* name
* password
* greenhouseId

### **Risultato atteso:** **201**
* id
---

## Agent

## &#9658; <font color="blue">**GET**</font> /agent/**login**
### **Parametri query:**
* organizationName
* greenhouseName
* environmentName
* environmentPassword

### **Risultato atteso:** **200**
* token