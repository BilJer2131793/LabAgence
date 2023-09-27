#pragma once
#include "Vaisseau.h";
class FactoryVaisseau
{
public:
	FactoryVaisseau();
	~FactoryVaisseau();
	static Vaisseau* getRandomVaisseau();
	static Vaisseau* GenererVaisseau(int typeV);
	static int genererNB(int min, int max);

private:
	static Faction* getRandomFaction();


};

