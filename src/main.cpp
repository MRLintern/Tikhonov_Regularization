// driver: load input, run Tikhonov solver and display/print solution

#include <iostream>
#include "RegularizationSolver.hpp"
#include "MatrixLoader.hpp"

int main() {

	try {

		// load forward model/system matrix A from txt file
		Eigen::MatrixXd A = MatrixLoader::loadMatrix("A.txt");

		// load RHS of algebraic system; data vector
		Eigen::VectorXd b = MatrixLoader::loadVector("b.txt");

		// regularization factor
		double lambda{0.1};

		// create solver object
		RegularizationSolver solver(A, b, lambda);

		// compute the regularized solution x
		Eigen::VectorXd x = solver.solve();

		// display the solution to screen
		std::cout<<"Regularized Solution:\n"<<x<<"\n";

	} catch (const std::exception& e) {

		// print any error messages to screen
		std::cerr<<"ERROR: "<<e.what()<<"\n";

		return 1;
	}
}
