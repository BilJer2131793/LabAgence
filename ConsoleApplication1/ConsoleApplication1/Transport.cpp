#include "Transport.h"
Transport::Transport(Faction* faction) : Vaisseau(faction)
{
	this->nom = "Transport";
	this->attaque = 2;
	this->defense = 6;
	this->capacite = 10;
	this->vie = 8;
}
Transport::~Transport() {

}
string Transport::to_string() {
	string msg = "Je suis un vaisseau de transport";
	return msg;
}