#pragma once
#include "Vaisseau.h"
class Guerre : public Vaisseau
{
public:
	Guerre(string nom, int attack, int defense, int vie, int capacite);
	~Guerre();

	virtual string to_string();
};

