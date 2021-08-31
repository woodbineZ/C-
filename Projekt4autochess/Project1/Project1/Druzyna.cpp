#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Druzyna.h"
#include "Rozgrywka.h"


using namespace std;

Druzyna::Druzyna(int _gold)
{
	gold = _gold;	
}

Druzyna::Druzyna()
{
	gold = 25;
}

Postac* Druzyna::dajPostac(int ktora)
{
	Postac* p = postacie.at(ktora);
	return p;
}

void Druzyna::atak(Druzyna& przeciwnik)
{
	for (int i = 0; i < postacie.size(); i++)
	{
		if (postacie.at(i)->czyZyje() && !postacie.at(i)->czyAtakowal())
		{
			postacie.at(i)->atak(przeciwnik);
			break;
		}
	}
	bool wszyscyAtakowali = true;
	for (int i = 0; i < postacie.size(); i++)
	{
		if (!postacie.at(i)->czyAtakowal() && postacie.at(i)->czyZyje())
			wszyscyAtakowali = false;
	}
	if(wszyscyAtakowali)
		for (int i = 0; i < postacie.size(); i++)
			postacie.at(i)->ustawCzyAtakowal(false);
}

bool Druzyna::czyZywa()
{
	for (int i = 0; i < postacie.size(); i++)
		if (postacie.at(i)->czyZyje())
			return true;
	return false;
}

void Druzyna::kupPostac()
{
	int nrPostaci;
	cout << "ktora postac chcesz kupic?" << endl;	
	try
	{	
		while (!(cin >> nrPostaci) || nrPostaci<0)
		{
			cout << "Podano niepoprawna mozliwosc wyboru." <<endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		Postac* temp = gra->dajPostac(nrPostaci);
		if (temp->czyDostepna())
		{
			if (temp->aKoszt() <= gold)
			{
				gold -= temp->aKoszt();
				temp->ustawDostepna(false);
				ustalPozycje(temp);
				postacie.push_back(temp);
			}
			else
				cout << "nie stac cie na ta postac" << endl;
		}
		else
		{
			cout << "ta postac nie jest dostepna" << endl;
			cout << "ktora postac chcesz kupic?" << endl;
			while (!(cin >> nrPostaci) || nrPostaci < 0)
			{
				cout << "Podano niepoprawny mozliwosc wyboru." << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			Postac* temp = gra->dajPostac(nrPostaci);
			if (temp->czyDostepna())
			{
				if (temp->aKoszt() <= gold)
				{
					gold -= temp->aKoszt();
					temp->ustawDostepna(false);
					ustalPozycje(temp);
					postacie.push_back(temp);
				}
				else
					cout << "nie stac cie na to postac" << endl;
			}
		}
	}
	catch(...)
	{
		cout << "Postac nie jest dostepna, wybierz inna." << endl;
	}
}

int Druzyna::ustalPozycje(Postac* postac)
{
	int poz;
	cout << "na ktora linie chcesz ustawic ta postac?(1)-najblizsza, (2)-srodkowa, (3)-najdalsza" << endl;
	while (!(cin >> poz) || poz<=0 || poz>3)
	{
		cout << "Podano niepoprawna pozycje. Podaj ponownie" <<endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	postac->aPozycja(poz);
	return poz;
}