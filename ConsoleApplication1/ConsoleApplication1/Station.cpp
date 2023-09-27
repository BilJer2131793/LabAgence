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

void Station::AfficherVaisseau()
{
	for (int i = 1; i < vecVaisseau.size()+1; i++)
	{
		cout << "("<<i<<") "<< vecVaisseau(i-1)->to_string();
	}
}


//Section Magasin

void Station::Magasin()
{
	clear_screen(' ');
	string choix = "";
	cout << "Bienvenue aux Magasin			Capacite du Garage:" << vecVaisseau.size() << "/" << capMax << "			Platinum: " << platinumDispo << endl;
	cout << "(1) Acheter un Nouveau Vaisseau " << endl;
	cout << "(2) Ameliore un Vaisseau" << endl;
	cout << "(3) Reparer un Vaisseau" << endl;
	cout << "(4) Vendre un Vaisseau";
	cout << "(5) Quitter";
	cout << endl << "Faites votre choix" << endl;

	std::cin >> choix;
	while (true)
	{
		if (choix == "1") {
			AcheterVaisseau();
		}
		else if (choix == "2") {

		}
		else if (choix == "3") {

		}
		else if (choix == "4") {

		}
		else if (choix == "5") {
			break;
		}
		else {
			cout << "Mauvaises entree detectee, Appuyez sur une touche pour continuer" << endl;
			std::cin;
		}
	}


}

inline bool Station::CheckArgent(int montant)
{
	if (this->platinumDispo >= montant) {
		return true;
	}
	else {
		cout << "Vous avez pas assez d'argent pour cette achat" << endl;
		return false;
	}

}

inline bool Station::CheckCapacite()
{
	if (vecVaisseau.size() > capMax)
	{
		return true;
	}
	else
	{
		cout << "Vous avez pas assez de place dans votre garage pour un autre vaisseau" <<endl;
		return false;
	}

}

void Station::ReparerVaisseau()
{
}

void Station::AcheterVaisseau()
{
	clear_screen(' ');
	string choix = "";
	cout << "Bienvenue aux Magasin			Capacite du Garage:"<<	vecVaisseau.size()<<"/"<< capMax << "			Platinum: " << platinumDispo << endl;
	cout << "(1) Vaisseau de Guerre		Atk:	Def:	Cap:	Vit:	Prix: " << endl;
	cout << "(2) Vaisseau de Transport	Atk:	Def:	Cap:	Vit:	Prix: " << endl;
	cout << "(3) Vaisseau de Livraison	Atk:	Def:	Cap:	Vit:	Prix: " << endl;
	cout << "(4) Quitter";
	cout << endl << "Faites votre choix" << endl;

	std::cin >> choix;
	while (true)
	{
		if (choix == "1") {
			if (CheckArgent(2000) && CheckCapacite()) {
				Vaisseau* nouvVaisseau = FactoryVaisseau::GenererVaisseau(1);
				vecVaisseau.push_back(nouvVaisseau);
			}
		}
		else if (choix == "2") {
			if (CheckArgent(2000) && CheckCapacite()) {
				Vaisseau* nouvVaisseau = FactoryVaisseau::GenererVaisseau(2);
				vecVaisseau.push_back(nouvVaisseau);
			}
		}
		else if (choix == "3") {
			if (CheckArgent(2000) && CheckCapacite()) {
				Vaisseau* nouvVaisseau = FactoryVaisseau::GenererVaisseau(3);
				vecVaisseau.push_back(nouvVaisseau);
			}
		}
		else if (choix == "4") {
			break;
		}
		else {
			cout << "Mauvaises entree detectee, Appuyez sur une touche pour continuer" << endl;
			std::cin;
			AcheterVaisseau();
		}
	}

}
void Station::AugmenterVaisseau()
{
	cout << "Bienvenue aux Garage 			Capacite du Garage:" << vecVaisseau.size() << "/" << capMax << "			Platinum: " << platinumDispo << endl;



}
void Station::VendreVaisseau()
{
}


void Station::clear_screen(char fill = ' ') {
	COORD tl = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO s;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, fill, cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);
}