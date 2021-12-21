---
title: API
parent: Auth Service
grand_parent: Design
---

# Auth Service - API

### **GET** /organization/**create**
Parametri query:
* organizationName
* name
* surname
* mail
* birthdate
* password

Risultato atteso: **201**
* token

### **POST** /organization/**info**
Header richiesti:
* token

Risultato atteso: **200**
* name
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