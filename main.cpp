
#include <memory>
#include <fstream>
#include "linprog.h"

using linprogPtr = std::unique_ptr<linprog>;

int main(int argc, char *argv[])
{
    int mm, nn;
    const char *file = argv[1];
    //const char *file = "data1.txt";
    ifstream fin(file, std::fstream::in);
    cout << fin.is_open() << endl;
    fin >> mm >> nn;
    double tmp_A, tmp_b, tmp_c;

    mat A = mat::Ones(mm, nn);
    vec b = vec::Ones(mm);
    vec c = vec::Ones(nn);

    for (int i = 0; i < nn; i++){
        fin >> tmp_c;
        c(i) = tmp_c;
    }

    for (int i = 0; i < mm; i++){
        for (int j = 0; j < nn; j++){
            fin >> tmp_A;
            A(i, j) = tmp_A;
        }
        fin >> tmp_b;
        b(i) = tmp_b;
    }

    fin.close();
    fin.clear();

    cout<<"\nLP problem:"<<endl;
    linprogPtr lp_test = std::make_unique<linprog>(A, b, c);
    lp_test->solve();

    return 0;
}
