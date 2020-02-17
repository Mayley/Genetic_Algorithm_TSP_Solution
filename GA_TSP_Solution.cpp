// GA_TSP_Solution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Settings.h"
#include "GeneticAlgorithm.h"

int main()
{
    std::cout << "Genetic Algorithm Travelling Sales Person Solver!\n";

    //Control loop for the game
    int menuChoice;

    GeneticAlgorithm* ga = new GeneticAlgorithm;

    do
    {
        std::cout << "\nWhat would you like to do?" << std::endl;
        std::cout << "1: Evolve" << std::endl;
        std::cout << "2: Print" << std::endl;
        std::cout << "3: Reset " << std::endl;
        std::cout << "4: Quit" << std::endl;
        std::cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            ga->evolve();
            break;
        case 2:
            ga->print();
            break;
        case 3:
            delete ga;
            ga = new GeneticAlgorithm;
            break;
        case 4:
            return 1;
        default:
            break;
        }
    } while (menuChoice != -1);


}
