---
title: Interfaccia utente
parent: Web Client
grand_parent: Design
nav_order: 2
---

# Interfaccia utente
Segue ora una breve spiegazione delle schermate presentate nella User Interface di questo Web Client; l'interfaccia, essendo poco più che un prototipo, risulta alquanto spoglia, stampando a schermo solo le informazioni necessarie all'utente per interagire con il sistema.

## Login
La prima schermata che si presenta all'apertura dell'applicativo contine il form per il login.  

All'interno del form vi sono due textbox che permettono all'utente (già registrato nel sistema) di inserire email e password.  

Interagendo con il bottone login (o attraverso la pressione del tasto _Enter_ sulla tastiera), verrà effettuato un tentativo di login.  

Il secondo e ultimo bottone permette di accedere alla schermata per la registrazione all'interno del sistema.

<div align="center">
<img src="https://images2.imgbox.com/6a/18/vpiHibGz_o.png" alt="Login">
<p align="center"> Login </p>
</div>

## Registrazione
Questa schermata presenta un form con più campi rispetto alla schermata precedente; attraverso questo form è possibile registrare una nuova Organizzazione e, necessariamente, il primo Agricoltore collegato alla nuova Organizzazione.  

Difatti, creato il primo Agricoltore di un'Organizzazione, esso potrà (una volta autenticato) creare i nuovi Agricoltori collegati alla medesima Organizzazione.  

Attraverso il bottone _Register_ (o premendo il tasto _Enter_ della tastiera), verrà effettuato un tentativo di registrazione che, nel caso di successo, effettuerà anche il login.

Interagendo con il bottone _Login_ invece è possibile tornare alla schermata Login precedentemente descritta.

<div align="center">
<img src="https://images2.imgbox.com/f2/6b/fHz8zpCt_o.png" alt="Registrazione">
<p align="center"> Registrazione </p>
</div>

## Greenhouses
Effettuato il login (o la registrazione), ci si ritroverà nella schermata contenente la lista delle Greenhouse contenute all'interno dell'Organizzazione di appartenenza (nell'esempio sottostante vi è una sola Greenhouse denominata _Brittany_); interagendo con una Greenhouse si verrà portati alla schermata contenente gli Environment collegati a tale Greenhouse.  

Attraverso il bottone _Create new_, sarà possibile creare una nuova Greenhouse.  

Infine, il bottone _Go to Farmers_ permetterà di raggiungere la schermata contenente gli Agricoltori appartenenti all'Organizzazione.

<div align="center">
<img src="https://images2.imgbox.com/a6/2e/4OACbSFY_o.png" alt="Lista delle Greenhouse all'interno dell'Organizzazione">
<p align="center"> Lista delle Greenhouse all'interno dell'Organizzazione </p>
</div>

## Environments
In questa schermata, come anticipato nella schermata precedente, sono contenuti tutti gli Environment collegati ad una Greenhouse (nell'esempio sottostante vi è un solo Environment denominato _TestEnvironment_).  

Interagendo con un Environment si verrà portati alla pagina dei Settings specifici per quell'Environment mentre, al click su _Create new_, verrà stampato a schermo un form per la creazione di un nuovo Environment.

<div align="center">
<img src="https://images2.imgbox.com/bf/6a/a1wjv686_o.png" alt="Lista degli Environment all'interno di una Greenhouse">
<p align="center"> Lista degli Environment all'interno di una Greenhouse </p>
</div>

## Settings
In questa schermata sono elencati i Settings di un dato Environment.  

Nella sezione _Current_ si troveranno (se presenti) i Settings correntemente attivi per questo environment; nella sezione _Old_, invece, si troveranno i Settings precedentemente inseriti e non più validi (scaduti o sostituiti da nuovi Settings).  
Interagendo con il tasto _Create new_ si potranno creare nuovi Settings.  

In alto troviamo dei bottoni di navigazione. Il bottone _Back to Greenhouses_, una volta premuto, riporterà l'utente nella schermata contenente la lista di Greenhouse; il bottone _Go to Data_, invece, porterà l'utente nella schermata contenente i dati campionati all'interno dell'Environment.

<div align="center">
<img src="https://images2.imgbox.com/a5/98/NLwuYBYi_o.png" alt="Settings di un Environment">
<p align="center"> Settings di un Environment </p>
</div>

## Dati
In questa schermata saranno presentati dei grafici cartesiani raffiguranti i dati campionati all'interno dell'Environment da parte di Greenhouse Core; questa schermata effettuerà polling verso il Persistence Service, aggiornandosi di volta in volta con i nuovi dati disponibili.  
Nella schermata di esempio si possono vedere i grafici contenenti la Temperatura e l'umidità dell'aria.  

In cima possiamo trovare i bottoni di navigazione per tornare alla schermata di Settings dell'Environment (_Go to Settings_) e per tornare alla lista di Greenhouse (_Go to Greenhouses_).

<div align="center">
<img src="https://images2.imgbox.com/77/22/bkB34yGm_o.png" alt="Dati di un Environment">
<p align="center"> Dati di un Environment </p>
</div>

## Agricoltori
In questa schermata troviamo l'elenco di tutti gli Agricoltori registrati all'interno dell'Organizzazione.  

Interagendo con un Agricoltore sarà possibile visionare i suoi dettagli mentre, effettuando un click sul bottone _Create new_, sarà possibile registrare un nuovo Agricoltore all'interno dell'Organizzazione.  

Cliccando sul bottone _Back to Greenhouses_ si tornerà alla schermata contenente l'elenco delle Greenhouse registrate all'interno dell'Organizzazione.

<div align="center">
<img src="https://images2.imgbox.com/0d/dc/r1iHpmML_o.png" alt="Lista di Farmer all'interno dell'Organizzazione">
<p align="center"> Lista di Farmer all'interno dell'Organizzazione </p>
</div>
