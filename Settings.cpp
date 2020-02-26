#include "Settings.h"

std::string Settings::selection_Method_String() {
	switch (Settings::selectionMethod)
	{
	case SelectionMethod::TOURNAMENT:
		return ("Tournament");
	default:
		break;
	}
}

std::string Settings::mutation_Method_String() {
	switch (Settings::mutationMethod)
	{
	case MutationMethod::SWAP:
		return ("Swap");
	default:
		break;
	}
}

std::string Settings::crossover_Method_String(bool abreviated) {

	if (abreviated)
	{
		switch (Settings::crossoverMethod)
		{
		case CrossoverMethod::ORDER:
			return ("OX");
		case CrossoverMethod::EDGE_RECOMBINATION:
			return ("ER");
		}
	}
	else {
		switch (Settings::crossoverMethod)
		{
		case CrossoverMethod::ORDER:
			return ("ORDER");
		case CrossoverMethod::EDGE_RECOMBINATION:
			return ("EDGE_RECOMBINATION");
		}
	}

}

void Settings::menu() {
	MenuController menu("Change Settings", true);

	int menuChoice;

	menu.add_Menu_Option("Number of Generations per evolution");
	menu.add_Menu_Option("Population size");
	menu.add_Menu_Option("Selection Method");
	menu.add_Menu_Option("Crossover Method");
	menu.add_Menu_Option("Crossover Threshold");
	menu.add_Menu_Option("Mutation Method");
	menu.add_Menu_Option("Mutation Threshold");

	do
	{
		menu.set_Menu_Option(0, "Number of generations per evolution: " + std::to_string(Settings::numberOfGenerations));
		menu.set_Menu_Option(1, "Population size: " + std::to_string(Settings::populationSize));
		menu.set_Menu_Option(2, "Selection Method: " + Settings::selection_Method_String());
		menu.set_Menu_Option(3, "Crossover Method: " + Settings::crossover_Method_String());
		menu.set_Menu_Option(4, "Crossover Thresold: " + std::to_string(Settings::crossoverThreshold));
		menu.set_Menu_Option(5, "Mutation Method: " + Settings::mutation_Method_String());
		menu.set_Menu_Option(6, "Mutation Threshold: " + std::to_string(Settings::mutationThreshold));

		menu.display();

		std::cin >> menuChoice;

		switch (menuChoice)
		{
		case 1:
			set_numberOfGenerations();
			break;
		case 2:
			set_populationSize();
			break;
		case 3:
			set_selectionMethod();
			break;
		case 4:
			set_crossoverMethod();
			break;
		case 5: 
			set_crossoverThreshold();
			break;
		case 6:
			set_mutationMethod();
			break;
		case 7:
			set_mutationThreshold();
			break;
		default:
			break;
		}
	} while (menuChoice > 0);
}

bool Settings::set_numberOfGenerations() {
	MenuController menu("Number of generations per evolution", true);
	int input;
	int newGenerationCount;

	menu.add_Menu_Option("100");
	menu.add_Menu_Option("250");
	menu.add_Menu_Option("500");
	menu.add_Menu_Option("750");
	menu.add_Menu_Option("1000");
	menu.add_Menu_Option("Own value");

	do
	{
		menu.display();

		std::cin >> input;

		switch (input)
		{
		case 1:
			numberOfGenerations = 100;
			input = -1;
			break;
		case 2:
			numberOfGenerations = 250;
			input = -1;
			break;
		case 3:
			numberOfGenerations = 500;
			input = -1;
			break;
		case 4:
			numberOfGenerations = 750;
			input = -1;
			break;
		case 5:
			numberOfGenerations = 1000;
			input = -1;
			break;
		case 6:
			do {
				std::cout << "Number of generations per evolution (minimum 50): ";
				std::cin >> newGenerationCount;
			} while (newGenerationCount <= 50);
			numberOfGenerations = newGenerationCount;
			input = -1;
			break;
		default:
			return false;
			break;
		}
	} while (input > 0);
}

bool Settings::set_populationSize() {
	MenuController menu("Number of generations per evolution", true);
	int input;
	int newGenerationCount;

	menu.add_Menu_Option("10");
	menu.add_Menu_Option("25");
	menu.add_Menu_Option("50");
	menu.add_Menu_Option("100");
	menu.add_Menu_Option("250");
	menu.add_Menu_Option("Own value");

	do
	{
		menu.display();

		std::cin >> input;

		switch (input)
		{
		case 1:
			numberOfGenerations = 10;
			input = -1;
			break;
		case 2:
			numberOfGenerations = 25;
			input = -1;
			break;
		case 3:
			numberOfGenerations = 50;
			input = -1;
			break;
		case 4:
			numberOfGenerations = 100;
			input = -1;
			break;
		case 5:
			numberOfGenerations = 1000;
			input = -1;
			break;
		case 6:
			do {
				std::cout << "Number of generations per evolution (minimum 50): ";
				std::cin >> newGenerationCount;
			} while (newGenerationCount <= 50);
			numberOfGenerations = newGenerationCount;
			input = -1;
			break;
		default:
			return false;
			break;
		}
	} while (input > 0);
	return false;
}
bool Settings::set_selectionMethod() {

	return false;
}
bool Settings::set_crossoverMethod() {

	return false;
}
bool Settings::set_crossoverThreshold() {

	return false;
}
bool Settings::set_mutationMethod() {

	return false;
}
bool Settings::set_mutationThreshold() {

	return false;
}

