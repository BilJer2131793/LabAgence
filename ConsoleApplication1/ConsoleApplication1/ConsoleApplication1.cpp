#include <iostream>
#include "Livraison.h"
#include "Transport.h"
#include "Guerre.h"
#include "Faction.h"
using std::cout;
using std::endl;


int main()
{
    Vaisseau* v = new Vaisseau("s",1,1,1,1);
    cout << v->to_string() << endl;
    Transport* t = new Transport("d",2,2,2,2);
    cout << t->to_string() << endl;
    Faction* rouge = new Faction("Rouge", 1,1,1,1);
    Faction* bleu = new Faction("bleu", 1, 1, 1, 1);



    delete v;
    delete t;
}

