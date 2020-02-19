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
	GAMutate(std::vector<Solution> offspring) {
		this->offspring = offspring;
	}
	std::vector<Solution> mutate(MutationMethod mutationMethod = MutationMethod::SWAP);

private:
	float mutationThreshold = Settings::mutationThreshold;
	std::vector<Solution> offspring;
	std::vector<Solution> swap();
};
#endif // !MUTATE_H
