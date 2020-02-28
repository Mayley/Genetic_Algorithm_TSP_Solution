#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include <iostream>
//Headers
#include "MenuController.h"

enum class CrossoverMethod {
	ORDER,
	EDGE_RECOMBINATION,
};

enum class MutationMethod {
	SWAP,
};

enum class SelectionMethod {
	TOURNAMENT,
};

static bool debugMode = true;

namespace Settings {
	static int numberOfGenerations = 1000;
	static SelectionMethod selectionMethod = SelectionMethod::TOURNAMENT;
	static int tournamentSize = 4;
	static CrossoverMethod crossoverMethod = CrossoverMethod::ORDER;
	static float crossoverThreshold = 0.7f;
	static MutationMethod mutationMethod = MutationMethod::SWAP;
	static float mutationThreshold = 0.02f;
	static int populationSize = 50;

	void menu();

	bool set_numberOfGenerations();
	bool set_selectionMethod();
	bool set_crossoverMethod();
	bool set_crossoverThreshold();
	bool set_mutationMethod();
	bool set_mutationThreshold();
	bool set_populationSize();

	std::string selection_Method_String();
	std::string mutation_Method_String();

	/* Returns the string for the CrossoverMethod enum,
   by defaut returns long strinb, but true will return shorthand*/
	std::string crossover_Method_String(bool abreviated = false);

}






#endif // !GA_SETTINGS_H


