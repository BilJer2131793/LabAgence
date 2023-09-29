#pragma once
#include <iostream>
#include "Quete.h";

class FactoryQuete
{
public:
	static Quete* getRandomQuete();
	static int genererNB(int min, int max);
};

