#include "Station.h"


Station::Station()
{
	this->platinumDispo = 100000;
	this->capMax = 10;
}

Station::~Station()
{
}
void Station::Init() {
	for (int i = 0; i < 3; i++)
		vecVaisseau.push_back(FactoryVaisseau::getRandomVaisseau());
}
vector<Vaisseau*> Station::getVaisseauDispo() { return vecVaisseau; }
void Station::ajouterVaisseau(Vaisseau* vaisseau) { vecVaisseau.push_back(vaisseau); }

int Station::AfficherVaisseau()
{
	int i = 1;
	for (i; i < vecVaisseau.size() + 1; i++)
	{
		cout << "(" << i << ") " << vecVaisseau[i - 1]->to_string() << endl;
	}
	return i;
}

//Section Magasin

void Station::Magasin()
{
	while (true)
	{
		clear_screen(' ');
		string choix = "";
		cout << "Bienvenue aux Magasin			Capacite du Garage:" << vecVaisseau.size() << "/" << capMax << "			Platinum: " << platinumDispo << endl;
		cout << "(1) Acheter un Nouveau Vaisseau " << endl;
		cout << "(2) Ameliore un Vaisseau" << endl;
		cout << "(3) Reparer un Vaisseau" << endl;
		cout << "(4) Vendre un Vaisseau" << endl;
		cout << "(5) Quitter";
		cout << endl << "Faites votre choix" << endl;

		std::cin >> choix;

		if (choix == "1") {
			AcheterVaisseau();
		}
		else if (choix == "2") {
			AugmenterVaisseau();
		}
		else if (choix == "3") {
			ReparerVaisseau();
		}
		else if (choix == "4") {
			VendreVaisseau();
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
	if (vecVaisseau.size() < capMax)
	{
		return true;
	}
	else
	{
		cout << "Vous avez pas assez de place dans votre garage pour un autre vaisseau" << endl;
		return false;
		std::cin;
	}

}

void Station::ReparerVaisseau()
{
	while (true)
	{
		clear_screen(' ');
		string choix = " ";
		cout << "Bienvenue aux Garage 			Capacite du Garage:" << vecVaisseau.size() << "/" << capMax << "			Platinum: " << platinumDispo << endl;

		int quitter = AfficherVaisseau();
		cout << "(" << quitter << ") Quitter";
		cout << endl << "Faites votre choix" << endl;
		std::cin >> choix;

		if (choix == std::to_string(quitter)) {
			break;
		}
		else if (std::isdigit(choix[0])) {
			//modifier pour bonnes valeur de vie
			int vieMax = 20;
			if (CheckArgent((vieMax - vecVaisseau[std::stoi(choix)]->getVie())) * 100)
			{
				this->platinumDispo -= (vieMax - vecVaisseau[std::stoi(choix)]->getVie()) * 100;
				vecVaisseau[std::stoi(choix)]->setVie(vieMax);
			}
		}
		else
		{
			cout << "Mauvaises entree detectee, Appuyez sur une touche pour continuer" << endl;
			std::cin;
		}

	}
}

void Station::AcheterVaisseau()
{
	while (true)
	{
		clear_screen(' ');
		string choix = "";
		cout << "Bienvenue aux Magasin			Capacite du Garage:" << vecVaisseau.size() << "/" << capMax << "			Platinum: " << platinumDispo << endl;
		cout << "(1) Vaisseau de Guerre		Atk:	Def:	Cap:	Vit:	Prix: " << endl;
		cout << "(2) Vaisseau de Transport	Atk:	Def:	Cap:	Vit:	Prix: " << endl;
		cout << "(3) Vaisseau de Livraison	Atk:	Def:	Cap:	Vit:	Prix: " << endl;
		cout << "(4) Quitter";
		cout << endl << "Faites votre choix" << endl;

		std::cin >> choix;

		if (choix == "1") {
			if (CheckArgent(2000) && CheckCapacite()) {
				this->platinumDispo -= 2000;
				Vaisseau* nouvVaisseau = FactoryVaisseau::GenererVaisseau(1);
				vecVaisseau.push_back(nouvVaisseau);
				std::cin;
				break;
			}
		}
		else if (choix == "2") {
			if (CheckArgent(2000) && CheckCapacite()) {
				this->platinumDispo -= 2000;
				Vaisseau* nouvVaisseau = FactoryVaisseau::GenererVaisseau(2);
				vecVaisseau.push_back(nouvVaisseau);
				break;
			}
		}
		else if (choix == "3") {
			if (CheckArgent(2000) && CheckCapacite()) {
				this->platinumDispo -= 2000;
				Vaisseau* nouvVaisseau = FactoryVaisseau::GenererVaisseau(3);
				vecVaisseau.push_back(nouvVaisseau);
				break;
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
	while (true)
	{
		clear_screen(' ');
		string choix = " ";
		cout << "Bienvenue aux Garage 			Capacite du Garage:" << vecVaisseau.size() << "/" << capMax << "			Platinum: " << platinumDispo << endl;

		int quitter = AfficherVaisseau();
		cout << "(" << quitter << ") Quitter";
		cout << endl << endl << "Augmenter un stat de vaisseau coute 1000 Platinum";
		cout << endl << "Faites votre choix" << endl;
		std::cin >> choix;

		if (choix == std::to_string(quitter)) {
			break;
		}
		else if (std::isdigit(choix[0])) {
			if (CheckArgent(1000))
				AugmenterStat(std::stoi(choix));
		}
		else
		{
			cout << "Mauvaises entree detectee, Appuyez sur une touche pour continuer" << endl;
			std::cin;
		}

	}
}
void Station::AugmenterStat(int v)
{
	bool continuer;
	do
	{
		continuer = false;
		string choixS = "";
		int choixI = 0;
		cout << "Voulez-vous ameliorer" << endl;
		cout << "(1) Vie" << endl;
		cout << "(2) Attaque" << endl;
		cout << "(3) Defense" << endl;
		cout << "(4) Vitesse" << endl;
		cout << "(5) Quitter" << endl;

		std::cin >> choixS;
		if (std::isdigit(choixS[0])) {
			choixI = std::stoi(choixS);
			switch (choixI) {
			case 1:
				vecVaisseau[v]->setVie(vecVaisseau[v]->getVie() + 1);
				this->platinumDispo -= 1000;
				break;
			case 2:
				vecVaisseau[v]->setAtk(vecVaisseau[v]->getAtk() + 1);
				this->platinumDispo -= 1000;
				break;
			case 3:
				vecVaisseau[v]->setDef(vecVaisseau[v]->getDef() + 1);
				this->platinumDispo -= 1000;
				break;
				//faire vitessse
			case 4:
				vecVaisseau[v]->setVie(vecVaisseau[v]->getVie() + 1);
				this->platinumDispo -= 1000;
				break;
			case 5:
				//rien
				break;
			default:
				cout << "Mauvaises entree detectee, Appuyez sur une touche pour continuer" << endl;
				std::cin;
				continuer = true;
				break;
			}
		}
		else
		{
			cout << "Mauvaises entree detectee, Appuyez sur une touche pour continuer" << endl;
			std::cin;
		}
	} while (continuer);
}
void Station::VendreVaisseau()
{
	while (true)
	{
		clear_screen(' ');
		string choix = "";
		cout << "Bienvenue aux Garage 			Capacite du Garage:" << vecVaisseau.size() << "/" << capMax << "			Platinum: " << platinumDispo << endl;
		int quitter = AfficherVaisseau();
		cout << "(" << quitter << ") Quitter" << endl;
		cout << "Choisissez quelle vaisseau vous voulez vendre" << endl;
		std::cin >> choix;

		if (choix == std::to_string(quitter)) {
			break;
		}
		else if (std::isdigit(choix[0])) {
			int choixI = std::stoi(choix);
			delete vecVaisseau[choixI-1];
			vecVaisseau.erase(vecVaisseau.begin() + choixI - 1);
			this->platinumDispo += 1000;
		}
		else
		{
			cout << "Mauvaises entree detectee, Appuyez sur une touche pour continuer" << endl;
			std::cin;
		}
	}
}

//???
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
