#include "czas.h"

czas::czas()
{
	sekundy = 0;
	minuty = 0;
	godziny = 0;
}

czas::~czas()
{

}

czas::czas(int sek)
{
	sekundy = sek;
	minuty = 0;
	godziny = 0;
}

czas::czas(int sek, int min)
{
	sekundy = sek;
	minuty = min;
	godziny = 0;
}

czas::czas(int sek, int min, int godz)
{
	sekundy = sek;
	minuty = min;
	godziny = godz;
}

bool czas::ustawSekundy(int ile)
{
	if (ile >= 0 && ile < 60)
	{
		sekundy = ile;
		return true;
	}
	return false;
}

bool czas::ustawMinuty(int ile)
{
	if (ile >= 0 && ile < 60)
	{
		minuty = ile;
		return true;
	}
	return false;
}

bool czas::ustawGodziny(int ile)
{
	if (ile>=0)
	{
		godziny = ile;
		return true;
	}
	return false;
}

bool czas::ustawTimer(int sek, int min, int godz)
{
	if (sek >= 0 && sek < 60 && min >= 0 && min < 60 && godz >= 0)
	{
		sekundy = sek;
		minuty = min;
		godziny = godz;
		return true;
	}
	return false;
}

int czas::pokazSekundy()
{
	return sekundy;
}

int czas::pokazMinuty()
{
	return minuty;
}

int czas::pokazGodziny()
{
	return godziny;
}

void czas::wyswietlCzas()
{
	cout << "Sekundy: " << sekundy << "   Minuty: " << minuty << "   Godziny: " << godziny << endl;;
}

void czas::napraw()
{
	while (sekundy > 60)
	{
		sekundy = sekundy - 60;
		minuty = minuty + 1;
	}
	while (minuty > 60)
	{
		minuty = minuty - 60;
		godziny = godziny + 1;
	}
}

czas czas::operator+(czas &timer)
{
	czas temp;
	temp.sekundy = sekundy + timer.sekundy;
	temp.minuty = minuty + timer.minuty;
	temp.godziny = godziny + timer.godziny;
	temp.napraw();
	return temp;
}

czas czas::operator+(int liczba)
{
	czas temp;
	temp.sekundy = sekundy + liczba;
	temp.napraw();
	return temp;
}

bool czas::operator==(czas &timer)
{
	if (timer.sekundy == sekundy && timer.minuty == minuty && timer.godziny == godziny)
		return true;
	else
		return false;
}

bool czas::operator<(czas &timer)
{
	if (godziny < timer.godziny
		|| (godziny == timer.godziny && minuty < timer.minuty)
		|| (godziny == timer.godziny && minuty == timer.minuty && sekundy < timer.sekundy))
		return true;
	else
		return false;
}

bool czas::operator>(czas &timer)
{
	if (!(timer<=*this) )
		return true;
	else
		return false;
}

bool czas::operator!=(czas &timer)
{
	if (!(timer==*this))
		return true;
	else
		return false;
}

bool czas::operator<=(czas &timer)
{
	if (timer<*this || timer==*this)
		return true;
	else
		return false;
}

bool czas::operator>=(czas &timer)
{
	if (!(timer<*this) || timer==*this)
		return true;
	else
		return false;
}

void czas::czytajKlawiature()
{
	int a, b, c;
	cout << "Podaj ile chcesz miec sekund" << endl;
	while (!(cin >> a) || a >= 60 || a<0)
	{
		cout << "Podano niepoprawne dane. Nalezy podac liczbe calkowita" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	cout << "Podaj ile chcesz miec minut" << endl;
	while (!(cin >> b) || b >= 60 || b<0)
	{
		cout << "Podano niepoprawne dane. Nalezy podac liczbe calkowita" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	cout << "Podaj ile chcesz miec godzin" << endl;
	while (!(cin >> c) || c<0)
	{
		cout << "Podano niepoprawne dane. Nalezy podac liczbe calkowita" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	ustawTimer(a, b, c);
}