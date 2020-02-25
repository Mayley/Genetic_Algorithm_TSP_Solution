#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

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

namespace Settings {
	static int numberOfGenerations = 500;
	static int solutionLength = 48;
	static SelectionMethod selectionMethod = SelectionMethod::TOURNAMENT;
	static int tournamentSize = 4;
	static CrossoverMethod crossoverMethod = CrossoverMethod::ORDER;
	static float crossoverThreshold = 0.7f;
	static MutationMethod mutationMethod = MutationMethod::SWAP;
	static float mutationThreshold = 0.02f;
	static int populationSize = 50;
}

 /* Returns the string for the CrossoverMethod enum, 
	by defaut returns long strinb, but true will return shorthand*/
 std::string crossover_Method_String(bool abreviated = false);

#endif // !GA_SETTINGS_H


