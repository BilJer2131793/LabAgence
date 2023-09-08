#include "Guerre.h"

Guerre::Guerre(string nom, int attack, int defense, int vie, int capacite) : Vaisseau(nom, attack, defense, vie, capacite)
{

}
Guerre::~Guerre() {

}

string Guerre::to_string() {
	string msg = "Je suis un vaisseau de guerre";
	return msg;
}