#pragma once
#include <list>
#include "Equipement.h"

class Marchand
{
private:
	list<Equipement*> listEquipementsAVendre;
	bool isPresent;

public:
	Marchand();
	~Marchand();
	list<Equipement*> getEquipements();
	bool getIsPresent();
	void setIsPresent(bool value);
	string to_string();
};

