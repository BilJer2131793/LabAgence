#include "Vaisseau.h"


Vaisseau::Vaisseau(Faction* faction)
{
	this->faction = faction;
}
Vaisseau::~Vaisseau() {
	delete faction;
	faction = nullptr;
}
int Vaisseau::getVie() {
	return vie;
}
void Vaisseau::setVie(int vie) {
	this->vie = vie;
}
int Vaisseau::getAtk() {
	return attaque;
}
void Vaisseau::setAtk(int atk) {
	this->attaque = atk;
}
int Vaisseau::getDef() {
	return defense;
}
void Vaisseau::setDef(int def) {
	this->defense = def;
}
int Vaisseau::getCap() {
	return capacite;
}
void Vaisseau::setCap(int cap) {
	this->capacite = cap;
}
bool Vaisseau::getDispo() {
	return dispo;
}
void Vaisseau::setDispo(bool dispo) {
	this->dispo = dispo;
}
int Vaisseau::getDistance() {
	return distance;
}
void Vaisseau::setDistance(int dist) {
	this -> distance = dist;
}

string Vaisseau::to_string() {
	return "Vaisseu";
}