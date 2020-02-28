#include "GeneticAlgorithm.h"

/* Create and populate a GA saving the first generations stats */
GeneticAlgorithm::GeneticAlgorithm() : populationFitness(&population) {
	//Intialise srand
	srand(time(NULL));
	setup_Random_Population();

	numberOfGenerations = &Settings::numberOfGenerations;
	gaSelect = new GASelect(&population);
}

GeneticAlgorithm::~GeneticAlgorithm() {
	delete gaSelect;
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
	MenuController menu("Main Menu!", true);
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
			break;
		case 5:
			Settings::menu();
			break;
		default:
			break;
		}

	} while (menuChoice > -1);
}

/* Main loop of alhorithm. Runs for X generations */
void GeneticAlgorithm::evolve() {
	for (int i = 0; i < Settings::numberOfGenerations; i++)
	{	
		if (debugMode)
		{
			std::cout << "-------------------------------------------------------------------" << std::endl;
			std::cout << "Generation: " << i + 1 << std::endl;
		}
		else {
			std::cout << i << "|";
		}

		/* Select, Crossover, Mutate, Evaluate, then add offspring into population */
		replace(mutate(crossover(select_Parents())));
		
		//Save population at the end of the generation
		populationFitness.save();
	}
}

/* Select Two parents using different selection method. Outputs two parent solutions. */
std::vector<Solution> GeneticAlgorithm::select_Parents() {
	return gaSelect->select_Solution();
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
	//Select two solutions to remove, based on lowest fitness winning
	std::vector<Solution> replaceSolution = gaSelect->select_Solution(false);

	//Now replace these soltions with the offspring solutions
	for (int replaceSolutionID = 0; replaceSolutionID < replaceSolution.size(); replaceSolutionID++)
	{
		//Gets the index of the solution in population with a matching gene order
		auto it = std::find(population.begin(), population.end(), replaceSolution[replaceSolutionID]);
		if (it != population.end()) {
			population.erase(it);
			
			population.push_back(offspring[replaceSolutionID]);
		}
	}
}