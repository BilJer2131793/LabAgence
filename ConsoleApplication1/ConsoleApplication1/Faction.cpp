#include "Faction.h"
Faction::Faction(string nom, int atk, int def, int vie, int capacite)
{
	this->nom = nom;
	this->atk = atk;
	this->def = def;
	this->vie = vie;
	this->capcite = capacite;
}
Faction::~Faction(){

}
