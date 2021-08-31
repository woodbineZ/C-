#pragma once
#include <iostream>
#include <cstdlib>
#include "Gracz.h"
#include "Karta.h"

class Kasyno
{
public:
	Karta Talia[52];
	Gracz Gracz1;
	Gracz Gracz2;
public:
	Kasyno();
	~Kasyno();
	void Tasuj();
	Karta* dajKarte();

};