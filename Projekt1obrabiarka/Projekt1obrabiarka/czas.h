#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class czas
{
public:
	czas();
	~czas();
	czas(int sek);
	czas(int sek, int min);
	czas(int sek, int min, int godz);
private:
	int sekundy;
	int	minuty; 
	int godziny;
public: 
	bool ustawSekundy(int ile);
	bool ustawMinuty(int ile);
	bool ustawGodziny(int ile);
	bool ustawTimer(int sek, int min, int godz);
	int pokazSekundy();
	int pokazMinuty();
	int pokazGodziny();
	void wyswietlCzas();
	void napraw();
	czas operator+(czas &timer);
	czas operator+(int liczba);
	bool operator==(czas &timer);
	bool operator<(czas &timer);
	bool operator>(czas &timer);
	bool operator!=(czas &timer);
	bool operator<=(czas &timer);
	bool operator>=(czas &timer);
	void czytajKlawiature();
};

