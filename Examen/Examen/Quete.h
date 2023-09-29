#pragma once
#include <iostream>
#include <string>;
#include <vector>;

using std::string;
class Quete
{
public:
	enum class difficulte { Facile, Moyen, Difficile };
	Quete(string nom, difficulte nivDifficulte, int nivMin, int recompenseOr, int expRecu);
	~Quete();

	difficulte getDifficulte();
	int getNivMin();
	int getRecompense();
	int getExp();

	virtual string to_string();

private:

	string nom;

	difficulte nivDifficulte;
	int nivMin;
	int recompenseOr;
	int expRecu;



};

