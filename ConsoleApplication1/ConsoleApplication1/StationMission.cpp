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
				if (missions[stoi(choix)-1]->etat == 0)
				{
					DemarerMission(stoi(choix) - 1);
				}
				else
				{
					cout << "La mission est deja en cours/completer";
				}

			}
		}
		else
		{
			cout << "Mauvaises entree detectee, Appuyez sur une touche pour continuer" << endl;
			std::cin;
		}
	}
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

void Station::DemarerMission(int choix)
{
		if (missions[choix]->etat == 0)
		{
			missions[choix]->etat = Mission::EtatMission::EnCours;
		}
}

void Station::CheckMissionEnCours()
{
	for (auto mis : missions)
		if (mis->etat == 1)
		{
			mis->distance -= 500;
		}
}

void Station::CheckMissionFini() 
{
	//check si une mission a etet effacer pour pas faire le i++ apres ce qui efface la mauvaise mission et cause un vector overflow
	bool missionAEtetEffacer;

	int i = 0;
	for (auto mis : missions) {
		missionAEtetEffacer = false;
		if (mis->distance <= 0)
		{
			missionAEtetEffacer = true;
			mis->etat + 1;
			platinumDispo += mis->platinum;
			delete missions[i];
			missions.erase(missions.begin() + i);

		}
		if (!missionAEtetEffacer)
		{
			i++;
		}
	}

}

vector<Mission*> Station::GenereMission()
{
	int max;
	if (capMax == 5)
		max = 3;
	else
		max = 4;

	vector<Mission*> Missions;
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