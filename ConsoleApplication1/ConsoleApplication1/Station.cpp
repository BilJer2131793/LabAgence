#include "Station.h"
#include <chrono>
#include <thread>



Station::Station()
{
	this->platinumDispo = 100000;
	this->capMax = 4;
}

Station::~Station()
{
}

void Station::Jeux() {
	missions = GenereMission();
	while (!CheckJeuxFini())
	{
		Magasin();
		Missions();





		CheckMissionEnCours();
		CheckMissionFini();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

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

bool Station::CheckJeuxFini()
{
	for (auto mis : missions)
		if (mis->distance > 0)
		{
			return false;
		}
	return true;
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
