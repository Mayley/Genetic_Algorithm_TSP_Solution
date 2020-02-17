#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H

#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>
#include <algorithm>
#include <time.h>

/* Headers */
#include "CityMatrix.h"
#include "GenerationFitness.h"
/* GA Components */
#include "GASelect.h"
#include "GACrossover.h"
#include "GAMutate.h"
#include "Solution.h"
#include "Settings.h"


class GeneticAlgorithm
{
public:
	GeneticAlgorithm();
	~GeneticAlgorithm() {};

	/* Main loop: Will produce two new solutions and replace them in population for X generations */
	void evolve();
	void print();

private:
	//Config variables
	int numberOfGenerations = Settings::numberOfGenerations;
	int populationSize = Settings::populationSize;

	//Stores each soltuion in a vector of population
	std::vector<Solution> population;
	//Stores stats about each generation
	GenerationFitness generationFitnessStats;

	//Creates a population of solutions to start with 
	void create_Initial_Population();

	//Select two parents from list with some method and return them
	std::vector<Solution> select_Parents();
	/* Mix the genes of the two parents too produce offspring */
	std::vector<Solution> crossover(std::vector<Solution> parent);
	/* Chance to mutate each gene of each offspring */
	std::vector<Solution> mutate(std::vector<Solution> offspring);
	//Use tournament selection and replace lowest fitness from tournament
	void replace(std::vector<Solution> offspring, std::vector<Solution>* population);
	void save_Generation_Fitness_Stats();
};

#endif // !GENETIC_ALGORITHM_H
