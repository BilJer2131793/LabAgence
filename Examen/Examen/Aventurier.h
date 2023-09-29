#pragma once
#include "Quete.h";
#include <vector>
using std::vector;
class Aventurier
{
private:
	int niveau;
	vector<Quete*> tabQuete;
public:
	Aventurier();
	~Aventurier();

	void afficherQuete();
	void ajouterQuete(Quete* q);
	int giveNiv();

};

