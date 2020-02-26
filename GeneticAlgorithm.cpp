#include "GeneticAlgorithm.h"

/* Create and populate a GA saving the first generations stats */
GeneticAlgorithm::GeneticAlgorithm() : populationFitness(&population) {
	//Intialise srand
	srand(time(NULL));
	setup_Random_Population();
}

/* create initial population upto populationSize */
void GeneticAlgorithm::setup_Random_Population() {
	Solution sol;
	//Create and add solution to population
	for (int i = 0; i < populationSize; i++)
	{
		//Randomise the solution and add to population
		sol.random_solution();
		//Add solution to population
		population.push_back(sol);
	}
}

/* Gives access to the Genetic Algorithm */
void GeneticAlgorithm::main_Menu() {
	MenuController menu("Genetic Algorithm for TSP!");
	int menuChoice;

	menu.add_Menu_Option("Evolve");
	menu.add_Menu_Option("Print");
	menu.add_Menu_Option("Clear");
	menu.add_Menu_Option("Reset");
	menu.add_Menu_Option("Settings");

	do
	{
		menu.display();

		std::cin >> menuChoice;

		switch (menuChoice)
		{
		case 1:
			evolve();
			break;
		case 2:
			populationFitness.main_Menu();
			break;
		case 3:
			populationFitness.clear_Stats_File();
			break;
		case 4:
			setup_Random_Population();
		case 5:
			Settings::menu();
		default:
			break;
		}

	} while (menuChoice > 0);
}


/* Main loop of alhorithm. Runs for X generations */
void GeneticAlgorithm::evolve() {
	for (int i = 0; i < numberOfGenerations; i++)
	{	
		//std::cout << "-------------------------------------------------------------------" << std::endl;
		//std::cout << "Generation: " << i+1 << std::endl;

		/* Select, Crossover, Mutate, Evaluate, then add offspring into population */
		replace(mutate(crossover(select_Parents())));
		
		//Save population at the end of the generation
		populationFitness.save();
	}
}

/* Select Two parents using different selection method. Outputs two parent solutions. */
std::vector<Solution> GeneticAlgorithm::select_Parents() {
	GASelect sel(population);
	return sel.select_Solution(SelectionMethod::TOURNAMENT);
}

/* Crossover genes of parent solutions (exact copy or different) */
std::vector<Solution> GeneticAlgorithm::crossover(std::vector<Solution> parents) {
	GACrossover gaCrossover(parents);
	return gaCrossover.crossover();
}

/* Randomly mutates each gene of the solution */
std::vector<Solution> GeneticAlgorithm::mutate(std::vector<Solution> offspring) {
	GAMutate gaMutate;
	return gaMutate.mutate(offspring, MutationMethod::SWAP);	
}

/* Take the offspring and replace them with the lowest rated solution from population using tournament method*/
void GeneticAlgorithm::replace(std::vector<Solution> offspring) {
	//Load select module with current pop and selecting the lowest fitness
	GASelect sel(population, false);
	//Select two solutions to remove, based on lowest fitness winning
	std::vector<Solution> replaceSolution = sel.select_Solution(SelectionMethod::TOURNAMENT);

	//Now replace these soltions with the offspring solutions
	for (int replaceSolutionID = 0; replaceSolutionID < replaceSolution.size(); replaceSolutionID++)
	{
		auto it = std::find(population.begin(), population.end(), replaceSolution[replaceSolutionID]);
		if (it != population.end()) {
			int id = it - population.begin();
			population.erase(it);

			population.push_back(offspring[replaceSolutionID]);
		}
	}
}