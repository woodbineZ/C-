#pragma once
#include "Gracz.h"

class Komputer : public Gracz
{
	private:
		int odwaga;
	public:
		Komputer();
		Komputer(int _odwaga) : Gracz(), odwaga(_odwaga) {}
		virtual bool decyzja();
		int wezOdwage() { return odwaga; }
		void ustawOdwage(int _odwaga);
		void ustawNazwe(int _iloscBotow);
};
