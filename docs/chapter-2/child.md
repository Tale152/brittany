---
title: Auth service - API
parent: Chapter 2
nav_order: 1
---

# Auth service - API

## Organization

### **GET** /organization/**create**
&emsp;Parametri query:
* organizationName
* name
* surname
* mail
* birthdate
* password

&emsp;Risultato atteso: **201**
* token

### **POST** /organization/**info**
&emsp;Header richiesti:
* token

&emsp;Risultato atteso: **200**
* name
---
## Farmer

### **GET** /farmer/**login**
&emsp;Parametri query:
* mail
* password

&emsp;Risultato atteso: **200**
* token

### **GET** /farmer/**info**
&emsp;Header richiesti:
* token

&emsp;Parametri query:
* id

&emsp;Risultato atteso: **200**
* farmers

### **GET** /farmer/**list**
&emsp;Header richiesti:
* token

&emsp;Risultato atteso: **200**
* farmers

### **POST** /farmer/**register**
&emsp;Header richiesti:
* token

&emsp;Parametri query:
* name
* surname
* mail
* birthdate
* password

&emsp;Risultato atteso: **201**
* id
---
## Greenhouse

### **GET** /greenhouse/**list**
&emsp;Header richiesti:
* token

&emsp;Risultato atteso: **200**
* greenhouses

### **POST** /greenhouse/**create**
&emsp;Header richiesti:
* token

&emsp;Parametri query:
* name

&emsp;Risultato atteso: **201**
* id
---
## Environment

### **GET** /environment/**list**
&emsp;Header richiesti:
* token

&emsp;Parametri query:
* id

&emsp;Risultato atteso: **200**
* environments

### **GET** /environment/**info**
&emsp;Header richiesti:
* token

&emsp;Parametri query:
* id

&emsp;Risultato atteso: **200**
* id_greenhouse
* name

### **POST** /environment/**create**
&emsp;Header richiesti:
* token

&emsp;Parametri query:
* name
* password
* greenhouseId

&emsp;Risultato atteso: **201**
* id
---
## Agent

### **GET** /agent/**login**
&emsp;Parametri query:
* organizationName
* greenhouseName
* environmentName
* environmentPassword

&emsp;Risultato atteso: **200**
* token