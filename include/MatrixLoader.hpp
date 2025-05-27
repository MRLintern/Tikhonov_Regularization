// MatrixLoader.hpp

// provides methods for reading components of a matrix and a vector stored in .txt files

// system considered: Ax = b

#pragma once

#include <string>
#include <Eigen/Dense>

class MatrixLoader {

public:

	// reads in the components of matrix A from txt file
	static Eigen::MatrixXd loadMatrix(const std::string& fileName);

	// reads in the components of vector b from txt file
	static Eigen::VectorXd loadVector(const std::string& fileName);
};
