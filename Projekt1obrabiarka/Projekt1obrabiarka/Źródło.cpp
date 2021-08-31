#include <iostream>
#include "czas.h"
#include "obrabiarka.h"

int main()
{
	czas timer1=czas(13, 23, 0), timer2=czas(7, 19, 0)
		, timer3=czas(7, 17, 1), timer4=czas(3, 6, 2)
		, timer5=czas(21, 20, 0), timer6=czas(18, 10, 1)
		, timer7=czas(29, 0, 2);
	obrabiarka frezarka;
	frezarka.dodaj(timer1);
	frezarka.dodaj(timer2);
	frezarka.dodaj(timer3);
	frezarka.dodaj(timer4);
	frezarka.dodaj(timer5);
	frezarka.dodaj(timer6);
	frezarka.dodaj(timer7);
		
		
		
	int ile;
	czas licznik;
/*	cout << "Witaj w menu obrabiarki. Podaj jak duzo zestawien czasow chcialbys miec w obrabiarce" << endl;
	while (!(cin >> ile) || ile<0)
	{
		cout << "Podano niepoprawne dane. Nalezy podac liczbe calkowita wieksza od 0" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}*/
	frezarka.wypisanie();
	//obrabiarka frezarka = obrabiarka(ile);
	cout << "Ustaw zakres licznika" << endl;
	licznik.czytajKlawiature();
	cout << "dodaj czasy do obrabiarki" << endl;
///	frezarka.wpiszZklaw();
	
	obrabiarka frezarkaZzakresem;
	frezarkaZzakresem=frezarka.pierwsze(-2);
	cout << "Czasy obrabiarki z zakresu:   "; 
	licznik.wyswietlCzas();
	frezarkaZzakresem.wypisanie();
	cout << "suma twoich obecnych czasow to:" << endl;
	frezarkaZzakresem.pokazSume();
	frezarka.pokazCzas(2);
	
	cin.get(); cin.get();
	return 0;
}
