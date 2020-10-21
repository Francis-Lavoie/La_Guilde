#include "Race.h"

Race::Race()
{
	Race(0, 0, 0, 0);
}

Race::Race(int attaque, int defense, int vie, int chance)
{
	nom = "";
	this->attaque = attaque;
	this->defense = defense;
	this->vie = vie;
	this->chance = chance;
}

Race::~Race()
{

}

string Race::getNom()
{
	return nom;
}

int Race::getAttaque()
{
	return attaque;
}

int Race::getDefense()
{
	return defense;
}

int Race::getVie()
{
	return vie;
}

int Race::getChance()
{
	return chance;
}
