#include "Marchand.h"
#include "FactoryAventurier.h"

Marchand::Marchand()
{
	for (int i = 0; i < 10; i++)
		listEquipementsAVendre.push_back(FactoryAventurier::getRandomEquipement());
	isPresent = false;
}

Marchand::~Marchand()
{
	for (auto it = listEquipementsAVendre.begin(); it != listEquipementsAVendre.end(); it++)
		delete (*it);
}

list<Equipement*>Marchand::getEquipements()
{
	return listEquipementsAVendre;
}

bool Marchand::getIsPresent()
{
	return isPresent;
}

void Marchand::setIsPresent(bool value)
{
	isPresent = value;
}

string Marchand::to_string()
{
	string flux = "";
	int i = 0;
	flux += isPresent ? "\nLe marchand est resent" : "\nLe marchand est absent\n";
	if (isPresent)
		for (auto it = listEquipementsAVendre.begin(); it != listEquipementsAVendre.end(); it++)
		{
			i++;
			flux += std::to_string(i) + ". " + (*it)->to_string() + "\n";
		}
	return flux;
}

