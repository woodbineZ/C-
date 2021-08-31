#include"Gracz.h"

Gracz::Gracz()
{
	rozmiar = 0;
}

Gracz::~Gracz() {}


int Gracz::PobierzRozmiar()
{
	return rozmiar;
}

int Gracz::ZliczPunkty()
{
	int suma=0;
	for (int i = 0; i < rozmiar; ++i) {
		suma=suma+reka[i].dajWartosc;
	}
	return suma;
}

void Gracz::WezKarte(Karta * _karta)
{

}

void Gracz::PokazReke()
{
	for (int i = 0; i < rozmiar; ++i) {
		reka[i].wyswietlKarte();
	}
}
