#pragma once
#include <iostream>
#include <vector>
#include "Druzyna.h"

using namespace std;
class Postac;
class Rozgrywka
{
	vector<Postac*> zbieranina;
	Druzyna t1, t2;
	string gracz1, gracz2;
public:
	Rozgrywka();
	~Rozgrywka();
	void walka();
	void wczytywanie();
	Postac* dajPostac(int ktora);
	void wyswietlZbieranine(int _gold);
	void zakupy();
	Druzyna& aDruzyny1() { return t1; }
	Druzyna& aDruzyny2() { return t2; }
	void nazwaGracza();
	string zwrocNazweG1() { return gracz1; }
	string zwrocNazweG2() { return gracz2; }
};