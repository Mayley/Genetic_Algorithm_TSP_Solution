#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

namespace Settings {
	int const numberOfGenerations = 500;
	int const solutionLength = 48;
	int const tournamentSize = 4;
	float const crossoverThreshold = 0.7f;
	float const mutationThreshold = 0.02f;
	int const populationSize = 50;
}



#endif // !GA_SETTINGS_H


