#include "MenuManager.h"
#include <iostream>
#include <vector>
#include "Utilities.h"

MenuManager::MenuManager()
{

}

void MenuManager::afficherActions()
{
	Utilities::clearConsole();
	cout << "1. Afficher votre guilde" << endl;
	cout << "2. Selectionner un nouvel aventurier" << endl;
	cout << "3. Envoyer un aventurier en quete" << endl;
	cout << "4. Acheter equipement au marchand" << endl;
	cout << "5. Enlever un equipement a un aventurier" << endl;
	cout << "6. Quitter" << endl;
}

void MenuManager::afficherAventurierRecrutable(list<Aventurier*> listAventurierRecrutables)
{
	int i = 0;
	cout << endl;
	for (auto it = listAventurierRecrutables.begin(); it != listAventurierRecrutables.end(); it++)
	{ 
		i++;
		cout << i << "." << (*it)->to_string() << endl;
	}
	cout << (i + 1) << ".Revenir au menu principal";
}

void MenuManager::afficherRessources(int orDisponible)
{
	cout << "\nOr disponible : " << orDisponible << endl << endl;
}

void MenuManager::afficherGuilde(vector<Aventurier*> tabAventurier)
{
	int i = 0;
	cout << endl;
	for (auto it = tabAventurier.begin(); it != tabAventurier.end(); it++) 
	{
		i++;
		cout << i << "." << (*it)->to_string() << endl; 
	}
	cout << (i + 1) << ".Revenir au menu principal";
}

void MenuManager::afficherQuetesDisponibles(list<Quete*> listQuetesDisponibles)
{
	int i = 0;
	cout << endl;
	for (auto it = listQuetesDisponibles.begin(); it != listQuetesDisponibles.end(); it++)
	{
		i++;
		cout << endl << i << "." << (*it)->to_string() << endl;
	}
	cout << (i + 1) << ".Revenir au menu principal";
}

