#pragma once
#include <iostream>
#include "Karta.h"

class Kasyno;
class Gracz
{
	protected:
		char nazwa[20];
		int rozmiar;			//ilosc kart w rêce
		Karta reka[10];
		bool pass;				// 1- Gracz spassowa³, 0- Gracz gra dalej
	public:
		Gracz();
		~Gracz();
		int pobierzRozmiar();
		int zliczPunkty();
		void wezKarte(Karta * _karta);
		void pokazReke();
		virtual bool decyzja();
		bool czyPass();
		void podajNazwe();
		void ustawNazwe();
		void autoPass();
		char* wezNazwe();
		Karta zwrocKarte(int _numer);
};
