/*!
  \file   121.cpp
  \author Zhitao Gong <me@gongzhitaao.org>
  \date   Thu Jun 13 11:03:58 2013

  \brief  Pipe Fitters
*/

#include <iostream>
#include <cmath>
using namespace std;

int skew(float a, float b)
{
    int h = floor(2*(a-1)/sqrt(3.)+1);
    int w = floor(b);

    if (b-w >= 0.5) return h*w;
    else return h*w-h/2;
}

int main()
{
    float a, b;
    while (cin >> a >> b) {

        int n0 = floor(a)*floor(b);
        int n1 = max(skew(a, b), skew(b, a));

        if (n0 >= n1) cout << n0 << " grid" << endl;
        else cout << n1 << " skew" << endl;
    }
    return 0;
}
