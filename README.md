zadanie_sss
===========

Zadanie úlohy:
1. ANAGRAMY
Anagram slova je nové slovo, ktoré vznikne poprehadzovaním písmen pôvodného slova.
Napíš program, ktorý pre zadané slovo a zoznam kanditátov vráti slová, ktoré su anagramom daného slova.
Napríklad pre slovo "listen" a zoznam kandidátov ["enlists", "google", "inlets", "banana"] program vráti zoznam ["inlets"].
Pokús sa algoritmus hľadania anagramov optimalizovať tak, aby bol čo najefektívnejší a vysvetli aké optimalizácie si použil a prečo.

Riešenie:
Keďže ide o efektívnosť tak som si vybral C. Princíp hĺadania anagramu je nasledovný:
  1. vstupom do funkcie je slovo ktorého anagramy hľadáme, zoznam v ktorom hľadáme, veľkosť zozamu v ktorom hľadáme, veľkosť výsledného zoznamu ktorý vrátime funkciou
  2. slovo ktorého anagramy hľadáme prejdeme po znakoch a jednotlivé indexy na ktoré sa dostaneme vďaka hodnote znaku inkrementuje o 1
  3. prechádzame postupne zoznam slov a dekrementuje hodnoty cez indexy kam ukazujú číselné hodnoty znakov
  4. ak je pred dekrementáciou hodnota na danom indexe 0 tak nejde o anagram, hodnoty sa zresetujú, zoznam(histogram) písmen sa obnoví a postúpi sa na ďalšie slovo
  5. ak zbehne celé slovo tak sa skontroluje či sú všetky prvky historgamu písmen na hodnote 0
  6. ak áno ide o anagram a je pridaný do výsledného zoznamu
  7. na konci sa nastaví veľkosť premennej výsledého zoznamu a funkcia vráti zoznam so slovami ktoré sú anagrami

Optimalizácie:
  - program nekontroluje všetky znaky slova zo zoznamu ale pri prvom nezhodnom znaku sa posúva na nasledujúce slovo
  - pri nezhodnej dĺžke pôvodného slova a slova ktoré sa ide práve testovať sa ihneď preskočí na nasledujúce slovo
  - ak sa v slove nechádza viac rovnakých písmen ktoré sa nachádzajú aj v pôvodnom slove tak sa automaticky prejde na ďalšie slovo
  

janocko martin
