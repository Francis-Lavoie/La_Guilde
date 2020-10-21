#pragma once
#include "Guilde.h"
#include "FactoryAventurier.h"
#include "FactoryQuete.h"
#include <iostream>
#include "Utilities.h"
#include "Chrono.h"

Guilde::Guilde()
{
	orDisponible = 1000;
	finPartie = false;
	menu = nullptr;
	marchand = new Marchand();

	for (int i = 0; i < 2; i++)
		listAventurierRecrutable.push_back(FactoryAventurier::getAventurierNiveau(5));

	for (int i = 0; i < 2; i++)
		listQuetesDisponibles.push_back(FactoryQuete::getRandomQuete());
}

Guilde::~Guilde()
{
	delete(menu);
	delete (marchand);
	for (auto it = listAventurierRecrutable.begin(); it != listAventurierRecrutable.end(); it++)
		delete (*it);

	for (auto it = listQuetesDisponibles.begin(); it != listQuetesDisponibles.end(); it++)
		delete (*it);
}

int Guilde::initialierJeu()
{
	menu = new MenuManager();
	return 0;
}

int Guilde::lancerJeu()
{
	update();
	return 0;
}

int Guilde::update()
{
	int aventurierPeriodNumber = 1;
	int quetePeriodNumber = 1;
	int marchandPeriodNumber = 1;
	win32::Stopwatch timer;
	timer.Start();
	do {
		if (int(timer.ElapsedMilliseconds()) > aventurierPeriodNumber * 2 * 60000)
		{
			listAventurierRecrutable.push_back(FactoryAventurier::getRandomAventurier());
			aventurierPeriodNumber++;
		}
		if (int(timer.ElapsedMilliseconds()) > quetePeriodNumber * 5 * 60000)
		{
			listQuetesDisponibles.push_back(FactoryQuete::getRandomQuete());
			quetePeriodNumber++;
		}
		if (int(timer.ElapsedMilliseconds()) > marchandPeriodNumber * 10 * 60000)
		{
			if (marchand->getIsPresent())
				marchand->setIsPresent(false);
			else
				marchand->setIsPresent(true);
			marchandPeriodNumber++;
		}
		updateMenu();
	} while (!finPartie);
	timer.Stop();

	return 0;
}

int Guilde::updateMenu()
{
	menu->afficherRessources(orDisponible);
	menu->afficherActions();

	int choix = Utilities::saisirNombre(1, 6);

	switch (choix)
	{
	case 1:
		cout << to_string();
		Utilities::waitKey(); break;
	case 2:
		optionSelectionnerHero();  break;
	case 3:
		Utilities::clearConsole();
		if (optionEnvoyerAventurierQuete(tabAventurier) == 1)
			cout << "Quete completee avec succes";
		else
			cout << "Echec de la quete";
		Utilities::waitKey(); break;
	case 4: optionAcheterEquipement(); break;
	case 5: optionEnleverEquipement(); break;
	case 6: finPartie = true; break;
	default: cout << "Choix invalide" << endl;
		break;
	}
	return 0;
}

void Guilde::optionSelectionnerHero()
{
	Aventurier* aventurierChoisi = nullptr;
	aventurierChoisi = Guilde::selectionnerHero();
	if (aventurierChoisi != nullptr)
		Guilde::recruterHero(aventurierChoisi);
}

void Guilde::optionAcheterEquipement()
{
	Aventurier* aventurierChoisi = nullptr;
	Equipement* equipementChoisi = nullptr;
	if (marchand->getIsPresent())
	{
		do {
			Utilities::clearConsole();
			menu->afficherGuilde(tabAventurier);
			cout << marchand->to_string() << endl;

			//Choix aventurier
			cout << "\n\nVeuillez entrez un numero daventurier valide";
			cout << "\nAppuyez sur " << std::to_string(tabAventurier.size() + 1) << " pour quitter";

			int choix = Utilities::saisirNombre(1, tabAventurier.size() + 1);
			if (choix == tabAventurier.size() + 1)
				return;

			vector<Aventurier*>::iterator it = tabAventurier.begin();
			advance(it, choix - 1);
			aventurierChoisi = *it;

			//Choix equipement
			cout << "\n\nVeuillez entrer un numero dequipement valide";
			cout << "\nAppuyez sur " << std::to_string(marchand->getEquipements().size() + 1) << " pour quitter";

			choix = Utilities::saisirNombre(1, marchand->getEquipements().size() + 1);
			if (choix == marchand->getEquipements().size() + 1)
				return;
			list<Equipement*>::iterator itE = marchand->getEquipements().begin();
			advance(it, choix - 1);
			equipementChoisi = *itE;
		} while (equipementChoisi->getEmplacementUtilise() > aventurierChoisi->getNbEmplacementLibres());

		aventurierChoisi->addEquipement(equipementChoisi);
	}
	else
		cout << marchand->to_string();
	Utilities::waitKey();
}

Aventurier* Guilde::selectionnerHero()
{
	menu->afficherAventurierRecrutable(listAventurierRecrutable);
	int choix = Utilities::saisirNombre(1, listAventurierRecrutable.size() + 1);

	if (choix == listAventurierRecrutable.size() + 1)
		return nullptr;

	//Utilisation d'un itérateur et avancement de celui-ci
	list<Aventurier*>::iterator it = listAventurierRecrutable.begin();
	advance(it, choix - 1);

	return (*it);
}

void Guilde::recruterHero(Aventurier* aventurier)
{
	tabAventurier.push_back(aventurier);
	listAventurierRecrutable.remove(aventurier);
}

int Guilde::optionEnvoyerAventurierQuete(vector<Aventurier*> tabAventuriers)
{
	Aventurier* aventurierChoisi = nullptr;
	Quete* queteChoisie = nullptr;
	do {
		menu->afficherGuilde(tabAventuriers);
		menu->afficherQuetesDisponibles(listQuetesDisponibles);

		//Choix aventurier
		cout << "\n\nVeuillez entrez un numero daventurier valide";
		cout << "\nAppuyez sur " << std::to_string(tabAventurier.size() + 1) << " pour quitter";

		int choix = Utilities::saisirNombre(1, tabAventurier.size() + 1);
		if (choix == tabAventurier.size() + 1)
			return 0;

		vector<Aventurier*>::iterator it = tabAventurier.begin();
		advance(it, choix - 1);
		aventurierChoisi = *it;

		//Choix quete
		cout << "\n\nVeuillez entrez un numero de quete valide";
		cout << "\nAppuyez sur " << std::to_string(listQuetesDisponibles.size() + 1) << " pour quitter";

		choix = Utilities::saisirNombre(1, listQuetesDisponibles.size() + 1);
		if (choix == listQuetesDisponibles.size() + 1)
			return 0;

		list<Quete*>::iterator itQuete = listQuetesDisponibles.begin();
		advance(itQuete, choix - 1);
		queteChoisie = *itQuete;
	} while (aventurierChoisi->getNiv() < queteChoisie->getNiveauMin());
	//On tente la quete lorsque cest valide
	int succes = queteChoisie->tenterQuete(aventurierChoisi);
	if (succes == 1)
		ajouterRecompense(aventurierChoisi, queteChoisie);
	return succes;
}

void Guilde::ajouterRecompense(Aventurier* aventurier, Quete* quete)
{
	aventurier->addXp(quete->getXpDonne());
}

void Guilde::optionEnleverEquipement()
{
	if (tabAventurier.size() > 0)
	{
		menu->afficherGuilde(tabAventurier);
		cout << "\nVeuillez choisir l'aventurier que vous voulez modifier" << endl;
		int choix = Utilities::saisirNombre(1, tabAventurier.size());

		vector<Aventurier*>::iterator itAventuriers = tabAventurier.begin();

		if (choix - 1 != tabAventurier.size())
			advance(itAventuriers, choix - 1);
		else
			return;

		Aventurier* aventurierChoisi = *itAventuriers;
		list<Equipement*> equipements = aventurierChoisi->getEquipements();

		//for (auto it = aventurierChoisi->getEquipements().begin(); it != aventurierChoisi->getEquipements().end(); ++it)
		Utilities::clearConsole();
		int i = 0;
		for (auto it = equipements.begin(); it != equipements.end(); it++)
		{
			i++;
			cout << i << "." << (*it)->to_string();
		}
		cout << "\nVeuillez choisir l'equipement a retirer";
		choix = Utilities::saisirNombre(1, equipements.size());

		aventurierChoisi->supprimerEquipement(choix - 1);

		Utilities::waitKey();
	}
	else
		cout << "Vous n'avez pas d'aventuriers pour l'instant";
}

string Guilde::to_string()
{
	string flux = "";
	for (auto it = tabAventurier.begin(); it != tabAventurier.end(); it++)
		flux += (*it)->to_string();
	return flux;
}
