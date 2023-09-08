#pragma once
#include "Vaisseau.h"
class Transport : public Vaisseau
{
public:
	Transport(string nom, int attack, int defense, int vie, int capacite);
	~Transport();


	virtual string to_string();


};

