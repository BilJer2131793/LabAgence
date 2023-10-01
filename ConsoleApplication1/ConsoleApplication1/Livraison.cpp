#include "Livraison.h"

Livraison::Livraison(Faction* faction) : Vaisseau(faction)
{
	vie = 10;
	defense = 4;
	attaque = 1;
	capacite = 10;
	niveau = 0;
	exp = 0;
	valeurMarchande = 500;
}

Livraison::~Livraison() {}

std::string Livraison::to_string()
{
	std::string info = "";
	info.append("Type : Livraison \n");
	info.append("nom : Vincent \n");
	info += Vaisseau::to_string();

	return info;

}
