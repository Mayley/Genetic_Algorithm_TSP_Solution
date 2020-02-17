#include "GASelect.h"

/* Select Two parents using different selection method. Outputs two parent solutions. Fitness of 1 */
std::vector<Solution> GASelect::select_Solution(std::vector<Solution> population, bool highestFitness) {
	//Return solutions selected using tournament selection
	return tournament(population, highestFitness);
}

/* Selects two parents with bias to highestFitness from a tournament of solutions */
std::vector<Solution> GASelect::tournament(std::vector<Solution> population, bool highestFitness) {
	//Return parents selected from tournament
	std::vector<Solution> parents;

	////Holds all current solutions in population
	//std::set<Solution> tournamentSelection;
	//tournamentSelection.clear();
	////Insert all current population solutions into tournament
	//for (int i = 0; i < population.size(); i++)
	//{
	//	tournamentSelection.insert(population[i]);
	//	std::cout << "Setup tournament pool" << std::endl;
	//}

	//Run tournament once for each parent
	for (int i = 0; i < 2; i++)
	{
		std::set<Solution> tournament;

		//Select the four solutions for the tournament
		for (int i = 0; i < tournamentSize; i++)
		{
			//Get random solution ID to add to tournament
			int rid;
			if (population.size() > 1)
			{
				rid = rand() % population.size();
			}
			else {
				rid = 0;
			}

			//Get solution from rid
			auto it = std::next(population.begin(), rid);
			Solution selectedSolution;
			if (it != population.end())
			{
				//Solution in tournament
				selectedSolution = *it;
			}
			else {
				std::cout << "Error in tournament Selection rid" << std::endl;
			}
			

			//Add solution to tournament
			tournament.insert(selectedSolution);

			//Remove from pool
			population.erase(population.begin() + rid);
		}

		if (highestFitness)
		{
			//Ordered list (<) so highest fitness is last
			parents.push_back(*std::next(tournament.begin(), tournament.size() - 1));
		}
		else {
			//Select from bottom of list
			parents.push_back(*tournament.begin());
		}
	}
	return parents;
}

