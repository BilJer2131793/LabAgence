#pragma once
#include<string>
class Mission
{
public:

	enum EtatMission
	{
		Disponible,
		EnCours,
		Termine
	};
	//static int MissionCount;

	int numMission;

	std::string objectif;
	int vieDemande;
	int defDemande;
	int attDemande;
	int capDemande;
	int platinum;
	int distance;
	EtatMission etat;

	Mission(std::string _objectif, int _vieDemande, int _defDemande, int _attDemande, int _capDemande, int _platinum, int _disatnce);
	~Mission();
	std::string virtual to_string();


};

