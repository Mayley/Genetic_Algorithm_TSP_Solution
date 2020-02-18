#include "GASelect.h"

/* Returns two parents selected with different methods 
   defaulted to tournament and highest selection. 
   Pass in current generation population*/
std::vector<Solution> GASelect::select_Solution(SelectionMethod selectionMethod) {
	// Return two parents using diferent selection methods.	
	switch (selectionMethod)
	{
	case SelectionMethod::TOURNAMENT:
		return tournament();
	default:
		break;
	}
}

/* Selects two parents with bias to highestFitness from a tournament of solutions */
std::vector<Solution> GASelect::tournament() {
	//Return parents selected from tournament
	std::vector<Solution> parents;

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

			//Get solution from population using rid as index position
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

			//Remove from pool for next tournament
			population.erase(population.begin() + rid);
		}

		//Return the required parent based on highest or lowest first.
		if (selectHighestFitness)
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

