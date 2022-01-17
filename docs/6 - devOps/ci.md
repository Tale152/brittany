---
title: Continous Integration
parent: Documentazione DevOps
has_children: false
---

# Continous Integration

Particolare attenzione è stata posta nell’individuazione di misure per assicurare la qualità del codice del sistema. Grazie alle GitHub Actions sono stati predisposti dei workflow per garantire la Continuous Integration e la Quality Assurance.

### Edge Worklow

Il workflow del modulo Edge è strutturato nel seguente modo:

1. Installazione dello strumento di coverage: _lcov_
2. Cache di pip
3. Cache di PlatformIO
4. Setup di Python
5. Installazione di PlatformIO
6. Esecuzione dei Test nativi
7. Check sulla soglia minima della coverage (impostata a 90%)