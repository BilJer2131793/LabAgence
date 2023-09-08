#include "Livraison.h"
Livraison::Livraison(string nom, int attack, int defense, int vie, int capacite) : Vaisseau(nom, attack, defense, vie, capacite)
{

}
Livraison::~Livraison() {

}
string Livraison::to_string() {
	string msg = "Je suis un vaisseau de livraison";
	return msg;
}