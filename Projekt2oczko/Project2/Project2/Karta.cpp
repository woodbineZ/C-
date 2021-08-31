#include "Karta.h"

char kolory[] = { 3, 4, 5, 6 };
char figury[] = { '2', '3', '4', '5', '6', '7', '8', '9', 'D', 'J', 'Q', 'K', 'A' };
int wartosci[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 2, 3, 4, 11 };

Karta::Karta(int _kolor, int _wartosc)
{
	setKolor(_kolor);
	setWartosc(_wartosc);
}

void Karta::setKolor(int _kolor)
{
	if (_kolor < 4)
	{
		kolor = kolory[_kolor];
	}
}

void Karta::setWartosc(int _wartosc)
{
	if (_wartosc < 14)
	{
		figura = figury[_wartosc];
		wartosc = wartosci[_wartosc];
	}
}

void Karta::wypisz()
{
	std::cout << figura << kolor;
}