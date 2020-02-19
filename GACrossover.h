#ifndef GA_CROSSOVER_H
#define GA_CROSSOVER_H

#include "Solution.h"
#include "Settings.h"

enum class CrossoverMethod {
	ORDER,
	MODIFIED_PARTIALLY_MAPPED_CROSSOVER,
};

class GACrossover
{
public:
	GACrossover(std::vector<Solution> parents) {
		this->parent = parents;
	};
	std::vector<Solution> crossover(CrossoverMethod crossoverMethod = CrossoverMethod::ORDER);

private:
	float crossoverThreshold = Settings::crossoverThreshold;
	std::vector<Solution> order();
	std::vector<Solution> parent;
};

#endif // !GA_CROSSOVER_H


