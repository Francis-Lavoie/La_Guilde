#include "Guerrier.h"

Guerrier::Guerrier():Aventurier("Guerrier",1,0)
{
	attaque = 50;
	defense = 50;
	vie = 100;
}

Guerrier::~Guerrier()
{

}

string Guerrier::to_string()
{
	return Aventurier::to_string() + "\nJe suis un guerrier\n";
}
