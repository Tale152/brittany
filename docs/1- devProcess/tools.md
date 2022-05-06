---
title: Strumenti di supporto utilizzati
parent: Processo di Sviluppo
has_children: false
---

# Strumenti di supporto utilizzati

Per semplificare la fase di sviluppo sono stati utilizzati diversi strumenti utili.

## Trello

Trello è uno strumento online per la gestione di progetti e di task, estremamente utile per organizzare il lavoro tra più membri dello stesso team.

Il software permette di costruire in modo molto personalizzabile una board, ovvero una lavagna sulla quale si possono segnare task e assegnarli a uno o più collaboratori. Inoltre ogni task aggiunto può essere contrassegnato da una o più label, di modo da rendere immediatamente chiaro quali sono i task con maggiore priorità e a quale ambito del progetto fanno riferimento.

Essendo molto versatile, Trello è ideale per creare un ambiente su misura per applicare anche una metodologia di lavoro agile.

<div align="center">
<img src="https://loghi-famosi.com/wp-content/uploads/2021/03/Trello-Logo.png" width="300px" height="150px" alt="Trello Logo">
<p align="center">Logo di Trello</p>
</div>

## Discord
Si è utilizzato il software Discord per effettuare chiamate e lavorare anche a distanza.
Si è preferito questo strumento, rispetto ad altri simili quali Zoom, Google Meet o altri, per vari motivi:
- per la buona qualità di videochiamata e dello streaming video;
- per la possibilità di lavorare in stanze differenti in contemporanea, e passare
agevolmente da una stanza all’altra;
- per la possibilità di implementare hook integrati con GitHub, tali per cui ogni modifica alle repository di progetto viene notificata a tutti i componenti del gruppo, tramite un apposito canale testuale.

<div align="center">
<img src="https://loghi-famosi.com/wp-content/uploads/2021/02/Discord-Logo.png" width="190px" height="110px" alt="Discord Logo">
<p align="center">Logo di Discord</p>
</div>

## GenMyModel

GenMyModel è un serivizo online per la creazione di diagrammi utili a modellare arcitetture software.
In particolare dispone della possibilità di creare diagrammi UML gratuitamente.  
È inoltre possibile a partire da un diagramma generare i relativi sorgenti una volta specificato un linguaggio di programmazione.

<div align="center">
<img src="https://aranega.github.io/files/COMMITMDE16/imgs/gmm-logo.svg" width="300px" alt="GenMyModel Logo">
<p align="center">Logo di GenMyModel</p>
</div>

## Github Pages
La documentazione del progetto è mantenuta tramite un processo di continuous integration grazie ad una feature proposta da GitHub: _GitHub Pages_.
GitHub Pages fornisce un modo per automatizzare la pubblicazione di pagine web da semplice testo scritto in markdown a un linguaggio human-readable. La documentazione è mantenuta su un branch orfano denominato "/docs".

## Heroku 
Heroku è una platform as a service sul cloud che supporta diversi linguaggi di programmazione. In questo progetto è stata utilizzata come piattaforma per effettuare il deploy di alcuni servizi.  
Heroku offre infatti la possibilità di hostare un'applicazione gratuitamente se quest'ultima non viene utilizzata per fini commerciali.  

Vi sono servizi aggiuntivi applicando un piano tariffario a pagamento, ma nella versione gratuita l'applicazione di cui è stato effettuato il deployment verrà posta in esecuzione solo qualora vi sia del traffico rivolto verso quest'ultima; dopo un certo periodo di inattività, difatti, l'esecuzione del container verrà bloccata per essere nuovamente lanciata qualora vi sia nuovamente del traffico in entrata.  

Tramite l'interfaccia web è possibile regolare alcuni parametri come le variabili d'ambiente, fondamentali per differenziare un'esecuzione del servizio durante il development o in produzione.

<div align="center">
<img src="https://upload.wikimedia.org/wikipedia/commons/e/ec/Heroku_logo.svg" width="300px" alt="Heroku Logo">
<p align="center">Logo di Heroku</p>
</div>

## MongoDB Atlas
MongoDB Atlas è un Database-as-a-Service (DBaaS) il cui servizio permette il set up e deployment di un database in modo facile e scalabile, demandando al provider del cloud la gestione di hardware, update e configurazioni per le performance.  
Questo servizio funge dunque da intermediario per un deployment semplificato verso alcuni provider quali AWS , Azure, e GCP.  

La tier gratuita di questo servizio offre un solo cluster per progetto, con RAM condivisa e 512MB di storage (oltre che assenza di backup), ma risulta comunque un ottimo banco di prova iniziale per un progetto (specialmente data l'assenza di un limite temporale nell'usufruire di questo servizio).

<div align="center">
<img src="https://webassets.mongodb.com/_com_assets/cms/mongodb_logo1-76twgcu2dm.png" width="300px" alt="MongoDB Logo">
<p align="center">Logo di MongoDB</p>
</div>
