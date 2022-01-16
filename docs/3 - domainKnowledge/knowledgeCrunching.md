---
title: Knowledge Crunching
parent: Domain Knowledge
has_children: false
---

# Knowledge Crunching

Prima ancora di mettere mano all’architettura di progetto, sono state effettuate sessioni di knowledge crunching che hanno visto la partecipazione di tutti i membri del team e di un esperto del dominio nell'ambito della botanica.
Scopo di queste sessioni era lo studio del dominio applicativo, e la definizione di requisiti tali da guidare lo sviluppo in un’ottica DDD.

Obiettivo principale delle sessioni è stata la definizione dell'Ubiquitous Language e l'acquisizione di una maggiore compotenenza in campo botanico.

Vengono di seguito illustrate alcune interazioni tra sviluppatori e l'esperto del dominio.
È stata effettuata per praticità una divisione per tipologia di argomento affrontato.

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

<span style="color:#19ff19;font-weight:bold">Esperto</span>: "Non solo, due piante appartenenti alla stessa famiglia avranno più o meno bisogno dello stesso tipo di trattamento per crescere. Anche se i parametri sono leggermente diversi tra le specie non dovrebbero cambiare più di tanto."  

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

<span style="color:#19ff19;font-weight:bold">Esperto</span>: "Il nome esteso è fase fenologica"

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

<span style="color:#b2868e;font-weight:bold">Esperto</span>: "Ci sono diversi modi per fornire minerali ad una pianta, ma il più comune ed utilizzato è sicuramente attraverso la fertirrigazione"  

<span style="color:#ec3a8b;font-weight:bold">Developer</span>: "Di cosa si tratta?"  

<span style="color:#b2868e;font-weight:bold">Esperto</span>: "Sostanzialmente si inseriscono le sostanze nutritive direttamente nell'acqua utilizzata per irrigare."  

<span style="color:#ec3a8b;font-weight:bold">Developer</span>: "Io una volta ho accidentalmente ucciso una mia piantina perché le ho dato troppo fertilizzante. Come bisogna calibrarsi?"  

<span style="color:#b2868e;font-weight:bold">Esperto</span>: "Dipende da diversi fattori, ma principalmente dal tipo di pianta e dalla fase in cui si trova. Fornendo troppo fertilizzante rischia di far morire la pianta, fornendonde troppo poco rischia di bloccare la crescita o di ridurre notevolmente il potenziale raccolto della pianta."

---

#### Equilibrio
<span style="color:#ec3a8b;font-weight:bold">Developer</span>: "Per come ci hai parlato fin'ora mi è sembrato di capire una cosa. L'importante è non far mai subire alla pianta dei cambiamenti nei parametri troppo repentini e lasciarla in una sorta di suo equilibrio. Me lo confermi?"  

<span style="color:#b2868e;font-weight:bold">Esperto</span>: "Sì esatto. Una volta che la pianta è stata abituata in un certo modo è meglio non cambiare il suo ritmo, o rischia spiacevoli conseguenze tra cui anche la morte."  

<span style="color:#ec3a8b;font-weight:bold">Developer</span>: "Questo quindi in generale vale per ogni parametro? Anche quando cambia la fase della pianta e quindi le sue esigenze è meglio cercare si essere più graduali possibili?"  

<span style="color:#b2868e;font-weight:bold">Esperto</span>: "Precisamente."