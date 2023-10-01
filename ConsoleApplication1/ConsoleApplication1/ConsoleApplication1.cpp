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


    Station *Logan;
    Logan = new Station();
    Logan->Init();
    Logan->Jeux();

    delete Logan;


    return 0;
}

