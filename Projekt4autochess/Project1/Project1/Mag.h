#pragma once
#include <iostream>
#include "Postac.h"
using namespace std;

class Mag :public Postac
{
public:
	virtual Postac* celuj(Druzyna& przeciwnik);
	Mag(int _koszt, int _hp, int _dmg, string _nazwa, char _rodzaj);
};
