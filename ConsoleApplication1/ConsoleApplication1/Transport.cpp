#include "Transport.h"

Transport::Transport(Faction* faction) : Vaisseau(faction)
{
	vie = 8;
	defense = 5;
	attaque = 3;
	capacite = 7;
	niveau = 0;
	exp = 0;
	valeurMarchande = 1000;
}

Transport::~Transport() {}

std::string Transport::to_string()
{
	std::string info = "";
	info.append("Type : Transport \n");
	info.append("nom : Vincent \n");
	info += Vaisseau::to_string();

	return info;
}
