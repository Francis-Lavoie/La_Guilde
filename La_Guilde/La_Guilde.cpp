#include <iostream>
#include "FactoryAventurier.h"
#include <ctime>
#include "Guilde.h"

using namespace std;

int main()
{
	srand(time(NULL));
	/*Aventurier aventurierVar;
	Aventurier* aventurier = FactoryAventurier::getRandomAventurier();
	cout << aventurier->to_string();
	delete aventurier;*/

	Guilde* guilde = new Guilde();
	guilde->initialierJeu();
	guilde->lancerJeu();
	delete (guilde);
}
