#include "FactoryQuete.h"
#include "Utilities.h"

Quete* FactoryQuete::getQuete(string difficulte, string nom, int niveauMin, int xpDonne)
{
	return new Quete(difficulte, nom, niveauMin, xpDonne);
}

Quete* FactoryQuete::getRandomQuete()
{
	int difficulteNumber = Utilities::generateRandom(1, 3);
	return getRandomQuete(difficulteNumber);	
}

Quete* FactoryQuete::getRandomQuete(int  difficulteNumber)
{
	string difficulte = "Facile";
	int niveauMin = 0;
	int xpDonne = 0;

	switch (difficulteNumber)
	{
	case 1:
		niveauMin = 1;
		xpDonne = Utilities::generateRandom(100, 400); break;
	case 2:
		difficulte = "Moyenne";
		niveauMin = 5;
		xpDonne = Utilities::generateRandom(401, 700); break;
	case 3:
		difficulte = "Difficile";
		niveauMin = 10;
		xpDonne = Utilities::generateRandom(701, 1000); break;
	}

	return new Quete(difficulte, FactoryQuete::getNomQuete(), niveauMin, xpDonne);
}

string FactoryQuete::getNomQuete()
{
	string noms[10];	
	noms[0] = "Tuez le gobelin";
	noms[1] = "Trouvez l'oeuf doré";
	noms[2] = "Echappez au dragon rouge";
	noms[3] = "Retrouvez le parchemin du roi";
	noms[4] = "Retrouvez la lance sacrée";
	noms[5] = "Combattez le grand lutteur de la plaine";
	noms[6] = "Sauvez peach";
	noms[7] = "Sauvez les villageois de l'incendie";
	noms[8] = "Passez innapercu auprès de la gendarmerie";
	noms[9] = "Protégez le chateau";

	return noms[Utilities::generateRandom(0, 9)];
}