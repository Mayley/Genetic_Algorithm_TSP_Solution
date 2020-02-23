#ifndef GA_CROSSOVER_H
#define GA_CROSSOVER_H

#include <map>
#include <set>
//Headers
#include "Solution.h"
#include "Settings.h"

class GACrossover
{
public:
	GACrossover(std::vector<Solution> parents) {
		this->parent = parents;
	};
	std::vector<Solution> crossover(CrossoverMethod crossoverMethod = Settings::crossoverMethod);

private:
	float crossoverThreshold = Settings::crossoverThreshold;
	std::vector<Solution> order();
	std::vector<Solution> edgeRecombination();
	std::vector<Solution> parent;
	//Stores the two new offspring to replace in population
	std::vector<Solution> offspring;

	void remove_Gene_From_EdgeMap(std::map<int, std::set<int>>& edgeMap, int gene);
	int gene_With_Least_Edges(std::map<int, std::set<int>>& edgeMap);

};

#endif // !GA_CROSSOVER_H


