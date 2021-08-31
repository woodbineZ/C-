#include <iostream>
#include<cstdlib>
#include<time.h>
#include"Kasyno.h"
#include"Gracz.h"
#include"Karta.h"

int main()
{
	srand(time(NULL));
	Kasyno munnyville;
	
	for (int i = 0; i < 52; ++i)
	{
		munnyville.Talia[i].wyswietlKarte();
	}
	munnyville.Tasuj();
	std::cout << std::endl;
	for (int i = 0; i < 52; ++i)
	{
		munnyville.Talia[i].wyswietlKarte();
	}
	system("PAUSE");
	return 0;
}