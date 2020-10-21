#include "Quete.h"
#include "Utilities.h"
#include <iostream>

Quete::Quete(string difficulte, string nom, int niveauMin, int xpDonne)
{
	this->difficulte = difficulte;
	this->nom = nom;
	this->niveauMin = niveauMin;
	this->xpDonnee = xpDonne;
}

int Quete::tenterQuete(Aventurier* aventurier)
{
	aventurier->setOccupe(true);
	for (int i = 120; i > 0; i--)
	{
		Utilities::clearConsole();
		cout << "L'aventurier tente la quete "  << i << " secondes restantes" << endl;
		Sleep(1000);
	}
	return Utilities::generateRandom(0, 1);
}

string Quete::to_string()
{
	return "Nom : " + nom + "\nDifficulte : " + difficulte + "\nNiveau minimal : " + std::to_string(niveauMin) + "\nXp recue : " + std::to_string(xpDonnee);
}

int Quete::getNiveauMin()
{
	return niveauMin;
}

int Quete::getXpDonne()
{
	return xpDonnee;
}

string Quete::getNom()
{
	return nom;
}

string Quete::getDifficulte()
{
	return difficulte;
}
