#include "FactoryVaisseau.h"
#include "Guerre.h"
#include "Transport.h"
#include "Livraison.h"

FactoryVaisseau::FactoryVaisseau()
{

}

FactoryVaisseau::~FactoryVaisseau()
{

}

int FactoryVaisseau::genererNB(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}

Vaisseau* FactoryVaisseau::getRandomVaisseau()
{
	Vaisseau* vaisseau(0);

	Faction* maFaction = getRandomFaction();


	int typeV = genererNB(1, 3);
	if (typeV == 1) {
		vaisseau = new Guerre(maFaction);
	}
	else if (typeV == 2) {
		vaisseau = new Transport(maFaction);
	}
	else if (typeV == 3){
		vaisseau = new Livraison(maFaction);
	}

	return vaisseau;

}
Faction* FactoryVaisseau::getRandomFaction()
{
	int typeF = FactoryVaisseau::genererNB(1, 2);
	Faction* f(0);
	if (typeF == 1) {
		f = new Faction("Rouge", 1, 2, 3, 4);
	}
	else if (typeF == 2)
	{
		f = new Faction("Bleur", 4, 3, 2, 1);
	}

	return f;
}