#pragma once
#include <string>
#include "Race.h"
#include <list>
#include "Emplacement.h"
#include "Equipement.h"
#include "Marchand.h"

using namespace std;

class Aventurier
{
public:
	Aventurier();
	Aventurier(string nom, int niveau, int xp);
	void setRace(Race* race);
	int getAtt();
	int getDef();
	int getVie();
	int getNiv();
	int getNbEmplacementLibres();
	Emplacement* getEmplacements();
	void setOccupe(bool etat);
	void setNiveau(int niveau);
	virtual string to_string();
	~Aventurier();
	void addEquipement(Equipement* equipement);
	list<Equipement*> getEquipements();
	void addXp(int xp);
	void supprimerEquipement(int index);

private:
	int valeurMarchande;

protected:
	int attaque;
	int defense;
	int vie;
	int chance;
	int niveau;
	int exp;
	Race* race;
	string nom;
	bool occupe;
	Emplacement tabEmplacement[5];
	list<Equipement*> listEquipements;
};


