#include "Guerre.h"

Guerre::Guerre(Faction* faction) : Vaisseau(faction)
{

	vie = 8;
	defense = 5;
	attaque = 8;
	capacite = 2;
	niveau = 0;
	exp = 0;
	valeurMarchande = 2000;



}

Guerre::~Guerre() {}


std::string Guerre::to_string()
{
	std::string info = "";
	info.append("Type : Guerre \n");
	info.append("nom : Vincent \n");
	info += Vaisseau::to_string();

	return info;

}
