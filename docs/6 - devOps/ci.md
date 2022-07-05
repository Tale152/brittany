---
title: Continuous integration
parent: Documentazione DevOps
has_children: false
---

# Continuous integration

Particolare attenzione è stata posta nell’individuazione di misure per assicurare la qualità del codice del sistema. Grazie alle GitHub Actions sono stati predisposti dei workflow per garantire la Continuous Integration e la Quality Assurance.

## [Auth, Persitence, Settings] Service Workflow 

Il workflow dei sottoprogetti _Auth_, _Persistence_ e _Settings_ Service è praticamente il medesimo. I tre sottoprogetti sono infatti strutturati in un modo molto simile ed utilizzano le stesse tecnologie. Il workflow è strutturato nel seguente modo:

#### Test

1. Viene creata una matrice e viene testato il sistema con tre diverse versioni di node (12.x, 14.x, 16.x) e tre diverse versioni di mongodb (3.6, 4.0, 4.2);
2. Checkout;
3. Set-up Node.js;
4. Set-up MongoDB;
5. npm install;
6. npm test.

#### Deploy Dev Docker Image

1. Controllo sullo stato del workflow di test. In caso di successo si prosegue;
2. Controllo del branch che ha effetuato il push. In caso ci si trovi nel branch [auth/settings/persistence]-service si prosegue;
3. Checkout;
4. Autenticazione a DockerHub Registry;
5. Creazione dell'immagine Docker;
6. Push dell'immagine Docker.

#### Production Deploy su Heroku

1. Controllo sullo stato del workflow di test. In caso di successo si prosegue;
2. Controllo del branch che ha effetuato il push. In caso ci si trovi nel branch master si prosegue;
3. Checkout;
4. Autenticazione al registro di Heroku;
5. Creazione del container;
6. Release del container.

## Edge Workflow

Il workflow del sottoprogetto _Edge_ è strutturato nel seguente modo:

#### Test

1. Checkout
2. Installazione dello strumento di coverage: _lcov_
3. Cache di pip
4. Cache di PlatformIO
5. Setup di Python
6. Installazione di PlatformIO
7. Esecuzione dei Test nativi
8. Check sulla soglia minima della coverage (impostata a 90%)

#### Deploy Dev Docker Image

1. Controllo sullo stato del workflow di test. In caso di successo si prosegue;
2. Controllo del branch che ha effetuato il push. In caso ci si trovi nel branch edge-service si prosegue;
3. Checkout;
4. Autenticazione a DockerHub Registry;
5. Creazione dell'immagine Docker;
6. Push dell'immagine Docker.

#### Deploy Production Docker Image

1. Controllo sullo stato del workflow di test. In caso di successo si prosegue;
2. Controllo del branch che ha effetuato il push. In caso ci si trovi nel branch master si prosegue;
3. Checkout;
4. Autenticazione a DockerHub Registry;
5. Creazione dell'immagine Docker;
6. Push dell'immagine Docker.

## Greenhouse Core

Il workflow del sottoprogetto _Greenhouse Core_ è strutturato nel seguente modo:

#### Deploy Dev Docker Image

1. Controllo del branch che ha effetuato il push. In caso ci si trovi nel branch greenhouse-core si prosegue;
2. Checkout;
3. Autenticazione a DockerHub Registry;
4. Creazione dell'immagine Docker;
5. Push dell'immagine Docker.

#### Deploy Production Docker Image

1. Controllo del branch che ha effetuato il push. In caso ci si trovi nel branch master si prosegue;
2. Checkout;
3. Autenticazione a DockerHub Registry;
4. Creazione dell'immagine Docker;
5. Push dell'immagine Docker.

## Web Client Workflow

Il workflow del sottoprogetto _Web Client_ è strutturato nel seguente modo:

#### Test

1. Viene creata una matrice e viene testato il sistema con tre diverse versioni di node (12.x, 14.x, 16.x) e tre sistemi operativi (Ubuntu, Windows, macOs);
2. Checkout;
3. Set-up Node.js;
4. npm install;
5. npm test.

#### Deploy Dev Docker Image

1. Controllo sullo stato del workflow di test. In caso di successo si prosegue;
2. Controllo del branch che ha effetuato il push. In caso ci si trovi nel branch web-client si prosegue;
3. Checkout;
4. Autenticazione a DockerHub Registry;
5. Creazione dell'immagine Docker;
6. Push dell'immagine Docker.

#### Production Deploy su Heroku

1. Controllo sullo stato del workflow di test. In caso di successo si prosegue;
2. Controllo del branch che ha effetuato il push. In caso ci si trovi nel branch master si prosegue;
3. Checkout;
4. Autenticazione al registro di Heroku;
5. Creazione del container;
6. Release del container.
