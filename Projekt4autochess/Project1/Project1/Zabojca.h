#pragma once
#include <iostream>
#include "Postac.h"
using namespace std;

class Zabojca :public Postac
{
public:
	virtual Postac* celuj(Druzyna& przeciwnik);
	Zabojca(int _koszt, int _hp, int _dmg, string _nazwa, char _rodzaj);
};
