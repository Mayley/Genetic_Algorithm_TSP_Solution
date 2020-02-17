#ifndef GA_SELECT_H
#define GA_SELECT_H

#include <set>
#include "Solution.h"
#include "Settings.h"


class GASelect
{
public:
	GASelect() {};
	~GASelect() {};
	std::vector<Solution> select_Solution(std::vector<Solution> population, bool highestFitness = true);
	
private:
	int tournamentSize = Settings::tournamentSize;
	std::vector<Solution> tournament(std::vector<Solution> population, bool highestFitness);


};

#endif // !GA_SELECT_H
