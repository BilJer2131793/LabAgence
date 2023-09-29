#include <iostream>
#include <ctime>
#include "Quete.h"
#include "FactoryQuete.h"
#include "Aventurier.h"

int main()
{
    srand(time(NULL));
    FactoryQuete* factory = new FactoryQuete();
    Quete* q = factory->getRandomQuete();

    Aventurier* hero = new Aventurier();

    for (int i = 0; i <= 12; i++)
    {
        Quete* quete = factory->getRandomQuete();
        if (hero->giveNiv() >= quete->getNivMin())
        {
            hero->ajouterQuete(quete);
        }
    }

    hero->afficherQuete();
    //std::cout << std::endl <<q->getExp();
    //std::cout << std::endl << q->getNivMin();
    //std::cout << std::endl << q->getRecompense() << std::endl;


    std::cout << q->to_string();

}