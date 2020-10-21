#include "FerCheval.h"

FerCheval::FerCheval() :Equipement()
{
	nom = "Fer a cheval";
	description = "Ce fer a cheval vous porte chance!";
	chance = 8;
	emplacementUtilises = 1;
}

FerCheval::~FerCheval()
{

}
