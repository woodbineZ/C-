#pragma once
#include <iostream>
#include "Karta.h"

class Gracz
{
	int rozmiar;
	Karta *reka;
public:
	Gracz();
	~Gracz();
	int PobierzRozmiar();
	int ZliczPunkty();
	void WezKarte(Karta * _karta);
	void PokazReke();
};