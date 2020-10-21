#include "Bouclier.h"

Bouclier::Bouclier() : Equipement()
{
	nom = "Bouclier";
	description = "Vous permet d'absorber les coups des adversaires!";
	defense = 10;
	emplacementUtilises = 3;
}

Bouclier::~Bouclier()
{

}
