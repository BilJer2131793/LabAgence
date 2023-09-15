#include <iostream>
#include <ctime>
#include "Vaisseau.h"
#include "FactoryVaisseau.h"
using std::cout;
using std::endl;


int main()
{
    srand(time(NULL));
    cout << "vaisseau en production" << endl;
    Vaisseau* monVaisseau = FactoryVaisseau::getRandomVaisseau();
    cout << monVaisseau->to_string();



    delete monVaisseau;

    return 0;
}

