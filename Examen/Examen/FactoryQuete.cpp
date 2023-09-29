#include "FactoryQuete.h"


Quete* FactoryQuete::getRandomQuete()
{
	Quete* quete;
	Quete::difficulte nivDifficulte;
	int nivMin;
	int recompense;
	int exp;
	int probabilite = genererNB(1, 100);

	if (probabilite <= 75)
	{
		nivDifficulte = Quete::difficulte::Facile;
		nivMin = genererNB(1, 10);
		recompense = genererNB(100, 1000);
		exp = genererNB(100, 2000);
	}
	else if (probabilite <= 90) 
	{
		nivDifficulte = Quete::difficulte::Moyen;
		nivMin = genererNB(10, 25);
		recompense = genererNB(1000, 5000);
		exp = genererNB(2000, 4000);
	}
	else
	{
		nivDifficulte = Quete::difficulte::Difficile;
		nivMin = genererNB(25, 99);
		recompense = genererNB(5000, 35000);
		exp = genererNB(4000, 14000);
	}

	quete = new Quete("Quete", nivDifficulte, nivMin, recompense, exp);

	return quete;
}
int FactoryQuete::genererNB(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}