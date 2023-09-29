#include "Quete.h"

Quete::Quete(string nom, difficulte nivDifficulte, int nivMin, int recompenseOr, int expRecu)
{
	this->nivDifficulte = nivDifficulte;
	this->nom = nom;
	this->nivMin = nivMin;
	this->recompenseOr = recompenseOr;
	this->expRecu = expRecu;
}
Quete::~Quete()
{
}

Quete::difficulte Quete::getDifficulte() { return this->nivDifficulte; }

int Quete::getNivMin() { return this->nivMin; }

int Quete::getRecompense() { return this->recompenseOr; }

int Quete::getExp() { return this->expRecu; }

string Quete::to_string()
{

	string textDif;
	if (nivDifficulte == difficulte::Facile){
		textDif = "Facile";
	}
	else if (nivDifficulte == difficulte::Moyen) {
		textDif = "Moyen";
	}
	else {
		textDif = "Difficile";
	}


	string text = "Nom: "+nom;
	//text= text +("\nDifficulte: "+textDif);
	//text = text + ("Niveau Minimum: " + getNivMin());
	//text+=("\nRecompense: " + getRecompense());
	//text+=("\nExperience: " + getExp());

	return text;
}
