#include "GACrossover.h"

/* Crossover genes of parent solutions (exact copy or different), returns two offspring solutions */
std::vector<Solution> GACrossover::crossover(CrossoverMethod crossoverMethod) {
	//Random number to decide is parents should be crosb
	float crossoverChance = (rand() % 10) / 100.0f;
	//Check if the parents should be crossbred
	if (crossoverChance <= crossoverThreshold)
	{
		//Select correct crossover metehod
		switch (crossoverMethod)
		{
		case CrossoverMethod::ORDER:
			return order();
		case CrossoverMethod::MODIFIED_PARTIALLY_MAPPED:
			return modified_Partially_Mapped();
		default:
			break;
		}		
	}

	//If no crossbreed just return the same parents
	return parent;
}

/* Select subset of genes from parentA and copy to offsprint then copy rest of genes from parentB */
std::vector<Solution> GACrossover::order() {
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

/* Split parent solution into left/middle/right, copy the middle portion to offspring
	Then fill left/right sections with parentB unless already used
	finally fill solution with random unsued gene */
std::vector<Solution> GACrossover::modified_Partially_Mapped() {
	//Get split locations
	int ridStart, ridEnd;
	ridEnd = rand() % parent[0].solution().size();
	if (ridEnd > 0)
	{
		ridStart = rand() % ridEnd;
	}
	else {
		ridStart = 0;
	}

	for (int parentAid = 0; parentAid < parent.size(); parentAid++)
	{
		Solution blankSol;
		blankSol.blank_solution();
		offspring.push_back(blankSol);

		//Copy genes from middle section of parent A to offspring
		for (int position = ridStart; position < ridEnd; position++)
		{
			offspring[parentAid].set_gene_by_position(position, *std::next(parent[parentAid].solution().begin(), position));
		}

		//Use the next parent to fill gene
		int parentBid = parentAid + 1;
		//If last parent then restart from beginning
		if (parentBid >= parent.size())
		{
			parentBid = 0;
		}

		// Add genes from Parent B to coresponding positions if possible
		for (int parentGenePosition = 0; parentGenePosition < parent[parentBid].solution().size(); parentGenePosition++)
		{
		}

		//Fill empty genes randomly



		//Calculate new fitness of solution
		offspring[parentAid].calculate_fitness();

		//std::cout << "Parent A: " << parent[parentAid] << std::endl << "Parent B: " << parent[parentBid] << std::endl << "Offspring: " << offspring[parentAid] << std::endl;
	}
}