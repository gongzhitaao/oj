// Joseph
// Time-stamp: <2013-04-15 07:52:10 CDT gongzhitaao>

#include <iostream>
using namespace std;

int main()
{
    int k;
    int ans[] = {2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
    // int ans[] = {2,7,5,30,169,441,1872,46620,1740,93313,459901,1358657,2504881,13482720};

    while (cin >> k && k) {
        cout << ans[k-1] << endl;
        // for (k = 1; k < 14; ++k) {
        //     // if (1 == k) {
        //     //     cout << 2 << endl;
        //     //     continue;
        //     // }

        //     bool ok = false;
        //     int f = 0;
        //     while (!ok) {
        //         int n = 2 * k;
        //         for (int i = k+1; i <= n; ++i) {
        //             int idx[28];
        //             for (int j = 0; j < n; ++j) idx[j] = j;

        //             int kk = i + f, cur = 0, j;
        //             for (j = 0; j < k; ++j) {
        //                 cur = (cur+kk-1) % (n-j);
        //                 if (idx[cur] < k) break;
        //                 for (int m = cur; m < n-j-1; ++m) idx[m] = idx[m+1];
        //             }

        //             if (j == k) {
        //                 cout << kk << endl;
        //                 ok = true;
        //                 break;
        //             }
        //         }
        //         f += n;
        //     }
    }
    return 0;
}
