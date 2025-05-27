// implement MatrixLoader functions

#include <fstream>
#include <sstream>
#include <stdexcept>
#include "MatrixLoader.hpp"

// load the matrix A from file
Eigen::MatrixXd MatrixLoader::loadMatrix(const std::string& fileName) {

	// open file containing components of A
	std::ifstream file(fileName);

	// can't open file
	if (!file) throw std::runtime_error("File Note Found!");

	// temp. storage for parse rows of file 
	std::vector<std::vector<double>> data;

	// for reading lines of file
	std::string line;

	// read file line by line
	while (getline(file, line)) {

		// create stringstream to parse each line
		std::stringstream ss(line);

		std::vector<double> row;

		double value{0.0};

		// read values in the current line
		while (ss >> value) { row.push_back(value); }

		// store parsed row
		data.push_back(row);
	}

	// create a matrix for storing parsed values
	Eigen::MatrixXd mat(data.size(), data[0].size());

	for (size_t i{0}; i < data.size(); ++i) {
		for (size_t j{0}; j < data[i].size(); ++j) {

			// fill matrix with parsed values
			mat(i, j) = data[i][j];
		}
	}

	return mat;
}

// load column vector b from file
Eigen::VectorXd MatrixLoader::loadVector(const std::string& fileName) {

	// open file containing components of b
	std::ifstream file(fileName);

	// can't open file
	if (!file) throw std::runtime_error("File Not Found!"); 

	// temp. storage for parse rows of file 
	std::vector<double> data;

	double value{0.0};

	// read values in the current line
	while (file >> value) { data.push_back(value); }

	Eigen::VectorXd vec(data.size());

	for (size_t i{0}; i < data.size(); ++i) {

		// fill the vector with data
		vec(i) = data[i];
	}

	return vec;
}