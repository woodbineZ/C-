#pragma once
#include <iostream>
#include "Zabojca.h"
#include "Druzyna.h"

using namespace std;

Zabojca::Zabojca(int _koszt, int _hp, int _dmg, string _nazwa, char _rodzaj):Postac(_koszt, _hp, _dmg, _nazwa, _rodzaj)
{
	
}


Postac* Zabojca::celuj(Druzyna& przeciwnik)
{
	try
	{
		return przeszukajPozycje(przeciwnik, 3);
	}
	catch (...) {}
	try
	{
		return przeszukajPozycje(przeciwnik, 2);
	}
	catch (...) {}
	return przeszukajPozycje(przeciwnik, 1);
}
