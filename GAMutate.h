#ifndef GA_MUTATE_H
#define GA_MUTATE_H

#include "Solution.h"
#include "Settings.h"

class GAMutate
{
public:
	std::vector<Solution> mutate(std::vector<Solution> offspring);

private:
	float mutationThreshold = Settings::mutationThreshold;

	std::vector<Solution> swap(std::vector<Solution> offspring);
};
#endif // !MUTATE_H
