#ifndef GA_MUTATE_H
#define GA_MUTATE_H

#include "Solution.h"
#include "Settings.h"

enum class MutationMethod {
	SWAP,
};

class GAMutate
{
public:
	std::vector<Solution> mutate(std::vector<Solution> offspring, MutationMethod mutationMethod = MutationMethod::SWAP);

private:
	float mutationThreshold = Settings::mutationThreshold;
	std::vector<Solution> offspring;
	std::vector<Solution> swap();
};
#endif // !MUTATE_H
