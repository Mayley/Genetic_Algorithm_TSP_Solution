#ifndef GA_SELECT_H
#define GA_SELECT_H

#include <set>
#include <string>
#include "Solution.h"
#include "Settings.h"

enum class selectionMethodType : int {
	SELECT_TOURNAMENT = 0,
};

class GASelect
{
public:
	GASelect(std::vector<Solution> currentPopulation, bool selectHighestFitness = true) {
		population = currentPopulation;
		this->selectHighestFitness = selectHighestFitness;
	};
	~GASelect() {};
	/* returns two parents based on current population depending on method type*/
	std::vector<Solution> select_Solution(selectionMethodType selectionMethod = selectionMethodType::SELECT_TOURNAMENT );
	
private:
	int tournamentSize = Settings::tournamentSize;
	bool selectHighestFitness = true;
	std::vector<Solution> tournament();
	std::vector<Solution> population;
};

#endif // !GA_SELECT_H
