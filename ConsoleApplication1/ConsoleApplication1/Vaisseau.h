#pragma once
#include <string>;
#include "Faction.h";
using std::string;

class Vaisseau
{
protected:
	Faction* faction;
	string nom;
	int attaque;
	int defense;
	int vie;
	int capacite;
	int valeurMarchande;
	int niveau;
	int exp;
	bool dispo;
	int distance;
public:
	Vaisseau(Faction* faction);
	~Vaisseau();
	int getVie();
	void setVie(int vie);
	int getAtk();
	void setAtk(int atk);
	int getDef();
	void setDef(int def);
	int getCap();
	void setCap(int cap);
	bool getDispo();
	void setDispo(bool dispo);
	int getDistance();
	void setDistance(int dist);

	virtual string to_string();

};


