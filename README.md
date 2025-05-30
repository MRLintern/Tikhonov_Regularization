## Tikhonov Regularization

### Introduction
* ___Tikhonov Regularization___ is a method used to solve __Ill-Posed Inverse Problems__.
* Essentially, it helps __stabilize__ the solution when the original problem is unstable, noisy, or has no unique solution.

### The Problem: Ill-posed Linear Systems
* Consider the following __Linear System__: __Ax = b__, where we want to find the components of the vector __x__, given some observations/data __b__.
* If:
    * __A__ is __Ill-Conditioned__ (has near-zero singular values),
    * or the system is __Underdetermined__ (more unknowns than equations),
    * or the observations/data __b__ are noisy,
* then, solving __x__ directly gives wild, unstable, or meaningless results.

### The Solution: Add Regularization
* Tikhonov proposes solving: __x_λ ​= argxmin​(∥Ax−b∥^2 + λ^2∥Lx∥^2)__.
* Where:
    * __∥Ax−b∥^2__ is the __Data Fidelity__ term (fit the data).
    * __λ^2∥Lx∥^2__ is the regularization term (penalizes “bad” solutions).
    * __λ__ is the __Regularization Parameter__ (controls tradeoff).
    * __L__ is the __Regularization Matrix__ (commonly the identity matrix).

### Requirements
* __Compiler__: `g++ 13.1.0`.
* __OS__: Developed on `Ubuntu 20.04`.
* `CMake`.
* `Eigen Template Library`.

### Getting and Running the Software
* `$ git clone git@github.com:MRLintern/Tikhonov_Regularization.git`
* `$ cd Tikhonov_Regularization`
* `$ mkdir build -p && cd build`
* `$ cmake ..`
* `$ cmake --build .`
* Move the input data files, `A.txt` and `b.txt` to the `build` directory.
* `$ ./main`
