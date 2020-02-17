#include "GACrossover.h"

/* Crossover genes of parent solutions (exact copy or different) */
std::vector<Solution> GACrossover::crossover(std::vector<Solution> parent) {
	//Random number to decide is parents should be crosb
	float crossoverChance = (rand() % 10) / 100.0f;
	//Check if the parents should be crossbred
	if (crossoverChance <= crossoverThreshold)
	{
		//Crossbreed parents
		return (order(parent));
	}

	return parent;
	//Else do not crossbreed
}

/* Select subset of genes from parentA and copy to offsprint then copy rest of genes from parentB */
std::vector<Solution> GACrossover::order(std::vector<Solution> parent) {
	//Stores the two new offspring to replace in population
	std::vector<Solution> offspring;

	//Get random index to copy genes from used for both parents
	int ridStart, ridEnd;
	ridEnd = rand() % parent[0].solution().size();
	if (ridEnd > 0)
	{
		ridStart = rand() % ridEnd;
	}
	else {
		ridStart = 0;
	}

	//Make a new child for each parent there is
	for (int parentAid = 0; parentAid < parent.size(); parentAid++)
	{
		Solution blankSol;
		blankSol.blank_solution();
		offspring.push_back(blankSol);

		//Get gene from parent A solution position (for ridStart - End) and change offspringSolution genepositon to the copied gene
		for (int position = ridStart; position < ridEnd; position++)
		{
			offspring[parentAid].set_gene_by_position(position, *std::next(parent[parentAid].solution().begin(), position));
		}

		//Use the next parent for the rest of the genes
		int parentBid = parentAid + 1;
		//If last parent then restart from beginning
		if (parentBid >= parent.size())
		{
			parentBid = 0;
		}

		// Try to add the genes from Parent B starting from gene0
		for (int parentGenePosition = 0; parentGenePosition < parent[parentBid].solution().size(); parentGenePosition++)
		{
			// Check if the current gene is already in the offspring solution
			if (!offspring[parentAid].check_for_duplicate_gene(parent[parentBid].get_gene_by_position(parentGenePosition)))
			{
				//Isn't duplicate, loop through offspring for next free gene
				for (int offspringGenePosition = 0; offspringGenePosition < offspring[parentAid].solution().size(); offspringGenePosition++)
				{
					//If gene is -1 then it is free
					if (offspring[parentAid].get_gene_by_position(offspringGenePosition) == -1)
					{
						//Change gene to new gene
						offspring[parentAid].set_gene_by_position(offspringGenePosition, parent[parentBid].get_gene_by_position(parentGenePosition));
						//Break out of loop and add next gene
						break;
					}
				}
			}
		}
		//Calculate new fitness of solution
		offspring[parentAid].calculate_fitness();

		//std::cout << "Parent A: " << parent[parentAid] << std::endl << "Parent B: " << parent[parentBid] << std::endl << "Offspring: " << offspring[parentAid] << std::endl;
	}
	return offspring;
}
