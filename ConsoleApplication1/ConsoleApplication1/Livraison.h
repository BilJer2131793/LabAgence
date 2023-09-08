#pragma once
#include "Vaisseau.h"
class Livraison : public Vaisseau
{
public:
	Livraison(string nom, int attack, int defense, int vie, int capacite);
	~Livraison();

	virtual string to_string();
};

