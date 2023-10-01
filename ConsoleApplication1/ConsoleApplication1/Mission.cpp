#include "Mission.h"
#include <iostream>

Mission::Mission(std::string _objectif, int _vieDemande, int _defDemande, int _attDemande, int _capDemande, int _platinum, int _disatnce)
{
	//++MissionCount;
	numMission = 1;
	objectif = _objectif;
	vieDemande = _vieDemande;
	defDemande = _defDemande;
	attDemande = _attDemande;
	capDemande = _capDemande;
	platinum = _platinum;
	distance = _disatnce;
	etat = Disponible;
}

Mission::~Mission()
{
	std::cout << "Mission " + std::to_string(numMission) + " termine";
}

std::string Mission::to_string()
{
	std::string info;
	info =
		"Objectif : " + objectif + ", statistique du vesseau necesaire : \n" +
		"Vie	  : " + std::to_string(vieDemande) + "			" +
		"Deffense : " + std::to_string(defDemande) + "\n" +
		"Attaque  : " + std::to_string(attDemande) + "			" +
		"Capacite : " + std::to_string(capDemande) + "\n\n" +
		"Distance : " + std::to_string(distance) + ", Recompense : " + std::to_string(platinum) + " de platinum\n\n";
	return info;
}