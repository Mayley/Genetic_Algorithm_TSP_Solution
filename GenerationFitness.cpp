#include "GenerationFitness.h"

void GenerationFitness::reset() {
	stats["best"] = 0;
	stats["worst"] = 1;
	stats["average"] = NULL;
}

void GenerationFitness::save(std::vector<float> generation) {
	//reset previous generation before saving newest generation;
	reset();

	float totalFitness = 0.0f;
	float average = 0.0f;

	for (int i = 0; i < generation.size(); i++)
	{
		set_Best_Worst(generation[i]);
		totalFitness += generation[i];
	}

	average = totalFitness / generation.size();
	set_Average(average);

	//print();

	save_To_File();
}

void GenerationFitness::save_To_File() {
	std::ofstream generationFitnessFile(file_name, std::ios::app);

	//If the file doesnt't exist then create the file
	if (!generationFitnessFile) {
		std::ofstream generationFitnessFile(file_name);
	}

	//Print generation
	print_generation();

	//Open file else output error
	if (generationFitnessFile.is_open()) {

		//set precision
		generationFitnessFile.precision(10);
		generationFitnessFile << std::fixed << stats["best"] << ","
			<< stats["average"] << ","
			<< stats["worst"] << std::endl;

		generationFitnessFile.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
	}

}

/* 1/fitness so a higher number is a better fitness */
void GenerationFitness::set_Best_Worst(float fitness) {
	if (fitness < stats["worst"]) {
		stats["worst"] = fitness;
	}
	else if (fitness > stats["best"]) {
		stats["best"] = fitness;
	}
}

void GenerationFitness::set_Average(float average) {
	stats["average"] = average;
}

void GenerationFitness::print_generation() {
	std::cout.precision(10);

	std::cout << std::fixed << "Best: " << stats["best"] << std::endl;
	std::cout << "Average: " << stats["average"] << std::endl;
	std::cout << "Worst: " << stats["worst"] << std::endl;}

void GenerationFitness::print_Top_Stats() {
	load_from_file();

	//Loop through each generation and store stats
	for (int i = 0; i < generationStatFromFile.size(); i++)
	{
		//Print best solution fitness for each
		if (generationStatFromFile[i][0] >= stats["best"])
		{
			stats["best"] = generationStatFromFile[i][0];
		}
		if (generationStatFromFile[i][1] >= stats["average"])
		{
			stats["average"] = generationStatFromFile[i][1];
		}
		if (generationStatFromFile[i][2] <= stats["worst"])
		{
			stats["worst"] = generationStatFromFile[i][2];
		}
	}

	generationStatFromFile.clear();

	print_generation();
}

void GenerationFitness::load_from_file() {
	std::ifstream generationFitnessFile(file_name);

	if (generationFitnessFile.is_open()) {
		std::string line;
		char delim = ',';
		//Get generation
		while (std::getline(generationFitnessFile, line))
		{
			//Store the current line(row) in a string stream and split by deliminater for the values
			std::istringstream dataLine(line);
			std::string data;
			std::vector<float> dataVector;

			//Get stats
			while (std::getline(dataLine, data, delim)) {
				//Store the rows data in the vector as columns
				dataVector.push_back(std::stof(data));
			}
			
			generationStatFromFile.push_back(dataVector);
		}
		//close file
		generationFitnessFile.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;;
	}


}