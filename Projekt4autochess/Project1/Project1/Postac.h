#pragma once
#include <iostream>
#include <string>
class Druzyna;
using namespace std;
class Postac
{
protected:
	int hp;
	int pozycja;
	int dmg;
	int koszt;
	bool dostepna;
	bool atakowal;
	bool zyje;
	string nazwa;
	char rodzaj;
public:
	Postac();
	Postac(int _koszt, int _hp, int _dmg, string _nazwa, char _rodzaj);
	void atak(Druzyna& przeciwnik);
	void getObrazenia(int damage);
	virtual Postac* celuj(Druzyna& przeciwnik);
	bool czyDostepna() { return dostepna; }
	void ustawDostepna(bool _dostepna) { dostepna = _dostepna; }
	bool czyAtakowal() { return atakowal; }
	void ustawCzyAtakowal(bool _atakowal) { atakowal = _atakowal; }
	bool czyZyje() { return zyje; }
	int aKoszt() { return koszt; }
	void aPozycja(int _pozycja) { pozycja = _pozycja; }
	int zwrocPozycje() { return pozycja; }
	Postac* przeszukajPozycje(Druzyna& przeciwnik, int _pozycja);
	void wyswietlInfo(int pozycjaWliscie, int _gold);
};