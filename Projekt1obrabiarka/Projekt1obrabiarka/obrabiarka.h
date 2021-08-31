#pragma once
#include <iostream>
#include "czas.h"

class obrabiarka
{
	int rozmiar;
	czas *tab;
public:
	obrabiarka();
	obrabiarka(int p_rozmiar);
	obrabiarka(const obrabiarka &ob1);
	~obrabiarka();
	void wpiszZklaw();
	void dodaj();
	void dodaj(czas timer);
	void pokazSume();
	void wypisanie();
	int zwrocRozmiar();
	void pokazCzas(int k);
	czas zwrocCzas(int k);
	obrabiarka zakres(czas timery);
	obrabiarka pierwsze(int n);
	obrabiarka& operator=(const obrabiarka &ob);
};

