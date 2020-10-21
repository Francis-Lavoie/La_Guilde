#include "Archer.h"

Archer::Archer():Aventurier("Archer",1,0)
{
	attaque = 50;
	defense = 75;
	vie = 75;
}

Archer::~Archer()
{

}

string Archer::to_string()
{
	return Aventurier::to_string() + "\nJe suis un archer\n";
}

