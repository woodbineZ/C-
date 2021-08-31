#include "Gracz.h"
#include "Kasyno.h"

Gracz::Gracz()
{
	pass = 0;
	rozmiar = 0;
}

Gracz::~Gracz()
{

}

int Gracz::pobierzRozmiar()
{
	return rozmiar;
}

int Gracz::zliczPunkty()
{
	int suma = 0;
	for (int i = 0; i < rozmiar; ++i)
	{
		suma = suma + reka[i].getWartosc();
	}
	return suma;
}

void Gracz::wezKarte(Karta * _karta)
{
	reka[rozmiar] = *_karta;
	rozmiar++;
}

void Gracz::pokazReke()
{
	std::cout << "reka gracza:";
	podajNazwe();
	for (int i = 0; i < rozmiar; ++i)
	{
		reka[i].wypisz();
	}
	std::cout << "\n";
}

bool Gracz::decyzja()
{
	int wybor;
	while (1)
	{
		std::cout << "Gracz:";
		podajNazwe();
		std::cout << "Dobieram [1]" << std::endl;
		std::cout << "Pasuje [2]" << std::endl;
		std::cin >> wybor;
		if (std::cin.fail() == true || (wybor != 1 && wybor != 2))
		{
			std::cout << "Wykryto blad. Podaj ponownie dane" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else break;
	}
	if (wybor == 1)
	{
		pass = 0;
		return true;
	}
	if (wybor == 2)
	{
		pass = 1;
		return false;
	}
}

bool Gracz::czyPass()
{
	return pass;
}

void Gracz::podajNazwe()
{
	std::cout << nazwa;
	std::cout << "\n";
}

void Gracz::ustawNazwe()
{
	char _nazwa[20];
	pass = 0;
	std::cout << "Podaj nazwe gracza:" << std::endl;
	std::cin >> _nazwa;
	strcpy_s(nazwa, _nazwa);
}

void Gracz::autoPass()
{
	if (zliczPunkty() >= 21)
		pass = 1;
}

char* Gracz::wezNazwe()
{
	return nazwa;
}

Karta Gracz::zwrocKarte(int _numer)
{
	Karta _karta(reka[_numer]);
	return _karta;
}