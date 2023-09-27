#pragma once
#include <iostream>
#include "Vaisseau.h"
#include "FactoryVaisseau.h"
#include <windows.h>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

class Station
{
private:
	int platinumDispo;
	int vieStation;
	int capMax;
	vector<Vaisseau*> vecVaisseau;


public:
	Station();
	~Station();
	vector<Vaisseau*> getVaisseauDispo();
	void Init();
	void ajouterVaisseau(Vaisseau* vaisseau);
	void AfficherVaisseau();

	//Section Magasin
	void Magasin();
	inline bool CheckArgent(int montant);
	inline bool CheckCapacite();
	void ReparerVaisseau();
	void AcheterVaisseau();
	void AugmenterVaisseau();
	void VendreVaisseau();
	void clear_screen(char fill);
};

