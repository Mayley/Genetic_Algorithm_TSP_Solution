#ifndef GENERATION_FITNESS_H
#define GENERATION_FITNESS_H

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
//Headers
#include "Settings.h"
#include "Solution.h"

class PopulationFitness
{
public:
	PopulationFitness(std::vector<Solution> *population);
	~PopulationFitness() {};

	/* Save best, worst, average fitness of the population saving it to a file*/
	void save();
	void print_Population_Stats();
	void print_from_file();
	void clear_stats_file();

private:
	//Record Fitness Stats
	std::map<std::string, float> stats = {
		{"worst",0},
		{"best",1},
		{"average",NULL}
	};
	
	std::string fileName = crossover_Method_String(true) + "_generation_stats.csv";
	std::vector<Solution> *population;

	void reset_Stats();
	void save_To_File();
	void load_from_file();
	void set_Stats();
	void print();
};
#endif // !GENERATION_FITNESS_H
