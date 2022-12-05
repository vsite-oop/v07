# VSITE OOP vježba 7

Implementirajte klasu money koristeći TDD:
- u solution dodajte projekt za unit testove ("*Native Unit Test Project*")
- u unit test projekt dodajte /app/money.h i /app/money.cpp
- u UnitTest1.cpp (možete ga preimenovati) dodajte `#include "money.h"`
- napišite što više testova i provjera (`Assert`-ova) koji pokrivaju barem funkcionalnost potrebnu za već napisani program (u main.cpp)
- implementirajte public metode i potrebne operatore klase `money`

Testovima pokrijte što više rubnih slučajeva (overflow, underflow, ispis sa 0 kn, ispis sa 0 lp i slično)

Očekivani unos u program je nešto poput (negativna svota je storno):
```
+ 6 80
+ 7 20
+ 12 40
- 5 50
+ 10 15
```

za očekivani ispis:

```
31 kn, 05 lp
```

 
![Build and test status](../../actions/workflows/msbuild.yml/badge.svg)
