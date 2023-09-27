#pragma once
#include "Vaisseau.h"
#include "FactoryVaisseau.h"
#include <vector>
using std::vector;
class Magasin
{
public:
	Magasin();
	~Magasin();
	void ReparerVaisseau();
	void AcheterVaisseau();
	void AugmenterVaisseau();
	void VendreVaisseau();

private:
};

