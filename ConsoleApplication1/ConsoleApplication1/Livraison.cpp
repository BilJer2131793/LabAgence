#include "Livraison.h"
Livraison::Livraison(Faction* faction) : Vaisseau(faction)
{
	this->nom = "Livraisson";
	this->attaque = 4;
	this->defense = 8;
	this->capacite = 4;
	this->vie = 15;
}
Livraison::~Livraison() {

}
string Livraison::to_string() {
	string msg = "Je suis un vaisseau de livraison";
	return msg;
}