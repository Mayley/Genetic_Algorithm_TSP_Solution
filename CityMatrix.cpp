#include "CityMatrix.h"

/* Load the distance between cities from a csv file */
void CityMatrix::load_Travel_Distance_From_File() {
	std::ifstream cityMatrixFile(cityMatrixFileName);

	if (cityMatrixFile.is_open()) {
		std::string line;
		char delim = ',';
		//Get each row of the matrix
		while (std::getline (cityMatrixFile, line))
		{
			//Store the current line(row) in a string stream and split by deliminater for the values
			std::istringstream dataLine(line);
			std::string data;
			std::vector<int> dataVector;

			//Get each column of the matrix for the row
			while (std::getline(dataLine, data, delim)) {
				//Store the rows data in the vector as columns
				dataVector.push_back(std::stoi(data));
			}
			//push vector to travelDistance
			travelDistance.push_back(dataVector);
		}
		//close file
		cityMatrixFile.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;;
	}

	// print_Matrix();
}

/* Print out the city matrix to check values */
void CityMatrix::print_Matrix() {
	//Iterate for eaach row
	for (int x = 0; x < travelDistance.size(); x++)
	{
		//iterate for each column
		for (int y = 0; y < travelDistance[x].size(); y++)
		{
			std::cout << travelDistance[x][y] << " ";
		}

		std::cout << std::endl;
	}
}

/* Input two city ID's and et the distance back between them from travelDistance[a][b]*/
int CityMatrix::travel_Distance(int cityA, int cityB) {
	//std::cout << travelDistance[cityA][cityB] << std::endl;
	return travelDistance[cityA][cityB];
}