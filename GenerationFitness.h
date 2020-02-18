#ifndef GENERATION_FITNESS_H
#define GENERATION_FITNESS_H

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Settings.h"

class GenerationFitness
{
public:
	GenerationFitness() { reset(); };
	~GenerationFitness() {};

	void save(std::vector<float> generation);
	void print_Top_Stats();

private:
	//Record Generation Fitness Stats
	std::map<std::string, float> stats = {
		{"worst",0},
		{"best",0},
		{"average",0}
	};

	std::vector<std::vector<float>> generationStatFromFile;

	std::string const file_name = "generation_fitness_stats.csv" ;

	void set_Best_Worst(float fitness);
	void set_Average(float average);
	void reset();
	void save_To_File();
	void print_generation();
	void load_from_file();
};
#endif // !GENERATION_FITNESS_H
