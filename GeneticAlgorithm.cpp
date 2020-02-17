#include "GeneticAlgorithm.h"

/* Create and populate a GA saving the first generations stats */
GeneticAlgorithm::GeneticAlgorithm() {
	//Intialise srand
	srand(time(NULL));
	create_Initial_Population();
}

/* create initial population upto populationSize */
void GeneticAlgorithm::create_Initial_Population() {
	Solution sol;
	//Creates random solution, and calculates the fitness based off the solution ID
	for (int i = 0; i < populationSize; i++)
	{
		//Randomise the solution
		sol.random_solution();
		//Add solution to population
		population.push_back(sol);
	}
}

/* Main loop of alhorithm. Runs for X generations */
void GeneticAlgorithm::evolve() {
	for (int i = 0; i < numberOfGenerations; i++)
	{	
		std::cout << "-------------------------------------------------------------------" << std::endl;
		std::cout << "Generation: " << i << std::endl;

		/* Select, Crossover, Mutate, Evaluate, then add offspring into population */
		std::vector<Solution> offspring = crossover(select_Parents());
		std::vector<Solution> mutatedSolution = mutate(offspring);
		replace(mutatedSolution, &population);
		
		//Save population at the end of the generation
		save_Generation_Fitness_Stats();
	}
}

/* after each generation save the stats (best, average, worst) from solutions in population to a file "generation_fitness.txt" */
void GeneticAlgorithm::save_Generation_Fitness_Stats() {
	//Store current generations fitness values in vector to pass to fitness storeage
	std::vector<float> generationFitness;
	//Loop through each solution in population checking agaisnt best and worst fitness
	for (int i = 0; i < population.size(); i++)
	{
		generationFitness.push_back(population[i].fitness());
	}

	//save stats
	generationFitnessStats.save(generationFitness);
}

/* Select Two parents using different selection method. Outputs two parent solutions. */
std::vector<Solution> GeneticAlgorithm::select_Parents() {
	GASelect gaSel;
	return gaSel.select_Solution(population);
}

/* Crossover genes of parent solutions (exact copy or different) */
std::vector<Solution> GeneticAlgorithm::crossover(std::vector<Solution> parent) {
	GACrossover gaCrossover;
	return gaCrossover.crossover(parent);
}

/* Randomly mutates each gene of the solution */
std::vector<Solution> GeneticAlgorithm::mutate(std::vector<Solution> offspring) {
	GAMutate gaMutate;
	return gaMutate.mutate(offspring);	
}

/* Take the offspring and replace them with the lowest rated solution from population using tournament method*/
void GeneticAlgorithm::replace(std::vector<Solution> offspring, std::vector<Solution> *population) {
	GASelect sel;
	//Select two solutions to remove, based on lowest fitness winning
	std::vector<Solution> replaceSolution = sel.select_Solution(*population, false);

	//Now replace these soltions with the offspring solutions
	for (int replaceSolutionID = 0; replaceSolutionID < replaceSolution.size(); replaceSolutionID++)
	{
		auto it = std::find(population->begin(), population->end(), replaceSolution[replaceSolutionID]);
		if (it != population->end()) {
			int id = it - population->begin();
			population->erase(it);

			population->push_back(offspring[replaceSolutionID]);
		}
	}
}

void GeneticAlgorithm::print() {
	generationFitnessStats.print_Top_Stats();
}