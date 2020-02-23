// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once

#include <iostream>
#include "GeneticAlgorithm.h"
#include "Settings.h"

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
        std::cout << "2: Print Current Population Stats" << std::endl;
        std::cout << "3: Print Solution Fitness Stats from file" << std::endl;
        std::cout << "4: Clear Stats File" << std::endl;
        std::cout << "5: Reset Genetic Algorithm" << std::endl;
        std::cout << "6: Quit" << std::endl;
        std::cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            delete ga;
            break;
        case 2:
            ga->print_Population_Stats();
            break;
        case 3:
            ga->print_Solution_Stats_From_File();
            break;
        case 4:
            ga->clear_Fitness_Stats_File();
            break;
        case 5:
            delete ga;
            ga = new GeneticAlgorithm;
            break;
        case 6:
            return 1;
        default:
            break;
        }
    } while (menuChoice != -1);


}
