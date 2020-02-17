#include "Solution.h"

Solution::Solution() {
	//Setup vector with ID's for all genes upto gene length
	for (int i = 0; i < geneLength; i++)
	{
		gene.push_back(i);
	}
}

/* randomize a solutions gene order */
void Solution::random_solution() {
	//Randomise the gene order
	std::random_shuffle(gene.begin(), gene.end());

	//Calculate new fitness
	calculate_fitness();
}

void Solution::calculate_fitness() {
	int distance = 0;

	//Loop through the Gene vector with i & i+1 using the int as the ID for the City
	for (int geneID = 0; geneID < gene.size(); geneID++)
	{
		//If its last gene then use gene 0 as second ID
		if (geneID ==gene.size() - 1) {
			distance += cityMatrix.travel_Distance(gene[geneID], 0);
		}
		else {
			distance += cityMatrix.travel_Distance(gene[geneID], gene[geneID + 1]);
		}
	}

	fitness_ = 1.0f/ distance;
}

void Solution::set_gene_by_position(int position, int geneToAdd) {
	gene[position] = geneToAdd;
}

/* Sets all genes to -1 to show they're free */
void Solution::blank_solution() {
	for (int i = 0; i < gene.size(); i++)
	{
		gene[i] = -1;
	}
}

/* Checks genes currently in solution to see if its duplicate returns true if duplicate */
bool Solution::check_for_duplicate_gene(int geneToAdd) {
	for (int i = 0; i < gene.size(); i++)
	{
		if (gene[i] == geneToAdd)
		{
			//std::cout << "Duplicate Gene: " << gene[i] << ":" << geneToAdd << std::endl;
			return true;
		}
	}
	return false;
}