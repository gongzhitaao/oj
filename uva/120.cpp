/*!
  \file   120.cpp
  \author Zhitao Gong <me@gongzhitaao.org>
  \date   Wed Jun 12 21:44:37 2013

  \brief  Stacks of Flapjacks
*/

#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    int stk[30];
    string s;
    while (getline(cin, s)) {
        stringstream ss;
        ss << s;
        int n;
        for (n = 0; ss >> stk[n]; ++n);

        cout << s << endl;

        for (int i = n-1; i > 0; --i) {

            int max_ind = 0;
            for (int j = 1; j <= i; ++j)
                if (stk[j] > stk[max_ind]) max_ind = j;

            if (max_ind == i) continue;

            for (int k = 0; k <= max_ind/2; ++k)
                swap(stk[k], stk[max_ind-k]);

            if (max_ind > 0) cout << n-max_ind << ' ';

            for (int k = 0; k <= i/2; ++k)
                swap(stk[k], stk[i-k]);

            cout << n-i << ' ';
        }
        cout << 0 << endl;
    }
    return 0;
}
