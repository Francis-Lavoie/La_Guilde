#pragma once
#include <string>
#include "Aventurier.h"

using namespace std;

class Quete
{
public:
	Quete(string difficulte, string nom, int niveauMin, int xpDonne);
	int tenterQuete(Aventurier* aventurier);
	string to_string();
	int getNiveauMin();
	int getXpDonne();
	string getNom();
	string getDifficulte();

private:
	string difficulte;
	string nom;
	int niveauMin;
	int xpDonnee;
};

