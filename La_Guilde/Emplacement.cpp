#include "Emplacement.h"

Emplacement::Emplacement()
{
	utilise = false;
}

Emplacement::~Emplacement()
{

}

bool Emplacement::getUtilise()
{
	return utilise;
}

void Emplacement::setUtilise(bool utilise)
{
	this->utilise = utilise;
}
