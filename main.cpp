#include <iostream>
#include <algorithm>
#include "Matrix.h"
#include "RandomMatrix.h"


using namespace std;

int main() {
    RandomMatrix rm(10);
    rm.solve_gauss(cin, cout);


}
