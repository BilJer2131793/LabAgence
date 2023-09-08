#include "Vaisseau.h"


Vaisseau::Vaisseau(string nom, int attack, int defense, int vie, int capacite)
{
	this->nom = nom;
	this->attaque = attack;
	this->defense = defense;
	this->vie = vie;
	this->capacite = capacite;
}
Vaisseau::~Vaisseau() {

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