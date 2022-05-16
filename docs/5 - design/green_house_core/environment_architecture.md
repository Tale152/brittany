---
title: Architettura Environment
parent: Greenhouse Core
grand_parent: Design
nav_order: 2
has_children: true
---

# Architettura generale Environment
Prima di definire in che modo funzionano gli _Artefatti_ e in come sono stati organizzati in _Workspace_, è necessario chiarire che cosa sono e il motivo per cui sono elementi fondamentali per la creazione di un __MAS__ (Multi-Agent System).

JaCaMo si appoggia a __Cartago__ per la creazione degli artefatti. Cartago si basa su un meta modello chiamato _Agents & Artifacts_, utilizzato per la modellazione e il design di sistemi multiagente.  

Un __Artefatto__ è uno strumento messo a disposizione degli agenti, che viene creato dinamicamente, usato e manipolato dagli agenti, con lo scopo di fornire supporto per compiere le loro attività.  
Ogni artefatto deve estendere __Artifact__, che costituisce la classe messa a disposizione da Cartago. Inoltre è possibile (e suggerita), l'implementazione del metodo __init()__, che viene chiamato durante l'inizializzazione dell'artefatto.

Tramite Cartago è anche possible creare degli ambienti basati sugli artefatti, che prendono il nome di __Workspace__. Un agente può entrare all'interno di un Workspace e collaborare con gli altri agenti nello stesso ambiente per raggiungere il proprio scopo.  

Avendo definito l'importanza di questi due costrutti, ora è possibile discutere come sono stati suddivisi gli artefatti in diversi workspace e dello scopo specifico di ogni artefatto.