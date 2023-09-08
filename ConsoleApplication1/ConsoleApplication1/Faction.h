#pragma once
#include <string>
using std::string;
class Faction
{
private:
	int atk;
	int def;
	int vie;
	int capcite;
	string nom;
public:
	Faction(string nom ,int atk, int def, int vie, int capacite);
	~Faction();
};

