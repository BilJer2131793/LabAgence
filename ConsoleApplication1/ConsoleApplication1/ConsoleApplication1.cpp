#include <iostream>
#include <ctime>
#include "Vaisseau.h"
#include "FactoryVaisseau.h"
#include "Station.h"
using std::cout;
using std::endl;

static int wow;
int main()
{
    srand(time(NULL));
    cout << "vaisseau en production" << endl;
    Vaisseau* monVaisseau = FactoryVaisseau::getRandomVaisseau();
    cout << monVaisseau->to_string();

    delete monVaisseau;
    Station *Logan;
    Logan = new Station();
    Logan->Init();
    Logan->Magasin();

    return 0;
}

