#include "Aventurier.h"

Aventurier::Aventurier()
{
	this->niveau = 1;
}

Aventurier::~Aventurier()
{
}
void Aventurier::afficherQuete()
{
	for (size_t i = 0; i != tabQuete.size(); ++i) {
		tabQuete[i]->to_string();
	}

}

void Aventurier::ajouterQuete(Quete* q)
{
	tabQuete.push_back(q);
}

int Aventurier::giveNiv()
{
	return this->niveau;
}
