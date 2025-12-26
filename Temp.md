## Roadmapa: Etap 1 (Liczby całkowite + Dodawanie/Odejmowanie)
[x] Zmień pętlę: Ustaw while(1) (nieskończona pętla), aby program działał ciągle.

[x] Bufor na tekst: Zadeklaruj w main tablicę, np. char buffer[1024]; (to będzie miejsce, gdzie ląduje tekst z klawiatury).

[x] Czytanie linii: Użyj funkcji fgets(buffer, 1024, stdin), aby pobrać tekst od użytkownika.

[x] Podpięcie: Przypisz input = buffer; i zresetuj pos = 0; na początku każdego obiegu pętli.

[x] Wyjście awaryjne: Dodaj if sprawdzający, czy użytkownik wpisał "exit" (użyj strncmp), żeby przerwać pętlę.

2. Oczy i Nogi Robota (Helpery)
Zdefiniuj te funkcje przed main.

[x] Funkcja peek():

Ma zwracać input[pos].

Musi sprawdzać, czy nie wyjechaliśmy poza string (znak \0 lub \n).

[x] Funkcja advance():

Ma zwiększać pos o 1 (pos++).

Może zwracać znak, który właśnie minęliśmy (opcjonalne, ale wygodne).

[x] Test: W main wypisz ręcznie wynik peek(), zrób advance() i wypisz znowu, żeby sprawdzić czy działa.

3. Parsowanie Liczb (Serce Etapu 1)
[x] Funkcja parse_number():

Zwraca int.

Ma lokalną zmienną result = 0.

Pętla: dopóki peek() jest cyfrą (użyj isdigit z biblioteki <ctype.h>):

Pobierz cyfrę.

Oblicz: result = result * 10 + (znak - '0').

Zrób advance().

Zwróć result.

[x] Test: Wpisz w terminalu "123", wywołaj w main tylko parse_number() i wypisz wynik %d. Musi wyjść liczba 123.

4. Parsowanie Wyrażeń (Mózg)
[x] Funkcja skip_whitespace():

Dopóki peek() to spacja, rób advance(). Wstawiaj to wywołanie wszędzie tam, gdzie spodziewasz się spacji.

[ ] Funkcja parse_expression():

Zwraca int.

Pobierz pierwszą liczbę: val = parse_number().

Pętla nieskończona:

skip_whitespace().

Sprawdź op = peek().

Jeśli op to + lub -:

advance().

Pobierz drugą liczbę (next_val = parse_number()).

Zaktualizuj val (dodaj lub odejmij next_val).

Jeśli op to koniec linii/stringa -> break (wyjdź z pętli).

Zwróć val.

5. Wielki Finał Etapu 1
[x] Uruchomienie: W pętli main wywołaj int wynik = parse_expression(); i wypisz go printf("%d\n", wynik);.

[x] Test boju: Sprawdź działania: 10 + 5, 20 - 3 + 100, 123+1.

Etap 2 (Priorytety): Dodaj * / i nawiasy ( ). Tutaj wdrożysz pełny Recursive Descent.

Etap 3 (Zmienne): Dodaj prostą tablicę (struct), która przechowuje pary {nazwa: "a", wartosc: 5.0}.

Etap 4 (Funkcje C): Dodaj obsługę sqrt, sin mapując stringi na funkcje z math.h.

Etap 5 (Funkcje własne): Implementacja słowa kluczowego def lub składni f(x) = ....