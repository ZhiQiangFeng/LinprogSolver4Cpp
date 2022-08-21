#ifndef INCLUDE_LIBS_H
#define INCLUDE_LIBS_H

#include <iostream>
using namespace std;

#include <Eigen/Dense>
#include "Eigen/BenchUtilities/BenchTimer.h"

using namespace Eigen;

typedef MatrixXd mat;
typedef VectorXd vec;
typedef HouseholderQR<mat> Factorization;

#endif // INCLUDE_LIBS_H
