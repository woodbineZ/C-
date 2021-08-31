#include "obrabiarka.h"

obrabiarka::obrabiarka()
{
	rozmiar = 0;
	tab = nullptr;
}

obrabiarka::obrabiarka(int p_rozmiar)
{
	rozmiar = p_rozmiar;
	tab = new czas[rozmiar];
}

obrabiarka::obrabiarka(const obrabiarka &ob1)
{
	rozmiar = ob1.rozmiar;
	tab = new czas[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		tab[i] = ob1.tab[i];
	}
}

obrabiarka::~obrabiarka()
{
	rozmiar = 0;
	delete[] tab;
	tab = nullptr;
}

void obrabiarka::wpiszZklaw()
{	
	for (int i = 0; i < rozmiar; i++)
	{
		tab[i].czytajKlawiature();
	}
}

void obrabiarka::dodaj()
{
	czas timer;
	timer.czytajKlawiature();
	dodaj(timer);
}

void obrabiarka::dodaj(czas timer)
{
	czas *temp = nullptr;
	int r1 = rozmiar + 1;
	temp = new czas[r1];
	for (int i = 0; i < rozmiar; i++)
	{
		temp[i] = tab[i];
	}
	temp[r1-1] = timer;
	delete[] tab;
	tab = temp;
	rozmiar = r1;
}

void obrabiarka::pokazSume()
{
	czas tabALL = czas();
	for (int i = 0; i < rozmiar; i++)
		tabALL = tabALL + tab[i];
	tabALL.wyswietlCzas();
}

void obrabiarka::wypisanie()
{
	for (int i = 0; i < rozmiar; i++)
		tab[i].wyswietlCzas();
}

int obrabiarka::zwrocRozmiar()
{
	return rozmiar;
}

void obrabiarka::pokazCzas(int k)
{
	if (k >= 0 && k <= rozmiar)
		tab[k-1].wyswietlCzas();
	else
		cout << "nie ma takiego elementu w zakresie" << endl;
}

czas obrabiarka::zwrocCzas(int k)
{
	czas timex;
	if (k >= 1 && k <= rozmiar)
	{
		timex = tab[k - 1];
		return timex;
	}
	else
	{
		timex = czas();
		cout << "nie ma takiego elementu w zestawieniu" << endl;
		return	timex;
	}
}

obrabiarka obrabiarka::zakres(czas timery)
{
	czas tempSUM;
	int indeks = 0;
	int ilosc = rozmiar;
	while (tempSUM < timery && indeks < rozmiar)
	{
		tempSUM = tempSUM + tab[indeks];
		if (tempSUM > timery)
			ilosc = indeks;
		else
			indeks++;
	}
	return pierwsze(ilosc);
}

obrabiarka obrabiarka::pierwsze(int n)
{
	obrabiarka temp;
	if (n >= 0 && n <= rozmiar)
	{
		temp = obrabiarka(n);
		for (int i = 0; i < n; i++)
			temp.tab[i] = tab[i];
	}
	return temp;
}

obrabiarka& obrabiarka::operator=(const obrabiarka &ob)
{
	if (&ob == this) return *this;
	delete[] tab;
	rozmiar = ob.rozmiar;
	tab = new czas[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		tab[i] = ob.tab[i];
	}
	return *this;
}