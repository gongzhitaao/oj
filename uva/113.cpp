
// Power of Cryptography
// Time-stamp: <2012-10-04 18:55:09 gongzhitaao>

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double n, p, r;
    while (cin >> n >> p) {
        r = pow(p, 1 / n); // r = exp(log(p) / n);
        cout << (int)((floor(r) + .5 < r) ? ceil(r) : floor(r)) << endl;
    }
    return 0;
}
