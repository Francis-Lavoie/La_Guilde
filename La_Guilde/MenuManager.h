#pragma once
#include <list>
#include <vector>
#include "Aventurier.h"
#include "Quete.h"

using namespace std;

class MenuManager
{
public:
	MenuManager();
	void afficherActions();
	void afficherAventurierRecrutable(list<Aventurier*> listAventurierRecrutables);
	//void afficherChoixPossibleRecrutement(list<Aventurier*> listAventurierRecrutables);
	void afficherRessources(int orDisponible);
	void afficherGuilde(vector<Aventurier*> tabAventurier);
	void afficherQuetesDisponibles(list<Quete*> listQuetesDisponibles);
};

