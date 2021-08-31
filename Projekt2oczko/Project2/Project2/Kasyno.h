#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Gracz.h"
#include "Karta.h"
#include <string.h>
#include "Komputer.h"

class Kasyno
{
		Karta talia[52];
		Gracz *listaGraczy;
		int iloscGraczy;
		bool oddane[52];
		Komputer *listaBotow;
		int iloscBotow;
		Gracz **tablica;
		int rozmiarTab;
	public:
		Kasyno();
		~Kasyno();
		void tasuj();
		Karta* dajKarte();
		void graj();
		Gracz* zwyciezca();
		void zapisz();
		void dodajBota(int _odwaga);
		void dodajGracza();
		void wypiszTalie();
};
