---
title: API
parent: Auth Service
grand_parent: Design
---

# Auth Service - API

## Organization

## &#9658; **<font color="green">POST</font>** /organization/**create**
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

## &#9658; **<font color="blue">GET</font>** /organization/**info**
### **Header richiesti:**
* **token**  
<u>Farmer token</u> ottenuto autenticandosi con un account Farmer.

### **Risultato atteso:** **200**
* **name**  
Nome dell'Organization collegata all'account autenticato.

---

## Farmer

## &#9658; **<font color="green">POST</font>** /farmer/**register**
### **Header richiesti:**
* **token**  
<u>Farmer token</u> ottenuto autenticandosi con un account Farmer.

### **Parametri body:**
* **name**  
Tipo: Stringa  
Obbligatorio: sì  
Nome del titolare del nuovo account Farmer collegato all'Organization contenuta nel Farmer token.
* **surname**  
Tipo: Stringa  
Obbligatorio: sì  
Cognome del titolare del nuovo account Farmer collegato all'Organization contenuta nel Farmer token.
* **mail**  
Tipo: Stringa  
Obbligatorio: sì  
Mail del titolare del nuovo account Farmer collegato all'Organization contenuta nel Farmer token.
* **birthdate**  
Tipo: Data  
Formato: *"1997-12-31T00:00:00.000+00:00"*  
Obbligatorio: sì  
Mail del titolare del nuovo account Farmer collegato all'Organization contenuta nel Farmer token.
* **password**  
Tipo: Stringa  
Obbligatorio: sì  
Password del titolare del nuovo account Farmer collegato all'Organization contenuta nel Farmer token.

### **Risultato atteso:** **201**
* **id**  
Id univoco associato al nuovo account Farmer creato.

## &#9658; **<font color="blue">GET</font>** /farmer/**login**
### **Parametri query:**
* **mail**  
Tipo: Stringa  
Obbligatorio: sì  
Mail associata al Farmer account al quale si intende autenticarsi.
* **password**  
Tipo: Stringa  
Obbligatorio: sì  
Password associata al Farmer account al quale si intende autenticarsi.

### **Risultato atteso:** **200**
* **token**  
<u>Farmer token</u> ottenuto autenticandosi al Farmer account specificato.

## &#9658; **<font color="blue">GET</font>** /farmer/**list**
### **Header richiesti:**
* **token**  
<u>Farmer token</u> ottenuto autenticandosi con un account Farmer.

### **Risultato atteso:** **200**
* **farmers**  
Lista di Farmer associati all'Organization contenuta nel Farmer token.

## &#9658; **<font color="blue">GET</font>** /farmer/**info**
### **Header richiesti:**
* **token**  
<u>Farmer token</u> ottenuto autenticandosi al Farmer account specificato.

### **Parametri query:**
* **id**  
Tipo: Stringa  
Obbligatorio: sì  
Id del Farmer account della qualesi desidera ottenere le info.

### **Risultato atteso:** **200**
* **name**  
Nome del titolare del Farmer account richiesto.
* **surname**  
Cognome del titolare del Farmer account richiesto.
* **mail**   
Mail del titolare del Farmer account richiesto.
* **birthdate**  
Mail del titolare del Farmer account richiesto.

---

## Greenhouse

## &#9658; **<font color="green">POST</font>** /greenhouse/**create**
### **Header richiesti:**
* **token**  
<u>Farmer token</u> ottenuto autenticandosi al Farmer account specificato.

### **Parametri body:**
* **name**  
Nome, univoco all'interno dell'Organization specificata nel Farmer token, della nuova Greenhouse da creare.

### **Risultato atteso:** **201**
* **id**  
Id della Greenhouse creata.

## &#9658; **<font color="blue">GET</font>** /greenhouse/**list**
### **Header richiesti:**
* **token**  
<u>Farmer token</u> ottenuto autenticandosi al Farmer account specificato.

### **Risultato atteso:** **200**
* **greenhouses**  
Lista di Greenhouse associate all'Organization contenuta nel Farmer token.

---

## Environment

## &#9658; **<font color="green">POST</font>** /environment/**create**
### **Header richiesti:**
* **token**  
<u>Farmer token</u> ottenuto autenticandosi al Farmer account specificato.

### **Parametri body:**
* **name**  
Nome, univoco all'interno della Greenhouse, del nuovo Environment che si intende creare.
* **password**  
Password del nuovo Environment che si intende creare.
* **greenhouseId**  
Id della Greenhouse associata a questo Environment.

### **Risultato atteso:** **201**
* **id**  
Id del nuovo Environment creato.

## &#9658; **<font color="blue">GET</font>** /environment/**list**
### **Header richiesti:**
* **token**  
<u>Farmer token</u> ottenuto autenticandosi al Farmer account specificato.

### **Parametri query:**
* **id**  
Id della Greenhouse della quale si vuole ottenere la lista di Environment associati.

### **Risultato atteso:** **200**
* **environments**  
Lista di Environment associati alla Greenhouse specificata.

## &#9658; **<font color="blue">GET</font>** /environment/**info**
### **Header richiesti:**
* **token**  
<u>Farmer token</u> ottenuto autenticandosi al Farmer account specificato.

### **Parametri query:**
* **id**  
Id dell'Environment della quale si vogliono ottenere le info.

### **Risultato atteso:** **200**
* **id_greenhouse**  
Id della Greenhouse associata all'Environment specificato.
* **name**  
Nome dell'Environment specificato.

---

## Agent

## &#9658; **<font color="blue">GET</font>** /agent/**login**
### **Parametri query:**
* **organizationName**
* **greenhouseName**
* **environmentName**
* **environmentPassword**

### **Risultato atteso:** **200**
* **token**