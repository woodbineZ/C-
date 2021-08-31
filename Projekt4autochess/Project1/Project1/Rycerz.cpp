#pragma once
#include <iostream>
#include "Rycerz.h"
#include "Druzyna.h"

using namespace std;

Rycerz::Rycerz(int _koszt, int _hp, int _dmg, string _nazwa, char _rodzaj) :Postac(_koszt, _hp, _dmg, _nazwa, _rodzaj)
{

}

Postac* Rycerz::celuj(Druzyna& przeciwnik)
{
	try
	{
		return przeszukajPozycje(przeciwnik, 1);
	}
	catch (...) {}
	try
	{
		return przeszukajPozycje(przeciwnik, 2);
	}
	catch (...) {}
	return przeszukajPozycje(przeciwnik, 3);
}