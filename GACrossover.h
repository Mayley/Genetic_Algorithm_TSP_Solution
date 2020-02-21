#ifndef GA_CROSSOVER_H
#define GA_CROSSOVER_H

#include "Solution.h"
#include "Settings.h"

enum class CrossoverMethod {
	ORDER,
	MODIFIED_PARTIALLY_MAPPED,
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
	std::vector<Solution> modified_Partially_Mapped();
	std::vector<Solution> parent;
	//Stores the two new offspring to replace in population
	std::vector<Solution> offspring;

};

#endif // !GA_CROSSOVER_H


