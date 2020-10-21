#include "Epee.h"
#include "Equipement.h"

Epee::Epee() : Equipement()
{
	nom = "Epee";
	description = "Vous permet de donner des coups rapides a vos adversaires!";
	attaque = 5;
	emplacementUtilises = 2;
}

Epee::~Epee()
{

}
