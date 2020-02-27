// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include "GeneticAlgorithm.h"
#include "MenuController.h"

int main()
{
	MenuController menu("Genetic Algorithm for TSP!");
	int menuChoice;

	GeneticAlgorithm* ga = new GeneticAlgorithm;

	menu.add_Menu_Option("Genetic Algorithm");
	menu.add_Menu_Option("Settings");
	menu.add_Menu_Option("Reset");

	do
	{
		menu.display();

		std::cin >> menuChoice;

		switch (menuChoice)
		{
		case 1:
			ga->main_Menu();
			break;
		case 2:
			Settings::menu();
			ga = new GeneticAlgorithm;
			break;
		case 3:
			ga = new GeneticAlgorithm;
			break;
		default:
			break;
		}

	} while (menuChoice > 0);


	delete ga;

}