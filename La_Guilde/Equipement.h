#pragma once
#include <string>

using namespace std;

class Equipement
{
public:
	Equipement();
	~Equipement();
	string getNom();
	string getDescription();
	int getAttaque();
	int getDefense();
	int getChance();
	int getVie();
	int getEmplacementUtilise();

protected:
	string nom;
	string description;
	int attaque;
	int defense;
	int chance;
	int vie;
	int emplacementUtilises;

public:
	  virtual string to_string() final;
};

