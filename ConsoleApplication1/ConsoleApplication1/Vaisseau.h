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
	void setVie(int vie);
	int getAtk();
	void setAtk(int atk);
	int getDef();
	void setDef(int def);
	void setNiv();
	void setXP();

	virtual string to_string();

};


