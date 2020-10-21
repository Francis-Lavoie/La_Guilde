#include "FactoryAventurier.h"
#include "Utilities.h"
#include "Races.h"
#include "Aventuriers.h"
#include "Equipements.h"

Aventurier* FactoryAventurier::getRandomAventurier()
{
	Aventurier* aventurier = new Aventurier();
	Race* race = nullptr;
	Equipement* equipement = nullptr;
	int randomNombre = Utilities::generateRandom(1, 3);
	//Type d'aventurier
	switch (randomNombre)
	{
	case 1:aventurier = new Archer(); break;
	case 2:aventurier = new Chevalier(); break;
	case 3:aventurier = new Guerrier(); break;
	}

	randomNombre = Utilities::generateRandom(1, 3);
	//Race
	switch (randomNombre)
	{
	case 1:race = new Bete(); break;
	case 2:race = new Elf(); break;
	case 3:race = new Humain(); break;
	}

	//Equipement
	equipement = FactoryAventurier::getRandomEquipement();

	aventurier->addEquipement(equipement);
	aventurier->setRace(race);
	return aventurier;
}

Aventurier* FactoryAventurier::getAventurierNiveau(int niveauMax)
{
	Aventurier* aventurier = FactoryAventurier::getRandomAventurier();
	aventurier->setNiveau(Utilities::generateRandom(1, niveauMax));
	return aventurier;
}

Equipement* FactoryAventurier::getRandomEquipement()
{
	int randomNombre = Utilities::generateRandom(1, 5);
	switch (randomNombre)
	{
	case 1: return new Bouclier(); break;
	case 2: return new Hache(); break;
	case 3: return new Epee(); break;
	case 4: return new Peau(); break;
	case 5: return new FerCheval(); break;
	}
}


