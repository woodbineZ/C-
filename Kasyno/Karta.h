#pragma once
#include <iostream>

class Karta
{
private:
	char kolor;
	char figura;
	int wartosc;
public:
	Karta(int _kolor = 0, int _wartosc = 0);
	void setKolor(int _kolor);
	void setWartosc(int _wartosc);
	int dajWartosc() { return wartosc; }
	int dajKolor() { return kolor; }
	void wyswietlKarte();
};

