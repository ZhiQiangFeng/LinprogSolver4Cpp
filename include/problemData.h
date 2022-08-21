#ifndef PROBLEMDATA_H
#define PROBLEMDATA_H

#include "include_libs.h"
#include <cassert>

class problemData
{
private:

    vec optx;   // |
    vec opty;   // | Optimal solution
    vec opts;   // |

public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    mat Q;     // |
    mat A;     // | Problem
    vec b;     // | Data
    vec c;     // |

    long m;     // number of constraints
    long n;     // number of variables

    // Constructors
    problemData() {}

    /* LP */
    problemData(const mat &iA, const vec &ib, const vec &ic)
    {
        assert(iA.rows() > 0 && iA.cols() > 0);

        m = iA.rows();
        n = iA.cols();

        A = iA;
        b = ib;
        c = ic;

        Q = mat::Zero(n,n);
    }

    // Methods
    void setOptx(const vec x) { optx = x; }
    void setOpty(const vec y) { opty = y; }
    void setOpts(const vec s) { opts = s; }

    vec getOptx() const { return optx; }
    vec getOpty() const { return opty; }
    vec getOpts() const { return opts; }
};

#endif // PROBLEMDATA_H
