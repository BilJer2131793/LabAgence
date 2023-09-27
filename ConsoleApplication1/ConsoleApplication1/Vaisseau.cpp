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
void Vaisseau::setNiv() {

}
void Vaisseau::setXP() {

}
string Vaisseau::to_string() {
	return "Vaisseu";
}