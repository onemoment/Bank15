# bank15
pg pibd 2015

Program ma symulować różne rodzaje rachunków bankowych.

### to do:

* klasa Adres - określenie adresów klientów i oddziałów bankowych. Atrybuty, konstruktor, destruktor, set, get

* klasa Klient - określanie danych klientów posiadających rachunki bankowe. j.w.

* klasa Bank - do opisu oddziałów bankowych. j.w.

* klasa Rachunek bieżący - dziedziczy po Bank. Atrybuty - numer rachunku, wlasciciel rachunku, nazwa banku, oprocentowanie, domyslna waluta, data założenia rachunku, data zamkniecia, prowizje oplaty, istnienie karty do rachunku. Zdefiniowane sa też usługi bankowe - bieżące saldo, operacje wplaty i wyplaty, przelewy przychodzace i wychodzace oraz zamkniecie rachunku.

* klasa Rachunek oszczędnościowy - dziedziczy po Rachunek bieżący. rozszerza możliwości rachunku zgodnie z nazwą. tam gdzie to przydatne stworz funkcje wirtulne.
* klasa Rachunek walutowy - j.w.
* klasa rachunek lokaty - j.w.
* interfejs użytkownika.
* historia operacji zapisywana do pliku