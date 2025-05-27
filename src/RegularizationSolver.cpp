
// implements the Regularization solver

#include "RegularizationSolver.hpp"

// constructor to initialise: A, b, regularization parameter and sets the Regularization Matrix to the identity matrix by default
RegularizationSolver::RegularizationSolver(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, double lambda)

	: A_(A), b_(b), lambda_(lambda), customL_(false) {

		// regularization matrix: identity matrix
		L_ = Eigen::MatrixXd::Identity(A.cols(), A.cols());
}

// set a custom regularization matrix L
void RegularizationSolver::setRegularizationMatrix(const Eigen::MatrixXd& L) {

	// columns of regularization matrix must match those of the forward model/system matrix
	if (L.cols() != A_.cols()) {

		// no equality so throw an exception
		throw std::invalid_argument("Regularization Matrix L must match Matrix A's Column Size"); 
	}

	// set custom matrix
	L_ = L;

	// update flag
	customL_ = true;
}

// solves (At * A + lambda^2 * Lt * L) * x = At * b; this will return the regularized solution; in linear algebra these are the Normal Equations
Eigen::VectorXd RegularizationSolver::solve() {

	// compute At * A
	const Eigen::MatrixXd AtA = A_.transpose() * A_;

	// compute Lt * L
	const Eigen::MatrixXd LtL = L_.transpose() * L_;

	// compute At * b
	const Eigen::VectorXd Atb = A_.transpose() * b_;

	// Tikhonov system matrix
	const Eigen::MatrixXd regMatrix = AtA + lambda_ * lambda_ * LtL;

	// solve using LDLT decomposition; matrix factorization technique used for solving linear equations
	// symmetric (or Hermitian) and positive definite matrices
	return regMatrix.ldlt().solve(Atb);
}