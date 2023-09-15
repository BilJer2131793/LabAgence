#pragma once
#include <string>;
#include "Faction.h";
using std::string;

class Vaisseau
{
protected:
	int attaque;
	int defense;
	int vie;
	int capacite;
	Faction* faction;
	string nom;
	int niveau;
	int exp;
public:
	Vaisseau(Faction* faction);
	~Vaisseau();
	int getVie();
	int getAtk();
	int getDef();
	void setNiv();
	void setXP();

	virtual string to_string();

};


