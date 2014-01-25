/*!
  \file   1022.cpp
  \author Zhitao Gong <zzg0009@auburn.edu>
  \date   Sat Aug 31 21:38:28 2013

  \brief  Packing Unit 4D Cubes
*/

#include <cstring>
#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

int t, n, v;
struct cube { int a[4][2]; };
map<int, cube> prod;
map<int, bool> vis;
int bound[4][2];

int dfs(int b, int x[4])
{
    if (vis[b]) return 0;

    vis[b] = true;

    int k = 1;
    for (int i = 0; i < 4; ++i) {
        if (x[i] > bound[i][1]) bound[i][1] = x[i];
        if (x[i] < bound[i][0]) bound[i][0] = x[i];
        if (prod[b].a[i][0] > 0) {
            --x[i];
            k += dfs(prod[b].a[i][0], x);
            ++x[i];
        }
        if (prod[b].a[i][1] > 0) {
            ++x[i];
            k += dfs(prod[b].a[i][1], x);;
            --x[i];
        }
    }
    return k;
}

int main()
{
    cin >> t;
    while (t-- > 0) {
        cin >> n;

        prod.clear();
        vis.clear();
        int x[4] = {0};

        for (int i = 0; i < 4; ++i)
            bound[i][0] = bound[i][1] = 0;

        for (int i = 0, id; i < n; ++i) {
            cin >> id;
            vis[id] = false;

            cube u;
            for (int j = 0; j < 4; ++j)
                cin >> u.a[j][0] >> u.a[j][1];
            prod[id] = u;
        }

        bool f = false;
        for (int k = 0; k < 2; ++k) {
            for (int j = 0; j < 4; ++j) {
                for (map<int, cube>::iterator i = prod.begin(); i != prod.end(); ++i) {
                    int t = (i->second).a[j][k];
                    if (t > 0 && prod[t].a[j][1-k] != i->first) f = true;
                    if (f) goto end;
                }
            }
        }

        if (n != dfs(prod.begin()->first, x)) f = true;
        else {
            v = 1;
            for (int i = 0; i < 4; ++i) v *= bound[i][1]-bound[i][0]+1;
        }

    end:
        if (f) cout << "Inconsistent" << endl;
        else cout << v << endl;
    }
    return 0;
}
