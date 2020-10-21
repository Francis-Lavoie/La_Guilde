#include "Aventurier.h"
#include <iostream>
#include "Utilities.h"

Aventurier::Aventurier()
{
	vie = 0;
	attaque = 0;
	defense = 0;
	chance = 0;
	niveau = 1;
	exp = 0;
	nom = "";
	race = nullptr;
	occupe = false;

	for (int i = 0; i < sizeof(tabEmplacement) / sizeof(tabEmplacement[0]); i++)
		tabEmplacement[i].setUtilise(false);
}

Aventurier::Aventurier(string nom, int niveau, int xp) : Aventurier()
{
	this->nom = nom;
	this->niveau = niveau;
	this->exp = xp;
}

Aventurier::~Aventurier()
{
	delete race;
	for (auto it = listEquipements.begin(); it != listEquipements.end(); it++)
		delete (*it);
}

void Aventurier::setRace(Race* race)
{
	this->race = race;
	attaque += race->getAttaque();
	defense += race->getDefense();
	vie += race->getVie();
	chance += race->getChance();
}

int Aventurier::getAtt() 
{
	return attaque;
}

int Aventurier::getDef()
{
	return defense;
}

int Aventurier::getVie()
{
	return vie;
}

int Aventurier::getNiv()
{
	return niveau;
}

int Aventurier::getNbEmplacementLibres()
{
	int cpt = 0;
	for (int i = 0; i < sizeof(tabEmplacement) / sizeof(tabEmplacement[0]);i++)
		if (tabEmplacement[i].getUtilise() == false)
			cpt++;
	return cpt;
}

Emplacement* Aventurier::getEmplacements()
{
	return tabEmplacement;
}

string Aventurier::to_string()
{
	string flux = "";
	flux += "Nom : " + nom + "\nRace : " + race->getNom() + "\nStatut : " + (occupe == true ? "Occupé" : "Libre") +"\nAttaque : " + std::to_string(attaque) + "\nDefense : " + std::to_string(defense) + "\nVie : " + std::to_string(vie);
	flux += "\nChance :  " + std::to_string(chance) + "\nNiveau : " + std::to_string(niveau) + "\nExp : " + std::to_string(exp);
	flux += "\n\n*****Equipements*****\n";

	for (auto it = listEquipements.begin(); it != listEquipements.end(); it++)
		flux +=(*it)->to_string();
	flux += "\n";
	return flux;
}

list<Equipement*> Aventurier::getEquipements()
{
	return listEquipements;
}

void Aventurier::setOccupe(bool etat)
{
	occupe = etat;
}

void Aventurier::setNiveau(int niveau)
{
	if (niveau > 100)
		niveau = 100;
	else if (niveau < 1)
		niveau = 1;
	this->niveau = niveau;
}

void Aventurier::addEquipement(Equipement* equipement)
{
	if (equipement->getEmplacementUtilise() <= getNbEmplacementLibres())
	{
		listEquipements.push_back(equipement);
		for (int i = 0; i < equipement->getEmplacementUtilise(); i++)
			for (int j = 0; j < 5; i++)
				if (tabEmplacement[i].getUtilise() == false)
				{
					tabEmplacement[i].setUtilise(true);
					break;
				}
	}
	else 
	{
		cout << "Impossible d'ajouter l'equipement, l'aventurier n'a plus de place!" << endl;
		//Utilities::waitKey();
	}
}

void Aventurier::addXp(int xp)
{
	this->exp += xp;
}

void Aventurier::supprimerEquipement(int index)
{
	list<Equipement*>::iterator itEquipements = this->listEquipements.begin();
	advance(itEquipements, index);
	this->listEquipements.erase(itEquipements);
}