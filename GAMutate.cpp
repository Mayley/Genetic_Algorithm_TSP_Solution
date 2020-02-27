#include "GAMutate.h"

/* Method of mutating each gene of offspring */
std::vector<Solution> GAMutate::mutate(std::vector<Solution> offspring, MutationMethod mutationMethod) {
	this->offspring = offspring;

	//Return offspring based on mutation method where default is swap;
	switch (mutationMethod)
	{
	case MutationMethod::SWAP:
		return swap();
		break;
	default:
		return swap();
		break;
	}
}

/* On gene mutation swaps selected gene with any random gene */
std::vector<Solution> GAMutate::swap() {
	//Run for each each offspring
	for (int offspringID = 0; offspringID < offspring.size(); offspringID++)
	{
		//Run for each gene in offspring
		for (int genePosition = 0; genePosition < offspring[offspringID].solution().size(); genePosition++)
		{
			//Random number to decide if gene should mutate
			float mutateChance = (rand() % offspring[offspringID].solution().size()) / 100.0f;
			if (mutateChance <= mutationThreshold)
			{
				//Mutate Gene
				//Select random gene to swap with
				int swapGenePosition = 0;
				do
				{
					swapGenePosition = rand() % offspring[offspringID].solution().size();
				} while (swapGenePosition == genePosition);

				//Swap genes
				int gene1 = offspring[offspringID].get_gene_by_position(genePosition);
				int gene2 = offspring[offspringID].get_gene_by_position(swapGenePosition);
				offspring[offspringID].set_gene_by_position(genePosition, gene2);
				offspring[offspringID].set_gene_by_position(swapGenePosition, gene1);
			}
		}
	}

	//return mutated offspring
	return (offspring);
}
