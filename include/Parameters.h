#ifndef PARAMETERS_H
#define PARAMETERS_H

class Parameters
{
    public:
        int maxIter;
        int verbose;
        double tol;
        double eta;     // ratio for stepsizes

        Parameters()
        {
            maxIter = 50;
            tol = 1e-08;
            verbose = 2;
            eta = 0.99995;
        }

        Parameters(int otherMaxIter, double otherTol, int otherVerbose)
        {
            maxIter = otherMaxIter;
            tol = otherTol;
            verbose = otherVerbose;
            eta = 0.99995;
        }

        void set_maxIter(int otherMaxIter) { maxIter = otherMaxIter; }
        void set_setTol(double otherTol)   { tol = otherTol;         }
        void set_verbose(int otherVerbose) { verbose = otherVerbose; }
};

#endif // PARAMETERS_H
