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
int Vaisseau::getAtk() {
	return attaque;
}
int Vaisseau::getDef() {
	return defense;
}
void Vaisseau::setNiv() {

}
void Vaisseau::setXP() {

}
string Vaisseau::to_string() {
	return "Vaisseu";
}