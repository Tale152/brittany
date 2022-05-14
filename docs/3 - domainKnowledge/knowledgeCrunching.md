---
title: Knowledge Crunching
parent: Domain Knowledge
has_children: false
nav_order: 1
---

# Knowledge Crunching

Prima ancora di mettere mano all’architettura di progetto, sono state effettuate sessioni di knowledge crunching che hanno visto la partecipazione di tutti i membri del team e di un esperto del dominio nell'ambito della botanica.  
Scopo di queste sessioni era lo studio del dominio applicativo, e la definizione di requisiti tali da guidare lo sviluppo in un’ottica DDD.

Obiettivo principale delle sessioni è stata la definizione dell'Ubiquitous Language e l'acquisizione di una maggiore competenenza in campo botanico.

Vengono di seguito illustrate alcune interazioni tra sviluppatori e l'esperto del dominio.  
È stata effettuata per praticità una divisione per tipologia di argomento affrontato.

## Dialoghi con esperto del dominio

<details>
<summary>
    Legenda (click me!)
</summary>

- <span style="background-color: #b6d7a8">Informazioni generali: teoria sul dominio della botanica</span>  
  
- <span style="background-color: pink"> Informazioni pratiche: Comportamenti da tenere nel dominio della botanica</span>  

- <span style="background-color: #ffe599"> Gestione di una serra - Funzionamento di un sistema non digitalizzato </span>  
  
- <span style="background-color: #add8e6"> Questioni relative all'implementazione</span>
</details>

#### Classificazione delle Piante

<span style="color:green;font-weight:bold">Developer</span>: "Esiste un sistema di classificazione per le piante?"  

<span style="color:#19ff19;font-weight:bold">Esperto</span>: "Certamente, in generale tutte le piante appartengono ad una _famiglia_. In generale se due piante appartengono alla stessa famiglia possiamo dire che hanno caratteristiche comuni."  

<span style="color:green;font-weight:bold">Developer</span>: "In che senso? Hanno un aspetto simile?"  

<span style="color:#19ff19;font-weight:bold">Esperto</span>: "Non solo, due piante appartenenti alla stessa famiglia avranno più o meno bisogno dello stesso tipo di trattamento per crescere. Anche se i parametri sono leggermente diversi tra le specie, non dovrebbero cambiare più di tanto."  

<span style="color:green;font-weight:bold">Developer</span>: "Interessante, ci sono suddivisioni ulteriori oltre alle famiglie?"  

<span style="color:#19ff19;font-weight:bold">Esperto</span>: "La famiglia è sicuramente la più importante, ed è anche sufficiente insieme al nome della specie."

---

#### Fasi Fenologiche

<span style="color:#19ff19;font-weight:bold">Esperto</span>: "Ci sono diverse fasi nel ciclo vitale di una pianta."  

<span style="color:green;font-weight:bold">Developer</span>: "È importante questa distinzione in fasi?"  

<span style="color:#19ff19;font-weight:bold">Esperto</span>: "Certo, ciò che richiede una pianta varia proprio in base alla fase in cui essa si trova. Per esempio in una fase iniziale spesso servono meno acqua e sostanze nutritive rispetto a quando è nel bel mezzo della sua fase di vegetazione."  

<span style="color:green;font-weight:bold">Developer</span>: "Le fasi in cui si può trovare una pianta sono sempre le stesse? O ci sono piante che hanno più fasi di altre?"  

<span style="color:#19ff19;font-weight:bold">Esperto</span>: "Alcune fasi ci sono in ogni tipo di pianta, come la germinazione, che è sempre la prima, ma il numero di fasi dipende dalla pianta. Anche perché ci sono piante che come noi umani nascono, crescono, producono e muoiono, altre che nelle condizioni giuste vivono praticamente in eterno. Questo tipo di piante si chiamano perenni."  

<span style="color:green;font-weight:bold">Developer</span>: "Come si capisce quando una pianta ha cambiato fase?"  

<span style="color:#19ff19;font-weight:bold">Esperto</span>: "Un agricoltore lo capisce quasi sempre semplicemente grazie all'impatto visivo."  

<span style="color:green;font-weight:bold">Developer</span>: "Queste fasi hanno un nome specifico o si chiamano semplicemente fasi?"  

<span style="color:#19ff19;font-weight:bold">Esperto</span>: "Il nome esteso è _fase fenologica_"

---

#### Bisogni primari
<span style="color:#FFA500;font-weight:bold">Developer</span>: "Cosa è fondamentale nell'impostazione di una serra? Quali sono i parametri importanti, le condizioni? Cos'è più importante? Cosa meno?"  

<span style="color:#E6BF83;font-weight:bold">Esperto</span>: "I parametri più importanti? Dunque, la temperatura sicuramente è la prima."  

<span style="color:#FFA500;font-weight:bold">Developer</span>: "La temperatura e l'umidità sono accorpabili?"  

<span style="color:#E6BF83;font-weight:bold">Esperto</span>: "Sì esatto, è importante controllare la temperatura in modo che l'umidità sia a livelli ragionevoli. Poi senza ombra di dubbio l'irrigazione è importantissima. Questi tre concetti sono senza ombra di dubbio i più importanti. Tra l'altro sono tutti legati tra loro. Anche solo un parametro non in linea potrebbe facilmente portare la pianta in una condizione di stress."

---

#### Illuminazione
<span style="color:#FFA500;font-weight:bold">Developer</span>: "Per quanto riguarda l'illuminazione?"  

<span style="color:#E6BF83;font-weight:bold">Esperto</span>: "Sì, anche l'illuminazione è un parametro molto importante. Molte serre vengono realizzate in vetro proprio per fare in modo che sia la natura a fornire illuminazione e quindi risparmiare sull'illuminazione artificiale. Ci sono tuttavia anche piante più delicate e che hanno bisogno di cicli di illuminazioni il meno variabili possibile."

---

#### Sostituzione del terriccio

<span style="color:#ec3a8b;font-weight:bold">Developer</span>: "In una serra si utilizzano terricci particolari?"  

<span style="color:#b2868e;font-weight:bold">Esperto</span>: "Dipende. A differenza della coltivazione a terra è sicuramente necessario l'utilizzo di terriccio. La terra è una fonte sostanzialmente infinita di sostanze nutrienti. Una pianta in un vaso può attingere ad una quantità limitata di questi nutrienti ovviamente. Prima o poi finiscono. Per questo esistono diversi tipi di terriccio, alcune serre utilizzano addirittura delle soluzioni composte quasi solo da acqua e nutirente chiamate idroponiche."  

<span style="color:#ec3a8b;font-weight:bold">Developer</span>: "Comunque ci sono momenti in cui il terriccio deve essere rimpiazzato perché termina le sostanze nutritive al suo interno, giusto?"  

<span style="color:#b2868e;font-weight:bold">Esperto</span>: "Esatto."

---

#### Fertirrigazione

<span style="color:#ec3a8b;font-weight:bold">Developer</span>: "È vero che ci sono più tipi di fertilizzante?"  

<span style="color:#b2868e;font-weight:bold">Esperto</span>: "Ci sono diversi modi per fornire minerali ad una pianta, ma il più comune ed utilizzato è sicuramente attraverso la _fertirrigazione_"  

<span style="color:#ec3a8b;font-weight:bold">Developer</span>: "Di cosa si tratta?"  

<span style="color:#b2868e;font-weight:bold">Esperto</span>: "Sostanzialmente si inseriscono le sostanze nutritive direttamente nell'acqua utilizzata per irrigare."  

<span style="color:#ec3a8b;font-weight:bold">Developer</span>: "Io una volta ho accidentalmente ucciso una mia piantina perché le ho dato troppo fertilizzante. Come bisogna calibrarsi?"  

<span style="color:#b2868e;font-weight:bold">Esperto</span>: "Dipende da diversi fattori, ma principalmente dal tipo di pianta e dalla fase in cui si trova. Fornendo troppo fertilizzante rischia di far morire la pianta, fornendone troppo poco rischia di bloccare la crescita o di ridurre notevolmente il potenziale raccolto della pianta."

---

#### Equilibrio
<span style="color:#ec3a8b;font-weight:bold">Developer</span>: "Per come ci hai parlato finora mi è sembrato di capire una cosa. L'importante è non far mai subire alla pianta dei cambiamenti nei parametri troppo repentini e lasciarla in una sorta di suo equilibrio. Me lo confermi?"  

<span style="color:#b2868e;font-weight:bold">Esperto</span>: "Sì esatto. Una volta che la pianta è stata abituata in un certo modo è meglio non cambiare il suo ritmo, o rischia spiacevoli conseguenze tra cui anche la morte."  

<span style="color:#ec3a8b;font-weight:bold">Developer</span>: "Questo quindi in generale vale per ogni parametro? Anche quando cambia la fase della pianta e quindi le sue esigenze è meglio cercare di essere il più graduali possibili?"  

<span style="color:#b2868e;font-weight:bold">Esperto</span>: "Precisamente."

---

#### Notifiche

<span style="color:#235f73;font-weight:bold">Developer</span>: "Sarebbe utile un sistema di notifiche all'agricoltore? In questo modo se il sistema si accorge che qualcosa non va può avvisare tempestivamente qualcuno ed evitare disastri."    

<span style="color:#72bcd4;font-weight:bold">Esperto</span>: "Certamente sì, anche se in molti casi probabilmente potrebbe non bastare."  

<span style="color:#235f73;font-weight:bold">Developer</span>: "In che senso?"  

<span style="color:#72bcd4;font-weight:bold">Esperto</span>: "Spesso quando in una serra ci si accorge di qualcosa che non va, è ormai troppo tardi per rimediare. Per esempio se l'impianto di irrigazione si rompe e fornisce troppa acqua alle piante. Venir informati della presenza di un guasto sarebbe utile certo, ma in questo caso il danno sarebbe già fatto, e sarebbe irreparabile."  

<span style="color:#235f73;font-weight:bold">Developer</span>: "Quindi meglio prevenire che curare."  

<span style="color:#72bcd4;font-weight:bold">Esperto</span>: "Certo. Ma le notifiche potrebbero essere utili non solo in caso di guasti. Potrebbe essere utile venir informati quando è il momento di fare manutenzione, o un qualche tipo di controllo."  

<span style="color:#235f73;font-weight:bold">Developer</span>: "Quindi possiamo dire che ci sono due tipi di notifiche: i _reminder_, e i _warning_".  

---

#### Autonomia

<span style="color:#235f73;font-weight:bold">Developer</span>: "Abbiamo capito che è impossibile affidare completamente al sistema la gestione delle piante. Ma cosa si può effettivamente automatizzare? Cosa può fare anche un computer in completa autonomia?"  

<span style="color:#72bcd4;font-weight:bold">Esperto</span>: "Ci sono aspetti per cui in realtà automatizzare sarebbe utilissimo. Ad esempio l'irrigazione."  

<span style="color:#235f73;font-weight:bold">Developer</span>: "In base a cosa il sistema dovrebbe capire quando è il momento di irrigare? L'umidità del suolo è un buon parametro?"  

<span style="color:#72bcd4;font-weight:bold">Esperto</span>: "Sì, può essere un buon modo. Dipende molto anche dalle esigenze della pianta. Molte serre scelgono semplicemente ogni quando irrigare. L'importante è che una volta che viene presa una decisione essa venga mantenuta nel tempo. Non si può cambiare la modalità a metà strada o la pianta rischia lo stress."  

---

#### Autonomia

<span style="color:#235f73;font-weight:bold">Developer</span>: "Cosa si fa se una pianta comincia a morire? Come va trattata? Cosa va cambiato?"  

<span style="color:#72bcd4;font-weight:bold">Esperto</span>: "Di solito quando qualche parametro non è il linea con le esigenze della pianta questa comincia ad appassire o cambiare aspetto. Solo guardando la pianta si può capire che c'è qualcosa che non va. Come comportarsi varia molto dal problema. Sicuramente bisogna agire nel modo più tempestivo possibile. Una volta identificato il problema si cerca di rimediare ristabilendo l'equilibrio della pianta, per esempio fornendo meno acqua nel caso in cui quest'ultima ne abbia ricevuta troppa. A volte non è sufficiente però. L'ideale e non arrivare mai alla situazione in cui una pianta mostra segni di deterioramento. Anche il raccolto finale è fortemente influenzato dal modo in cui la pianta è cresciuta."

## Retrospettiva sui meeting

I meeting con l'esperto del dominio sono stati molto utili per comprendere meglio aspetti legati al dominio botanico e in particolare gli aspetti legati alla coltivazione.  
Sono stati inoltre molto utili per arricchire il vocabolario e fissare l'ubiquitous language.

### Informazioni chiave ottenute

Vengono di seguito elencate alcune delle informazioni più importanti che sono state apprese dopo i meeting avvenuti:

- Le piante (tutte) sono estremamente delicate, una volta abituate in un certo modo è difficile cambiare il loro ritmo e anche solo piccole variazioni possono portare la pianta in una condizione di stress.
- La manutenzione resta uno dei cardini principali all'interno della serra in quanto è necessaria a garantire sempre che le piante non possano incorrere in situazioni spiacevoli, e quindi massimizzare il raccolto.
- Temperatura, Umidità, Irrigazione e Illuminazione sono le quattro "proprietà" a cui prestare più attenzione quando si coltiva una pianta.