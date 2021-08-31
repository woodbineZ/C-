#include "Kasyno.h"
#include <fstream>

Kasyno::Kasyno()
{
	for (int i = 0; i < 13; ++i)
	{
		talia[i].setKolor(0);
		talia[i + 13].setKolor(1);
		talia[i + 26].setKolor(2);
		talia[i + 39].setKolor(3);
	}
	for (int j = 0; j < 13; ++j)
	{
		talia[j].setWartosc(j);
		talia[j + 13].setWartosc(j);
		talia[j + 26].setWartosc(j);
		talia[j + 39].setWartosc(j);
	}

	iloscGraczy = 0;
	iloscBotow = 0;
	rozmiarTab = 0;
}

Kasyno::~Kasyno()
{
	delete[] tablica;
	delete[] listaGraczy;
	delete[] listaBotow;
}

void Kasyno::tasuj()
{
	int losowa1;
	int losowa2;
	Karta t1;
	Karta t2;
	for (int i = 0; i < 100; ++i)
	{
		do
		{
			losowa1 = (std::rand() % 52);
			losowa2 = (std::rand() % 52);
		} while (losowa1 == losowa2);
		t1 = talia[losowa1];
		t2 = talia[losowa2];
		talia[losowa1] = t2;
		talia[losowa2] = t1;
	}
}

Karta * Kasyno::dajKarte()
{
	Karta* ptr;

	int losowa;
	do
	{
		losowa = std::rand() % 52;
	} while (oddane[losowa] == 1);
	oddane[losowa] = 1;
	ptr = &talia[losowa];
	return ptr;
}

void Kasyno::graj()
{
	tablica = new Gracz*[6];
	for (int i = 0; i < 52; ++i)
		oddane[i] = 0;
	int gramydalej = 1;
	int chce = 1;
	std::cout << "Tworzenie 1. gracza:" << std::endl;
	dodajGracza();
	do
	{
		while (1)
		{
			std::cout << "Czy chcesz dodac kolejnego gracza? 1-TAK 2-NIE" << std::endl;
			std::cin >> chce;
			if (std::cin.fail() == true || (chce != 1 && chce != 2))
			{
				std::cout << "wykryto blad. Podaj dane ponownie" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
			}
			else break;
		}
		if (chce == 1)
			dodajGracza();
	} while (chce == 1);
	int a = 1;
	while (a == 1)
	{
		while (1)
		{
			std::cout << "Czy chcesz dodac Bota? 1-TAK 2-NIE" << std::endl;
			std::cin >> a;
			if (std::cin.fail() == true || (a != 1 && a != 2))
			{
				std::cout << "wykryto blad. Podaj dane ponownie" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
			}
			else break;
		}
		if (a == 1)
		{
			int _odwaga;
			while (1) {
				std::cout << "W skali od 1 do 3 jak bardzo odwazny ma byc?" << std::endl;
				std::cin >> _odwaga;
				if (std::cin.fail() == true || (_odwaga != 1 && _odwaga != 2 && _odwaga != 3))
				{
					std::cout << "wykryto blad. Podaj dane ponownie" << std::endl;
					std::cin.clear();
					std::cin.ignore(256, '\n');
				}
				else break;
			}
			dodajBota(_odwaga);
		}
	}
	std::cout << "///////////    ZACZYNAMY GRE    ///////////" << std::endl;
	for (int i = 0; i < rozmiarTab; ++i)
	{
		tablica[i]->wezKarte(dajKarte());
		tablica[i]->wezKarte(dajKarte());
	}
	do
	{
		for (int i = 0; i < rozmiarTab; ++i)
		{
			if (tablica[i]->czyPass() == 0)
			{
				tablica[i]->pokazReke();
				if (tablica[i]->decyzja() == 1)
					tablica[i]->wezKarte(dajKarte());
			}
		}
		for (int i = 0; i < rozmiarTab; ++i)
			tablica[i]->autoPass();

		gramydalej = 0;

		for (int i = 0; i < rozmiarTab; ++i)
		{
			if (tablica[i]->czyPass() == 0)
				gramydalej = 1;
		}
	} while (gramydalej == 1);
	std::cout << "Koncowe rece wszystkich graczy:" << std::endl;
	for (int i = 0; i < rozmiarTab; ++i)
		tablica[i]->pokazReke();
	std::cout << "WYBIERANIE ZWYCIEZCY" << std::endl;
	std::cout << "Wygral: ";
	zwyciezca()->podajNazwe();
}

Gracz* Kasyno::zwyciezca()
{
	Gracz* zwyciezca = nullptr;
	for (int i = 0; i < rozmiarTab; ++i)
	{
		if (tablica[i]->zliczPunkty() <= 21)
			zwyciezca = tablica[i];
	}
	for (int i = 0; i < rozmiarTab; ++i)
	{
		if (tablica[i]->zliczPunkty() <= 21 && tablica[i]->zliczPunkty() > zwyciezca->zliczPunkty())
			zwyciezca = tablica[i];
	}
	return zwyciezca;
}

void Kasyno::zapisz()
{
	std::ofstream plik;
	plik.open("Wyniki.txt", std::ifstream::out);
	for (int i = 0; i < rozmiarTab; ++i)
	{
		plik << tablica[i]->wezNazwe() << "\t";
		for (int j = 0; j < tablica[i]->pobierzRozmiar(); ++j)
		{
			plik << tablica[i]->zwrocKarte(j).getFigura() << tablica[i]->zwrocKarte(j).getKolor();
		}
		plik << "\t" << tablica[i]->zliczPunkty();
		plik << std::endl;
	}
	plik.close();
}

void Kasyno::dodajBota(int _odwaga)
{
	if (rozmiarTab >= 6)
	{
		std::cout << "Nie mozna dodac wiecej niz 6 graczy" << std::endl;
	}
	else
	{
		if (iloscBotow == 0)
		{
			iloscBotow = 1;
			rozmiarTab++;
			listaBotow = new Komputer[iloscBotow];
			listaBotow[0].ustawOdwage(_odwaga);
			listaBotow[0].ustawNazwe(1);
			tablica[rozmiarTab - 1] = &listaBotow[0];

		}
		else
		{
			Komputer *temp = nullptr;
			iloscBotow++;
			rozmiarTab++;
			temp = new Komputer[iloscBotow];
			for (int i = 0; i < iloscBotow - 1; ++i)
			{
				temp[i].ustawNazwe(i);
				temp[i].ustawOdwage(listaBotow[i].wezOdwage());
			}
			temp[iloscBotow - 1].ustawNazwe(iloscBotow);
			temp[iloscBotow - 1].ustawOdwage(_odwaga);
			delete[] listaBotow;
			listaBotow = new Komputer[iloscBotow];
			for (int i = 0; i < iloscBotow; ++i) {
				listaBotow[i].ustawNazwe(i);
				listaBotow[i].ustawOdwage(temp[i].wezOdwage());
				tablica[iloscGraczy + i] = &listaBotow[i];
			}
			delete[] temp;
		}
	}
}

void Kasyno::dodajGracza()
{
	if (rozmiarTab >= 6)
	{
		std::cout << "Nie mozna dodac wiecej niz 6 graczy." << std::endl;
	}
	else {
		if (iloscGraczy == 0)
		{
			iloscGraczy = 1;
			rozmiarTab = 1;
			listaGraczy = new Gracz[iloscGraczy];
			listaGraczy[iloscGraczy - 1].ustawNazwe();
			tablica[rozmiarTab - 1] = &listaGraczy[iloscGraczy - 1];
		}
		else
		{
			Gracz *temp = nullptr;
			iloscGraczy++;
			rozmiarTab++;
			temp = new Gracz[iloscGraczy];
			for (int i = 0; i < iloscGraczy - 1; ++i)
			{
				temp[i] = listaGraczy[i];
			}
			temp[iloscGraczy - 1].ustawNazwe();
			delete[] listaGraczy;
			listaGraczy = new Gracz[iloscGraczy];
			for (int i = 0; i < iloscGraczy; ++i)
			{
				listaGraczy[i] = temp[i];
				tablica[i] = &listaGraczy[i];
			}
			delete[] temp;
		}
	}
}

void Kasyno::wypiszTalie()
{
	for (int i = 0; i < 52; ++i)
	{
		std::cout << i << ":";
		talia[i].wypisz();
		std::cout << "\t";
	}
}