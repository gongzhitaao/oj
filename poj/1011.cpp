// Sticks
// Time-stamp: <2013-04-14 21:35:34 CDT gongzhitaao>

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int sticks[64],                 // initial sticks len
    n,                          // initial sticks count
    len,                        // final len
    num;                        // final sticks count
bool used[64];

bool dfs(int cur, int left, int cnt)
{
    if (0 == left) {
        if (cnt + 2 == num) return true;

        for (cur = 0; used[cur]; ++cur) ;

        used[cur] = true;
        if (dfs(cur+1, len-sticks[cur], cnt+1)) return true;
        used[cur] = false;

        return false;
    } else {
        for (int i = cur; i < n; ++i) {
            if (used[i] || left < sticks[i] ||
                (sticks[i] == sticks[i-1] && !used[i-1])) continue;

            used[i] = true;
            if (dfs(i, left-sticks[i], cnt)) return true;
            used[i] = false;
        }
        return false;
    }
}

int main()
{
    while (cin >> n && n) {
        int totlen = 0;
        for (int i = 0; i < n; ++i) {
            cin >> sticks[i];
            totlen += sticks[i];
        }

        sort(sticks, sticks+n, greater<int>());
        fill(used, used+n, false);

        num = n;
        bool ok = false;
        for (; totlen / num < sticks[0]; --num) ;
        for (; num > 1; --num) {
            if (0 == totlen % num) {
                len = totlen / num;
                used[0] = true;
                if (dfs(1, len-sticks[0], 0)) {
                    ok = true;
                    break;
                }
                used[0] = false;
            }
        }

        if (ok) cout << len << endl;
        else cout << totlen << endl;

    }
    return 0;
}
