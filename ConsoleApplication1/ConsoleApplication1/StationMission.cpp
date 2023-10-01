#include "Station.h"

void Station::Missions() 
{
	while (true)
	{
		clear_screen(' ');
		string choix = " ";
		cout << "Bienvenue aux Centre de Mission 	Capacite du Garage:" << vecVaisseau.size() << "/" << capMax << "			Platinum: " << platinumDispo << endl;
		int quitter = AfficherMission();

		std::cin >> choix;
		if (choix == std::to_string(quitter)) {
			break;
		}
		else if (std::isdigit(choix[0])) 
		{
			if (stoi(choix)<quitter)
			{
				Mission* m = getMission(stoi(choix)-1);
				if (m->etat == 0)
				{
					DemarerMission(m->objectif);
				}
				else
				{
					cout << "La mission est deja en cours/completer";
				}
				delete m;
				m = nullptr;

			}
		}
		else
		{
			cout << "Mauvaises entree detectee, Appuyez sur une touche pour continuer" << endl;
			std::cin;
		}
	}
}
Mission* Station::getMission(int _i) 
{
	std::list<Mission*>::iterator it = missions.begin();
	for (int i = 0; i < _i; i++) {
		++it;
	}
	return *it;
}
int Station::AfficherMission() {

	int i = 1;
	for (Mission* mis : missions) {
		cout << "(" << i << ") " << mis->to_string();
		i++;
	}
	cout << "(" << i << ") Finir Tour";
	return i;
}

bool Station::CheckSpecVaisseau(Vaisseau* v, Mission* m) {

	if (m->attDemande <= v->getAtk())
		if (m->vieDemande <= v->getVie())
			if (m->defDemande <= v->getDef())
				if (m->capDemande <= v->getCap())
					return true;
	return false;
}

void Station::DemarerMission(string objectif)
{
	for (auto mis : missions)
		if (mis->etat == 0 && mis->objectif == objectif)
		{
			mis->etat = Mission::EtatMission::EnCours;
		}
}

void Station::CheckMissionEnCours()
{
	for (auto mis : missions)
		if (mis->etat == 1)
		{
			mis->distance -= 5000;
		}
}

void Station::CheckMissionFini() 
{
	for (auto mis : missions)
		if (mis->etat == 1 and mis->distance == 0)
		{
			mis->etat + 1;
			platinumDispo += mis->platinum;
			/*cout << "La mission avec le but: " << mis->objectif << "a ete completer avec success";*/
		}
}

std::list<Mission*> Station::GenereMission()
{
	int max;
	if (capMax == 5)
		max = 3;
	else
		max = 4;

	std::list<Mission*> Missions;
	for (int i = 0; i < capMax; i++)
	{
		int objMission = (rand() % (max - 1 + 1)) + 1;
		Missions.push_back(ObjectifMission(objMission));
	}
	return Missions;
}

Mission* Station::ObjectifMission(int mission)
{
	switch (mission)
	{
	case 1: return new Mission("Aller sauver une planet", 8, 2, 2, 5, 500, 1000);
	case 2: return new Mission("Piller un vaisseaux abandoné", 8, 2, 2, 5, 500, 1000);
	case 3: return new Mission("Attaquer un vaisseaux enemie", 8, 2, 2, 5, 500, 1000);
	case 4: return new Mission("Aller a la rencontre de Dieux", 8, 2, 2, 5, 500, 1000);

	}

}