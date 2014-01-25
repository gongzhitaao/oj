/*!
  \file   1019.cpp
  \author Zhitao Gong <zzg0009@auburn.edu>
  \date   Mon Aug 26 18:22:17 2013

  \brief  Number Sequence
*/

#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

inline long long root(long long a, long long b, long long c)
{
    float fa(a), fb(b), fc(c);
    long long r = floor((-fb+sqrt(fb*fb-4*fa*fc))/(2*fa));
    return a*r*r+b*r+c >= 0 ? r-1 : r;
}

const int N = 5;
int L[N] = {0, 10-1, 210-21, 3210-321, 43210-4321 };
int SL[N] = {0};

long long pos(long long p)
{
    char buf[10];
    long long n = p;
    for (int i = N-1; i >= 0; --i) {
        if (n > SL[i]) {
            n -= SL[i];
            long long k = root(i+1, 2*L[i]+i+1, -2*n);
            n -= k*L[i]+(i+1)*(1+k)*k/2;
            for (int j = N-1, p = 10000; j >= 0; --j, p/=10) {
                if (n > L[j]) {
                    n -= L[j];
                    long long x = n/(j+1);
                    long long r = n%(j+1);
                    if (0 == r) {
                        return (p+x-1)%10;
                    } else {
                        sprintf(buf, "%lld", p+x);
                        return buf[r-1]-'0';
                    }
                }
            }
        }
    }
}

int main()
{
    for (int i = 1, j = 9; i < N; ++i, j *= 10)
        SL[i] = SL[i-1] + j*L[i-1] + (j+1)*j*i/2;

    long long t;
    cin >> t;
    while (t-- > 0) {
        long long n;
        cin >> n;
        cout << pos(n) << endl;
    }
    return 0;
}
