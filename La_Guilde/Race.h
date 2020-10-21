#pragma once
#include <string>

using namespace std;

class Race
{
public:
	Race();
	Race(int attaque, int defense, int vie, int chance);
	~Race();
	string getNom();
	int getAttaque();
	int getDefense();
	int getVie();
	int getChance();

protected:
	int attaque;
	int defense;
	int vie;
	int chance;
	string nom;
};

