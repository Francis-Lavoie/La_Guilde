#include "Hache.h"
#include "Equipement.h"

Hache::Hache() : Equipement()
{
	nom = "Hache";
	description = "Vous permet de donner des coups a vos adversaires!";
	defense = 5;
	emplacementUtilises = 3;
}

Hache::~Hache()
{

}
