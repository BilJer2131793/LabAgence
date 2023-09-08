#pragma once
#include <string>;
#include "Faction.h";
using std::string;

class Vaisseau
{
private:
	int attaque;
	int defense;
	int vie;
	int capacite;
	string nom;
	int niveau;
	int exp;
public:
	Vaisseau(string nom, int attack, int defense, int vie, int capacite);
	~Vaisseau();
	int getVie();
	int getAtk();
	int getDef();
	void setNiv();
	void setXP();

	virtual string to_string();

};


