
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

    mat A = mat::Ones(mm, nn);
    vec b = vec::Ones(mm);
    vec c = vec::Ones(nn);

    for (int i = 0; i < nn; i++)
        fin >> c(i);

    for (int i = 0; i < mm; i++){
        for (int j = 0; j < nn; j++){
            fin >> A(i, j);
        }
        fin >> b(i);
    }

    fin.close();
    fin.clear();

    cout<<"\nLP problem:"<<endl;
    linprogPtr lp_test = std::make_unique<linprog>(A, b, c);
    lp_test->solve();

    return 0;
}
