#ifndef GA_SELECT_H
#define GA_SELECT_H

#include <set>
#include <string>
#include "Solution.h"
#include "Settings.h"

class GASelect
{
public:
	GASelect(std::vector<Solution> *population) : population(population) {};
	~GASelect() {};
	/* returns two parents based on current population depending on method type*/
	std::vector<Solution> select_Solution(bool highestFitness = true);
	
private:
	SelectionMethod selectionMethod = Settings::selectionMethod;
	int tournamentSize = Settings::tournamentSize;
	bool highestFitness;
	std::vector<Solution> tournament();
	std::vector<Solution> *population;
};

#endif // !GA_SELECT_H
