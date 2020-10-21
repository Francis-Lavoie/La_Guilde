#include "Chevalier.h"

Chevalier::Chevalier():Aventurier("Chevalier",1,0)
{
	attaque = 75;
	defense = 50;
	vie = 75;
}

Chevalier::~Chevalier()
{

}

string Chevalier::to_string()
{
	return Aventurier::to_string() + "\nJe suis un chevalier\n";
}

