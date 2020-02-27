#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H

#include <set>
#include <stdlib.h>
#include <algorithm>
#include <time.h>

/* Headers */
#include "CityMatrix.h"
#include "PopulationFitness.h"
#include "GASelect.h"
#include "GACrossover.h"
#include "GAMutate.h"
#include "MenuController.h"

class GeneticAlgorithm
{
private:
	//Config variables
	int numberOfGenerations = Settings::numberOfGenerations;
	int populationSize = Settings::populationSize;

	//Stores each solution in a vector of population
	std::vector<Solution> population;
	//Stores stats about each generation
	PopulationFitness populationFitness;
public:
	GeneticAlgorithm();
	~GeneticAlgorithm() {};

	/* Main access to the GA*/
	void main_Menu();

private:
	/* Main loop: Will produce two new solutions and replace them in population for X generations */
	void evolve();

	//Creates a population of solutions to start with 
	void setup_Random_Population();

	//Select two parents from list with some method and return them
	std::vector<Solution> select_Parents();
	/* Mix the genes of the two parents too produce offspring */
	std::vector<Solution> crossover(std::vector<Solution> parents);
	/* Chance to mutate each gene of each offspring */
	std::vector<Solution> mutate(std::vector<Solution> offspring);
	//Use tournament selection and replace lowest fitness from tournament
	void replace(std::vector<Solution> offspring);
};

#endif // !GENETIC_ALGORITHM_H
