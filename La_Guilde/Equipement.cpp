#include "Equipement.h"

Equipement::Equipement()
{
	vie = 0;
	attaque = 0;
	defense = 0;
	chance = 0;
	emplacementUtilises = 0;
	nom = "";
	description = "";
}

Equipement::~Equipement()
{

}

string Equipement::getNom()
{
	return nom;
}

string Equipement::getDescription()
{
	return description;
}

int Equipement::getAttaque()
{
	return attaque;
}

int Equipement::getDefense()
{
	return defense;
}

int Equipement::getChance()
{
	return chance;
}

int Equipement::getVie()
{
	return vie;
}

int Equipement::getEmplacementUtilise()
{
	return emplacementUtilises;
}


string Equipement::to_string()
{
	string flux = "Nom : " + nom + "\nDescription : " + description + "\nEmplacement Utilises : " + std::to_string(emplacementUtilises);
	flux += "\nAttaque : " + std::to_string(attaque) + "\nDefense : " + std::to_string(defense) + "\nVie : " + std::to_string(vie);
	flux += "\nChance : " + std::to_string(chance);
	return flux;
}
