#ifndef GA_SELECT_H
#define GA_SELECT_H

#include <set>
#include <string>
#include "Solution.h"
#include "Settings.h"

class GASelect
{
public:
	GASelect(std::vector<Solution> currentPopulation, bool selectHighestFitness = true) {
		population = currentPopulation;
		this->selectHighestFitness = selectHighestFitness;
	};
	~GASelect() {};
	/* returns two parents based on current population depending on method type*/
	std::vector<Solution> select_Solution(SelectionMethod selectionMethod = Settings::selectionMethod);
	
private:
	int tournamentSize = Settings::tournamentSize;
	bool selectHighestFitness;
	std::vector<Solution> tournament();
	std::vector<Solution> population;
};

#endif // !GA_SELECT_H
