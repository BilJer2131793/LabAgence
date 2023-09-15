#pragma once
#include "Vaisseau.h"
#include "FactoryVaisseau.h"
#include <vector>
using std::vector;

class Station
{
private:
	int platinumDispo;
	int vieStation;
	vector<Vaisseau*> vecVaisseau;


public:
	Station();
	~Station();
	vector<Vaisseau*> getVaisseauDispo();
	void Init();
	void ajouterVaisseau(Vaisseau* vaisseau);

};

