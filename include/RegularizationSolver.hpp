// solver class for Tikhonov regularization
// system condsidered: Ax = b

// implement solver for Tikhonov regularization

#pragma once

#include <Eigen/Dense>

class RegularizationSolver {

private:

	// forward operator; matrix A
	Eigen::MatrixXd A_;

	// RHS of algebraic system; data column vector
	Eigen::VectorXd b_;

	// regularization parameter
	double lambda_;

	// regularization matrix; defaulted to identity matrix
	Eigen::MatrixXd L_;

	// flag: was a custom value for L_ used or not?
	bool customL_;

public:

	// constructor; initialise data members
	RegularizationSolver(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, double lambda);

	// set a custom regularization matrix L
	void setRegularizationMatrix(const Eigen::MatrixXd& L);

	// solve the system and return components of x
	Eigen::VectorXd solve();
};