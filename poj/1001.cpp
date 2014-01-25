
// Exponentiation
// Time-stamp: <2012-10-30 17:26:31 gongzhitaao>

#ifdef DEBUG
#include <stdlib.h>
#include <time.h>
#endif

#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string mult(const string &a, const string &b)
{
    string op1, op2;
    if (a.size() < b.size()) {
        op1 = b;
        op2 = a;
    } else {
        op1 = a;
        op2 = b;
    }

    int s1 = op1.size();
    for (int i = 0; i < s1; ++i) op1[i] -= '0';
    int s2 = op2.size();
    for (int i = 0; i < s2; ++i) op2[i] -= '0';

    int sr = s1 + s2;
    string r(sr, char(0));

    int t, c, k;
    for (int i = s2 - 1; i >= 0; --i) {
        c = 0;
        for (int j = s1 - 1; j >= 0; --j) {
            k = (s1 - 1 - j) + (s2 - 1 - i);
            t = op2[i] * op1[j] + c + r[k];
            r[k] = t % 10;
            c = t / 10;
        }
        if (c) r[k+1] = c;
    }

    sr = r.size();
    if (!r[sr-1]) r.erase(r.end()-1);
    for (int i = 0; i < sr; ++i) r[i] += '0';
    reverse(r.begin(), r.end());

    return r;
}

inline bool nostop(int d[], int i)
{
    switch (i) {
    case 0: return d[0] || d[1] || d[2] || d[3] || d[4];
    case 1: return d[1] || d[2] || d[3] || d[4];
    case 2: return d[2] || d[3] || d[4];
    case 3: return d[3] || d[4];
    case 4: return d[4];
    default: return true;
    }
}

int main()
{
    stringstream ss;

#ifdef DEBUG
    // debug mult
    srand(time(NULL));
    int i1, i2, o1, o2;
    string v1, v2;
    for (int i = 0; i < 1000; ++i) {
        i1 = rand() % 1000;
        i2 = rand() % 1000;
        ss << i1 << ' ' << i2;
        ss >> v1 >> v2;
        ss.clear();
        o1 = i1 * i2;
        ss << mult(v1, v2);
        ss >> o2;
        ss.clear();
        if (o1 != o2) cout << i << endl;
    }
#endif

    string R, r;
    int n;

    float a;
    int c, d[5], e;
    string tmp[5];
    while (cin >> a >> n) {
        ss.clear();

        // preparing
        ss << a;
        ss >> R;
        ss.clear();
        for (c = 0; c < R.size() && R[c] != '.'; ++c) /* empty */;
        if (c < R.size()) {
            c = R.size() - c - 1;
            for (int i = 0; i < c; ++i) a *= 10;
            ss << a;
            ss >> R;
        } else c = -1;

        // R contians integer, n power, c position of decimal point
        d[0] = d[1] = d[2] = d[3] = d[4] = 0;
        for (int i = 0, j = n; i < 5 && j > 0; ++i) {
            d[i] = j & 1;
            j >>= 1;
        }

        tmp[0] = R;
        for (int i = 1; i < 5 && nostop(d, i); ++i)
            tmp[i] = mult(tmp[i-1], tmp[i-1]);

        r = "1";
        for (int i = 0; i < 5; ++i)
            if (d[i]) r = mult(tmp[i], r);

        if (c >= 0) {
            e = c * n;
            if (e > r.size()) {
                while (e > r.size()) {
                    r = "0" + r;
                }
                r = "." + r;
            }
            else r.insert(r.size() - c * n, ".");
        }

        cout << r << endl;
    }
    return 0;
}
