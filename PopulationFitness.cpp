#include "PopulationFitness.h"

void PopulationFitness::reset_Stats() {
	stats["best"] = 0;
	stats["worst"] = 1;
	stats["average"] = NULL;
}

/* Saves the best, worst, average stats of a given population to a file,
	printing the stats at the end*/
void PopulationFitness::save(std::vector<Solution> population) {
	//reset previous stats before saving.
	reset_Stats();

	this->population = population;
	
	//Loop through population
	float averageFitness = 0;
	for (int i = 0; i < population.size(); i++)
	{
		//Check to see if its best or worst
		if (population[i] > stats["best"])
		{
			stats["best"] = population[i].fitness();
		}
		else if (population[i] < stats["worst"])
		{
			stats["worst"] = population[i].fitness();
		}

		//Add to average to get the total fitness of all in population
		averageFitness += population[i].fitness();
	}

	//Set average fitness
	stats["average"] = (averageFitness / population.size());

	save_To_File();
	print();
}

void PopulationFitness::print() {
	std::cout.precision(10);
	std::cout << std::fixed << "Best: " << stats["best"] << std::endl;
	std::cout << "Average: " << stats["average"] << std::endl;
	std::cout << "Worst: " << stats["worst"] << std::endl;
}

void PopulationFitness::print_from_file() {
	load_from_file();
	print();
}

void PopulationFitness::clear_stats_file() {
	remove(file_name.c_str());
}

void PopulationFitness::save_To_File() {
	std::ofstream populationFitnessFile(file_name, std::ios::app);

	//If the file doesnt't exist then create the file
	if (!populationFitnessFile) {
		std::ofstream generationFitnessFile(file_name);
	}

	//Open file else output error
	if (populationFitnessFile.is_open()) {

		//set precision
		populationFitnessFile.precision(10);
		populationFitnessFile << std::fixed << stats["best"] << ","
			<< stats["average"] << ","
			<< stats["worst"] << std::endl;

		populationFitnessFile.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
	}

}

void PopulationFitness::load_from_file() {
	std::ifstream populationFitnessFile(file_name);

	//Check if we can open the file else output error
	if (populationFitnessFile.is_open()) {

		//Get each line from the csv file
		std::string line;
		char delim = ',';
		//Get line by line
		while (std::getline(populationFitnessFile, line))
		{
			//Store the current line(row) in a string stream and split by deliminater for the values
			std::istringstream dataLine(line);
			std::string data;
			std::vector<float> dataVector;

			//Save line data into a vector separated by ","
			while (std::getline(dataLine, data, delim)) {
				//Store the rows data in the vector as columns
				dataVector.push_back(std::stof(data));
			}

			//Check line data against current stats and save if needed
			if (dataVector[0] > stats["best"])
			{
				stats["best"] = dataVector[0];
			}
			if (dataVector[1] > stats["average]"])
			{
				stats["average"] = dataVector[1];
			}
			if (dataVector[2] < stats["worst"])
			{
				stats["worst"] = dataVector[2];
			}
		}
		//close file
		populationFitnessFile.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;;
	}
}