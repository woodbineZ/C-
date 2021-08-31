#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Rozgrywka.h"
#include "Postac.h"
#include "Mag.h"
#include "Rycerz.h"
#include "Zabojca.h"

using namespace std;

Rozgrywka::Rozgrywka()
{
	t1.przypiszGre(this);
	t2.przypiszGre(this);
}

void Rozgrywka::wczytywanie()
{
	ifstream sklep;
	string nazwa;
	char temp;
	int tempHP, tempDMG, tempKoszt;
	sklep.open("shop.txt", ifstream::in);
	while (!sklep.eof())
	{
		sklep >> temp;
		sklep >> nazwa;
		sklep >> tempKoszt;
		sklep >> tempHP;
		sklep >> tempDMG;
		if (temp == 'm')
		{
			Postac *wsk = new Mag(tempKoszt, tempHP, tempDMG, nazwa, temp);
			zbieranina.push_back(wsk);
		}
		if (temp == 'r')
		{
			Postac *wsk = new Rycerz(tempKoszt, tempHP, tempDMG, nazwa, temp);
			zbieranina.push_back(wsk);
		}
		if (temp == 'z')
		{
			Postac *wsk = new Zabojca(tempKoszt, tempHP, tempDMG, nazwa, temp);
			zbieranina.push_back(wsk);
		}
	}
	sklep.close();
}

Postac* Rozgrywka::dajPostac(int ktora)
{
	Postac* p1 = zbieranina.at(ktora);
	return p1;
}

void Rozgrywka::wyswietlZbieranine(int _gold)
{
	for (int i = 0; i < zbieranina.size(); i++)
	{
		if(zbieranina.at(i)->czyDostepna())
			zbieranina.at(i)->wyswietlInfo(i, _gold);
	}
}

void Rozgrywka::zakupy()
{
	int x = 0;
	int y = 0;
	for (int i = 0; i < 7; i++)
	{
		wyswietlZbieranine(t1.ileGolda());
		cout << gracz1 << " masz tyle zlota: " << t1.ileGolda() << ", ";
		bool zakupiono=false;
		while (!zakupiono && x < zbieranina.size())
		{
			if (zbieranina.at(x)->aKoszt() <= t1.ileGolda())
			{
				t1.kupPostac();
				zakupiono = true;
			}
				x++;
		}
		wyswietlZbieranine(t2.ileGolda());
		cout << gracz2 << " masz tyle zlota: " << t2.ileGolda() << ", ";
		zakupiono = false;
		while (!zakupiono && y < zbieranina.size())
		{
			if (zbieranina.at(y)->aKoszt() <= t2.ileGolda())
			{
				t2.kupPostac();
				zakupiono = true;
			}
				y++;
		}
	}

}

void Rozgrywka::nazwaGracza()
{
	cout << "podaj nazwe gracza numer 1" << endl;
	while (!(cin >> gracz1))
	{
		cout << "Podano niepoprawna nazwe" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	cout << "podaj nazwe gracza numer 2" << endl;
	while (!(cin >> gracz2))
	{
		cout << "Podano niepoprawna nazwe" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
}

void Rozgrywka::walka()
{
	while (t1.czyZywa() && t2.czyZywa())
	{
		cout << "Atakuje gracz: " << gracz1 << endl;
		t1.atak(t2);
		cout << "Atakuje gracz: " << gracz2 << endl;
		t2.atak(t1);
	}
}

Rozgrywka::~Rozgrywka()
{
	for (int i = 0; i < zbieranina.size(); i++)
		delete zbieranina.at(i);
}
