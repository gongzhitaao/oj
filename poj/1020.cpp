/*!
  \file   1020.cpp
  \author Zhitao Gong <zzg0009@auburn.edu>
  \date   Wed Aug 28 21:40:39 2013

  \brief  Anniversary Cake
*/

#include <iostream>
#include <cstring>
using namespace std;

int p[11], c[41], sz;

bool dfs(int n)
{
    if (0 == n) return true;

    int r = 1;
    for (int i = 2; i <= sz; ++i)
        if (c[i] < c[r]) r = i;

    for (int s = 1; s <= 10 && c[r] == c[r+s-1] && r+s-1 <= sz; ++s) {
        if (0 == p[s]) continue;

        if (c[r+s-1] + s > sz ||
            r + s - 1 > sz) return false;

        --p[s];
        for (int i = r; i <= r+s-1; ++i) c[i] += s;
        if (dfs(n-1)) return true;

        ++p[s];
        for (int i = r; i <= r+s-1; ++i) c[i] -= s;
    }

    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0) {

        memset(p, 0, sizeof p);
        memset(c, 0, sizeof c);

        int n, m;
        cin >> sz >> n;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> m;
            sum += m * m;
            ++p[m];
        }
        if (sz * sz == sum && dfs(n)) cout << "KHOOOOB!" << endl;
        else cout << "HUTUTU!" << endl;
    }
    return 0;
}
