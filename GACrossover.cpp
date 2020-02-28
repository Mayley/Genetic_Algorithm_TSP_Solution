#include "GACrossover.h"

/* Crossover genes of parent solutions (exact copy or different), returns two offspring solutions */
std::vector<Solution> GACrossover::crossover(CrossoverMethod crossoverMethod) {
	//Random number to decide is parents should be crosb
	float crossoverChance = (rand() % 100) / 100.0f;
	//Check if the parents should be crossbred
	if (crossoverChance <= crossoverThreshold)
	{
		//Select correct crossover metehod
		switch (crossoverMethod)
		{
		case CrossoverMethod::ORDER:
			return order();
		case CrossoverMethod::EDGE_RECOMBINATION:
			return edgeRecombination();
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
		for (int position = ridStart; position <= ridEnd; position++)
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

		if (debugMode)
		{
			std::cout << "Cut between: " << ridStart << " -> " << ridEnd << std::endl;
			std::cout << "Parent A: " << parent[parentAid] << std::endl;
			std::cout << "Parent B: " << parent[parentBid] << std::endl;
			std::cout << "Offspring: " << offspring[parentAid] << std::endl;
		}
	}
	return offspring;
}

/* Uses a map of all genes and their edges, 
	Start with random gene, and remove that gene as edge from edgemap.
	Select next gene with least number of active edges, random on draw
	Then select a random edge from that gene
	Repeat until complete solution */
std::vector<Solution> GACrossover::edgeRecombination() {
	//Create edege map using both parents
	std::map<int, std::set<int>> edgeMap;

	//Loop through each parents genes adding as edges to map.
	for (int i = 0; i < 2; i++)
	{
		//Loop through the solution of parent, looking at the gene, before and after
		//Add theses to edge map
		for (int gene = 0; gene < parent[i].solution().size(); gene++)
		{
			int prevGene = gene;
			int nextGene = gene;
			if (gene == 0)
			{
				
				prevGene = parent[i].solution().size() - 1;
				nextGene++;
			}
			else if (gene == parent[i].solution().size() - 1)
			{
				prevGene --;
				nextGene = 0;
			}
			else {
				prevGene--;
				nextGene++;
			}
			//Add to map as edges for gene
			edgeMap[parent[i].solution()[gene]].insert(parent[i].solution()[prevGene]);
			edgeMap[parent[i].solution()[gene]].insert(parent[i].solution()[nextGene]);
		}
	}

	//Create two offspring using a copy of edgemap to work with
	for (int i = 0; i < 2; i++)
	{
		std::map<int, std::set<int>> edgeMapCopy = edgeMap;

		Solution blankSol;
		blankSol.blank_solution();
		offspring.push_back(blankSol);

		//Pick a random starting city
		int randStart = rand() % offspring[i].solution().size();
		
		//Loop through each genePosition in offspring
		for (int gene = 0; gene < offspring[i].solution().size(); gene++)
		{
			//If first gene add from randomStart
			if (gene == 0)
			{
				//Add gene and remove from edgemap
				offspring[i].set_gene_by_position(0, randStart);
				remove_Gene_From_EdgeMap(edgeMapCopy, randStart);
			}
			else {
				//Otherwise get a gene with least edges to use at position
				int geneWithLeastEdges = gene_With_Least_Edges(edgeMapCopy);
				offspring[i].set_gene_by_position(gene, geneWithLeastEdges);
				remove_Gene_From_EdgeMap(edgeMapCopy, geneWithLeastEdges);
			}	
		}

		offspring[i].calculate_fitness();
	}

	return offspring;
}

/* Take map and remove a gene as edge to all genes in that map, and the gene itself */
void GACrossover::remove_Gene_From_EdgeMap(std::map<int, std::set<int>> &edgeMap, int gene) {
	for (auto edge : edgeMap)
	{
		edge.second.erase(gene);
	}
	edgeMap.erase(gene);
}

/* Loop through each gene in the map to get the one with least edges*/
int GACrossover::gene_With_Least_Edges(std::map<int, std::set<int>>& edgeMap) {
	std::vector<int> geneWithLeastEdge;
	int edgeCount;

	for (auto edge : edgeMap)
	{
		//If no genes in vector then use first edge as minimum
		if (geneWithLeastEdge.size() == 0)
		{
			geneWithLeastEdge.push_back(edge.first);
			edgeCount = edge.second.size();
		}

		//Check if current genes edges (edge.second.size) is lower than edgecount
		//Clear all current genes, and add in new gene
		if (edge.second.size() < edgeCount)
		{
			geneWithLeastEdge.clear();
			//Add current gene to list
			geneWithLeastEdge.push_back(edge.first);
			//Change edgeCount to new amount
			edgeCount = edge.second.size();
		}
		else if (edge.second.size() == edgeCount)
		{
			geneWithLeastEdge.push_back(edge.first);
		}
		
		//Otherwise gene has a bigger edge count dont add.
	}

	//If there is more than one gene with same number of edges pick random edge
	if (geneWithLeastEdge.size() > 1)
	{
		//pick random gene from list
		int randomIndex = rand() % geneWithLeastEdge.size();
		return geneWithLeastEdge[randomIndex];
	}
	else {
		return geneWithLeastEdge[0];
	}
}