---
title: Version Control
parent: Documentazione DevOps
has_children: false
---

# Version Control

## Git Workflow

Il Workflow di git è stato suddiviso a sua volta per sottoprogetti.
Lo sviluppo indipendente di ogni sottoprogetto avviene infatti sul branch corrispondente.
Il branch ``develop`` viene utilizzato per la sincronizzazione e l'integrazione di funzionalità tra sottoprogetti. 
Il branch ``base_subproject_template`` viene utilizzato per effettuare modifiche ad ogni sottoprogetto. Si tratta infatti del branch da cui tutti i branch dei sottoprogetti originano.  
Il branch ``master`` viene utilizzato quando il codice raggiunge uno stato in cui può essere efftuata una release.
Il branch ``docs`` infine viene utilizzato per  mantenere la documentazione.
Da ciascun branch dei sottoprogetti possono ovviamente partire ulteriori branch di feature.
Segue l'elenco con descrizione dei branch utilizzati:

- __docs__: il branch orfano dedicato alla stesura della documentazione. Viene utilizzato anche da GitHub per creare l'ambiente di GitHub Pages.
- __master__: il branch che mantiene la storia del progetto, dedicato principalmente al codice sorgente del software in release.
- __develop__: il branch in cui sono presenti tutti i sottoprogetti. I sotto branch effettuano operazioni di merge su questo branch quando è necessario integrare qualcosa.
- __base_subproject_template__: il branch da cui originano tutti i branch di ogni sottoprogetto. Modifiche che devono essere apportate ad ogni sottoprogetto possono essere introdotte in questo branch.
- __greenhouse-core__: il branch utilizzato per lo sviluppo del sottoprogetto ```greengouse_core```.
- __edge__: il branch utilizzato per lo sviluppo del sottoprogetto ```edge```.
- __auth-service__: il branch utilizzato per lo sviluppo del sottoprogetto ```auth-service```.
- __persistence-service__: il branch utilizzato per lo sviluppo del sottoprogetto ```persistence-service```.
- __settings-service__: il branch utilizzato per lo sviluppo del sottoprogetto ```settings-service```.

<div align="center">
<img src="https://images2.imgbox.com/6f/e5/PPF85aMo_o.png" alt="Git Workflow">
<p align="center">Git Worflow</p>
</div>