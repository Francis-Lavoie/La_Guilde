#pragma once
#include "Aventurier.h"
#include "Quete.h"
#include <vector>
#include <list>
#include "MenuManager.h"

class Guilde
{
private:
	int orDisponible;
	bool finPartie;
	vector<Aventurier*> tabAventurier;
	list<Aventurier*> listAventurierRecrutable;
	list<Quete*> listQuetesDisponibles;
	MenuManager* menu;
	void recruterHero(Aventurier* aventurier);
	int update();
	int updateMenu();
	Aventurier* selectionnerHero();
	int optionEnvoyerAventurierQuete(vector<Aventurier*> tabAventuriers);
	void optionSelectionnerHero();
	void optionEnleverEquipement();
	void optionAcheterEquipement();
	void ajouterRecompense(Aventurier* aventurier, Quete* quete);
	Marchand* marchand;

public:
	Guilde();
	~Guilde();
	int initialierJeu();
	int lancerJeu();
	string to_string();
};

