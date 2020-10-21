#pragma once
#include "Aventurier.h"
class FactoryAventurier
{
public:
	static Aventurier* getRandomAventurier();
	static Aventurier* getAventurierNiveau(int niveauMax);
	static Equipement* getRandomEquipement();
};

