#ifndef GA_CROSSOVER_H
#define GA_CROSSOVER_H

#include "Solution.h"
#include "Settings.h"

class GACrossover
{
public:
	std::vector<Solution> crossover(std::vector<Solution> parent);

private:
	float crossoverThreshold = Settings::crossoverThreshold;
	std::vector<Solution> order(std::vector<Solution> parent);
};

#endif // !GA_CROSSOVER_H


