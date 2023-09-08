#include "Transport.h"
Transport::Transport(string nom, int attack, int defense, int vie, int capacite) : Vaisseau(nom, attack, defense, vie, capacite)
{

}
Transport::~Transport() {

}
string Transport::to_string() {
	string msg = "Je suis un vaisseau de transport";
	return msg;
}