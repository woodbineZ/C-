#pragma once
#include <iostream>
#include "Postac.h"
using namespace std;

class Rycerz :public Postac
{
public:
	virtual Postac* celuj(Druzyna& przeciwnik);
	Rycerz(int _koszt, int _hp, int _dmg, string _nazwa, char _rodzaj);
};
