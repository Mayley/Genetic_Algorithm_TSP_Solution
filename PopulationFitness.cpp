#include "PopulationFitness.h"

PopulationFitness::PopulationFitness(std::vector<Solution> *population) : population(population) {
	reset_Stats();
};

void PopulationFitness::reset_Stats() {
	stats["best"] = 0;
	stats["worst"] = 1;
	stats["average"] = NULL;
}

/* Saves the best, worst, average stats of a given population to a file,
	printing the stats at the end*/
void PopulationFitness::save() {
	//reset previous stats before saving.
	reset_Stats();
	//Set stats in varible for current population
	set_Stats();
	//Save generation stats to file
	save_To_File();
	//Print
	print();
}

void PopulationFitness::set_Stats() {
	//Loop through population
	float averageFitness = 0;
	for (int i = 0; i < population->size(); i++)
	{
		//Check to see if its best or worst
		if ((*population)[i] > stats["best"])
		{
			stats["best"] = (*population)[i].fitness();
		}
		else if ((*population)[i] < stats["worst"])
		{
			stats["worst"] = (*population)[i].fitness();
		}

		//Add to average to get the total fitness of all in population
		averageFitness += (*population)[i].fitness();
	}

	//Set average fitness
	stats["average"] = (averageFitness / population->size());
}

void PopulationFitness::print_Population_Stats() {
	set_Stats();
	print();
}

void PopulationFitness::print_From_File() {
	reset_Stats();
	load_From_File();
	print();
}

void PopulationFitness::clear_Stats_File() {
	remove(fileName.c_str());
}

void PopulationFitness::save_To_File() {
	std::ofstream populationFitnessFile(fileName, std::ios::app);

	//If the file doesnt't exist then create the file
	if (!populationFitnessFile) {
		std::ofstream generationFitnessFile(fileName);
	}

	//Open file else output error
	if (populationFitnessFile.is_open()) {

		//set precision
		populationFitnessFile.precision(10);
		populationFitnessFile << std::fixed << stats["best"] << ","
			<< stats["average"] << ","
			<< stats["worst"] << std::endl;
	}
	else {
		std::cout << "Unable to open file" << std::endl;
	}

	populationFitnessFile.close();
}

void PopulationFitness::load_From_File() {
	std::ifstream populationFitnessFile(fileName);
	int totalGenerations = 0;

	//Check if we can open the file else output error
	if (populationFitnessFile.is_open()) {

		//Get each line from the csv file
		std::string line;
		char delim = ',';
		//Get line by line
		while (std::getline(populationFitnessFile, line))
		{
			//Increment the generation for each line
			totalGenerations++;

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
			if (dataVector[1] > stats["average"])
			{
				stats["average"] = dataVector[1];
			}
			if (dataVector[2] < stats["worst"])
			{
				stats["worst"] = dataVector[2];
			}
		}

		std::cout << "Loaded Data from: " << fileName << std::endl;
		std::cout << "Total generations recorded: " << totalGenerations << std::endl;
	}
	else {
		std::cout << "Unable to open file" << std::endl;;
	}

	populationFitnessFile.close();
}

void PopulationFitness::print() {
	std::cout.precision(10);
	std::cout << std::fixed << "Best: " << stats["best"] << std::endl;
	std::cout << "Average: " << stats["average"] << std::endl;
	std::cout << "Worst: " << stats["worst"] << std::endl;

}