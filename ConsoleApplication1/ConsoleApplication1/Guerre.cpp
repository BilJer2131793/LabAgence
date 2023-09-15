#include "Guerre.h"

Guerre::Guerre(Faction* faction) : Vaisseau(faction)
{
	this->nom = "Guerre";
	this->attaque = 10;
	this->defense = 8;
	this->capacite = 3;
	this->vie = 14;
}
Guerre::~Guerre() {

}

string Guerre::to_string() {
	string msg = "Je suis un vaisseau de guerre";
	return msg;
}