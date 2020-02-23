#ifndef CITY_MATIX_H
#define CITY_MATIX_H

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

class CityMatrix
{
public:
	CityMatrix() { load_Travel_Distance_From_File(); };
	~CityMatrix() {};

	int travel_Distance(int cityA, int cityB);
	size_t dataSize() { return travelDistance.size(); };

private:
	std::vector<std::vector<int>> travelDistance;
	const std::string cityMatrixFileName = "distance_matrix.csv";

	void load_Travel_Distance_From_File();
	void print_Matrix();
};

#endif // !CITY_MATIX_H
