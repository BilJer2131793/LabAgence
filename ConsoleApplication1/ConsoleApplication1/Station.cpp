#include "Station.h"


Station::Station()
{
}

Station::~Station()
{
}
void Station::Init() {
	for (int i = 0; i < 3;)
		vecVaisseau.push_back(FactoryVaisseau::getRandomVaisseau());
}
vector<Vaisseau*> Station::getVaisseauDispo() { return vecVaisseau; }
void Station::ajouterVaisseau(Vaisseau* vaisseau) { vecVaisseau.push_back(vaisseau); }