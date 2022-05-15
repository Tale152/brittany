---
title: Greenhouse Core
parent: Design
has_children: true
---

# Greenhouse Core

Greenhouse Core è un microservizio il cui scopo è quello di controllare e gestire nei modi previsti gli ambienti della serra. Questo è reso possibile grazie alla struttura multi-agente sviluppata tramite l'utilizzo del framework __JaCaMo__.

Al fine di adempiere al suo scopo, Greenhouse Core deve comunicare con i __Service__:
- Auth Service viene contattato al fine di autenticarsi e ottenere un _token_ valido per la comunicazione con gli altri servizi;
- Settings Service è fondamentale per reperire eventuali configurazioni effettuate dall'utente, di modo che il sistema sia in grado di effettuare azioni che rispettino tali configurazioni;
- Persistence Service viene utilizzato per rendere persistenti i dati raccolti nel caso in cui le configurazioni del sistema lo rendano necessario.

Oltre alle comunicazioni con i Service appena descritte, questo microservizio deve anche mettersi in contatto con gli __Edge__. Questi componenti sono gli end point del sistema e si trovano nella stessa rete LAN di Greenhouse Core. Il sistema multi-agente si occuperà di cercare gli Edge mediante richieste HTTP, alla ricerca di componenti con i quali riesca a comunicare, ovvero che rispondano alla richiesta con un __Thing Descriptor__. Quest'ultimo permette a Greenhouse Core di comunicare con l'Edge e di sapere come invocare azioni compiute da attuatori o ad accedere a proprietà rilevate dai sensori.  

Le informazioni tratte dagli Edge vengono incrociate con le configurazioni richieste dall'agricoltore, permettendo al sistema di autogestirsi, performando azioni al fine di mantenere all'interno dell'ambiente fisico lo stato richiesto e di monitorare lo stato dei sensori, rendendo persistenti i dati quando variano sensibilmente.
