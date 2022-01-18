---
title: Version Control
parent: Documentazione DevOps
has_children: false
---

# Version Control

## Git Workflow

- __docs__: il branch orfano dedicato alla stesura della documentazione. Viene utilizzato anche da GitHub per creare l'ambiente di GitHub Pages.
- __master__: il branch che mantiene la storia del progetto, dedicato principalmente al codice sorgente del software in release.
- __develop__: il branch in cui sono presenti tutti i sottoprogetti. I sotto branch effettuano operazioni di merge su questo branch quando è necessario integrare qualcosa.
- __greenhouse-core__: il branch utilizzato per lo sviluppo del sottoprogetto ```greengouse_core```.
- __edge__: il branch utilizzato per lo sviluppo del sottoprogetto ```edge```.
- __auth-service__: il branch utilizzato per lo sviluppo del sottoprogetto ```auth-service```.
- __persistence-service__: il branch utilizzato per lo sviluppo del sottoprogetto ```persistence-service```.
- __settings-service__: il branch utilizzato per lo sviluppo del sottoprogetto ```settings-service```.

<div align="center">
<img src="https://images2.imgbox.com/d8/90/9LDld0i1_o.png" alt="Git Workflow">
<p align="center">Git Worflow</p>
</div>