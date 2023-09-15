#pragma once
#include "Vaisseau.h"
class Livraison : public Vaisseau
{
public:
	Livraison(Faction* faction);
	~Livraison();

	virtual string to_string();
};

