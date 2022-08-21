#ifndef LINPROG_H
#define LINPROG_H

#include "Status.h"
#include "problemData.h"
#include "Parameters.h"
#include "include_libs.h"

class linprog
{
    public:

        linprog(const mat &A, const vec &b, const vec &c);

        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    public:

        problemData prob;
        Parameters  pars;
        Status      stat;
        Eigen::BenchTimer timer;

        int iter;
        double residual;
        double totalTime;

        double alphax, alphas;
        double mu;

        double sigma;       // centring paramter
        double bc;          // regulator

        vec Rp, Rd;

        vec  x,  y,  s;
        vec dx, dy, ds;

        void solve();

    private:
        void initialize();
        void initialPoint();
        void calResidual();
        bool checkTermination();
        void calSearchDriection();
        void getStepSize();
        void updateIterates();
        void printHeader();
        void printIter();
        void printFooter();
        void startTimer();
        void endTimer();
        void printOPT();
        void _getDirections(vec& Rm, Factorization& factor);

};

#endif // LINPROG_H
