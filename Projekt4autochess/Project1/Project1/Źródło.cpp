#include <iostream>
#include <string>
#include "Rozgrywka.h"
#include "Druzyna.h"
#include "Postac.h"
#include "Mag.h"
#include "Rycerz.h"
#include "Zabojca.h"


using namespace std;

int main()
{
	Rozgrywka gra1;
	cout << "Witaj w symulatorze rundy gry Dota2 AutoChess" << endl;
	gra1.nazwaGracza();
	gra1.wczytywanie();
	gra1.zakupy();
	gra1.walka();
	if (!(gra1.aDruzyny1().czyZywa()))
		cout << "zwycieza gracz: " << gra1.zwrocNazweG2() << endl;
	else if (!(gra1.aDruzyny2().czyZywa()))
		cout << "zwycieza gracz: " << gra1.zwrocNazweG1()<<endl;
	system("pause");
	return 0;
}