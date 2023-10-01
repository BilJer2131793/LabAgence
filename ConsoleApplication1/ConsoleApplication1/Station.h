#pragma once
#include <iostream>
#include "Vaisseau.h"
#include "FactoryVaisseau.h"
#include "Mission.h"
#include <windows.h>
#include <vector>
#include <iterator>
#include <list>
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
	std::list<Mission*> missions;


public:
	Station();
	~Station();
	void Jeux();
	vector<Vaisseau*> getVaisseauDispo();
	void Init();
	void ajouterVaisseau(Vaisseau* vaisseau);
	int AfficherVaisseau();

	//Section Mission
	std::list<Mission*> GenereMission();
	Mission* ObjectifMission(int mission);
	Mission* getMission(int _i);
	void Missions();
	void DemarerMission(string objectif);
	void CheckMissionEnCours();
	void CheckMissionFini();
	int AfficherMission();
	bool CheckSpecVaisseau(Vaisseau* v, Mission* m);

	//Section Magasin
	void Magasin();
	inline bool CheckArgent(int montant);
	inline bool CheckCapacite();
	void ReparerVaisseau();
	void AcheterVaisseau();
	void AugmenterVaisseau();
	void AugmenterStat(int v);
	void VendreVaisseau();
	void clear_screen(char fill);
};

