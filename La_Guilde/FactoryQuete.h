#pragma once
#include "Quete.h"

using namespace std;

class FactoryQuete
{
public:
    static Quete* getRandomQuete();
    static Quete* getQuete(string difficulte, string nom, int niveauMin, int xpDonne);
    static Quete* getRandomQuete(int difficulteNumber);

private:
    static string getNomQuete();
};

