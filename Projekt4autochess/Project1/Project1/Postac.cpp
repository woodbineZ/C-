#include <iostream>
#include "Postac.h"
#include "Druzyna.h"

using namespace std;

Postac::Postac()
{
	atakowal = false;
	zyje = true;
}

Postac::Postac(int _koszt, int _hp, int _dmg, string _nazwa, char _rodzaj)
{
	hp = _hp;
	dmg = _dmg;
	koszt = _koszt;
	atakowal = false;
	zyje = true;
	dostepna = true;
	nazwa = _nazwa;
	rodzaj = _rodzaj;
}

void Postac::wyswietlInfo(int pozycjaWliscie, int _gold)
{
	if (_gold >= koszt || _gold == -1)
	cout <<pozycjaWliscie<<" "<< rodzaj << " " << nazwa << " " << hp << " hp " << dmg << " dmg " << koszt << " zlota" << endl;
}

void Postac::getObrazenia(int damage)
{
	hp -= damage;
	if (hp <= 0)
		zyje = false;
}

Postac* Postac::celuj(Druzyna& przeciwnik)
{
	Postac* wrog = przeciwnik.dajPostac(0);
	return wrog;
}

Postac* Postac::przeszukajPozycje(Druzyna& przeciwnik, int _pozycja)
{
	for (int i = 0; i < przeciwnik.zwrocLiczbePostaci(); i++)
	{
		Postac* temp = przeciwnik.dajPostac(i);
		if (temp->zwrocPozycje() == _pozycja && temp->czyZyje()) 
			return temp;
	}
	throw 1;
}

void Postac::atak(Druzyna& przeciwnik)
{
	Postac* wrog;
	try
	{
		wrog = celuj(przeciwnik);
	}
	catch (...)
	{
		return;
	}
	wrog->getObrazenia(dmg);
	cout << " postac: " << this->nazwa << " zaatakowal " << wrog->nazwa << " zadajac " << this->dmg << " obrazen, " << wrog->nazwa << " zostalo " << wrog->hp << " hp." << endl;
	atakowal = true;
}

