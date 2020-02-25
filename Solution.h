#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <algorithm>
#include <ostream>

//Headers
#include "CityMatrix.h"

class Solution
{
public:
	/* Create a new random solution */
	Solution();
	~Solution() {};

private:
	CityMatrix cityMatrix;

	std::vector<int> gene;
	float fitness_ = 0.0f;
	size_t geneLength = cityMatrix.dataSize();

public:
	float fitness() { return fitness_; };
	std::vector<int> solution() { return gene; };
	void set_gene_by_position(int position, int geneToAdd);
	void random_solution();
	void blank_solution();
	void calculate_fitness();
	int get_gene_by_position(int position) { return gene[position]; }
	bool check_for_duplicate_gene(int geneToAdd);

	bool operator< (const Solution& rhs) const {
		return this->fitness_ < rhs.fitness_;
	}
	bool operator< (const float& rhs) const {
		return this->fitness_ < rhs;
	}
	bool operator> (const float& rhs) const {
		return this->fitness_ > rhs;
	}
	friend std::ostream& operator<<(std::ostream& os, const Solution sol) {
		os.precision(10);
		os << "Solution: ";
		for (int i = 0; i < sol.gene.size(); i++)
		{
			if (i < sol.gene.size() - 1) {
				os << sol.gene[i] << "->";
			}
			else {
				os << sol.gene[i];
			}
			
		}

		os << "\tFitness: " << std::fixed << sol.fitness_ << std::endl;
	
		return os;
	}
	bool operator== (const Solution& rhs) const {
		return this->gene == rhs.gene;
	}
	void operator= (const Solution &rhs) {
		this->gene = rhs.gene;
		this->fitness_ = rhs.fitness_;
	}
};

#endif // !SOLUTION_H
