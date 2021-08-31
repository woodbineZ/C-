#pragma once
#include <iostream>
#include <vector>
#include "Postac.h"
class Rozgrywka;
using namespace std;

class Druzyna
{
	Rozgrywka* gra;
	int gold;
	vector<Postac*> postacie;
public:
	Druzyna(int _gold);
	Druzyna();
	Postac* dajPostac(int ktora);
	void atak(Druzyna& przeciwnik);
	bool czyZywa();
	int ileGolda() { return gold; }
	void kupPostac();
	int ustalPozycje(Postac* postac);
	int zwrocLiczbePostaci() { return postacie.size(); }
	void przypiszGre(Rozgrywka* _gra) { gra = _gra; }
};