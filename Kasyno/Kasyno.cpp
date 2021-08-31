#include "Kasyno.h"

Kasyno::Kasyno()
{
		for (int i = 0; i < 13; ++i) {
			Talia[i].setKolor(0);
			Talia[i + 13].setKolor(1);
			Talia[i + 26].setKolor(2);
			Talia[i + 39].setKolor(3);
		}
		for (int j = 0; j < 13; ++j) {
			Talia[j].setWartosc(j);
			Talia[j+13].setWartosc(j);
			Talia[j + 26].setWartosc(j);
			Talia[j + 29].setWartosc(j);
		}
}
Kasyno::~Kasyno() {}
void Kasyno::Tasuj()
{
	int losowa1;
	int losowa2;
	Karta K1;
	Karta K2;
	int kolorTemp1;
	int kolorTemp2;
	int wartoscTemp1;
	int wartoscTemp2;
	for (int i = 0; i < 100; ++i)
	{
		do 
		{
			losowa1 = (std::rand() % 52);
			losowa2 = (std::rand() % 52);
		} while (losowa1 == losowa2);

			kolorTemp1 = Talia[losowa1].dajKolor();
			wartoscTemp1 = Talia[losowa1].dajWartosc();
			kolorTemp2 = Talia[losowa1].dajKolor();
			wartoscTemp2 = Talia[losowa1].dajWartosc();

			Talia[losowa1].setKolor(kolorTemp2);
			Talia[losowa1].setWartosc(wartoscTemp2);
			Talia[losowa2].setKolor(kolorTemp1);
			Talia[losowa2].setWartosc(wartoscTemp1);
	}
}
Karta * Kasyno::dajKarte()
{

}