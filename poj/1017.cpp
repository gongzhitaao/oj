/*!
  \file   1017.cpp
  \author Zhitao Gong <zzg0009@auburn.edu>
  \date   Sat Aug 24 09:31:16 2013

  \brief  Packets
*/

#include <cstdio>
using namespace std;

int c[7];

void fill_1(int n)
{
    c[1] -= n;
    if (c[1] < 0) c[1] = 0;
}

void fill_2(int n)
{
    c[2] -= n;
    if (c[2] < 0) {
        fill_1(-c[2] * 4);
        c[2] = 0;
    }
}

int main()
{
    while (scanf("%d %d %d %d %d %d", c+1, c+2, c+3, c+4, c+5, c+6)) {

        if (0 == c[1] && 0 == c[2] && 0 == c[3] &&
            0 == c[4] && 0 == c[5] && 0 == c[6]) break;

        int s = 0;
        s += c[6];

        s += c[5];
        fill_1(11 * c[5]);

        s += c[4];
        fill_2(5 * c[4]);

        int n = c[3] / 4;
        int r = c[3] - 4 * n;
        s += n;
        if (r > 0) {
            ++s;
            switch (4-r) {
            case 1:
                fill_2(1);
                fill_1(5);
                break;
            case 2:
                fill_2(3);
                fill_1(6);
                break;
            case 3:
                fill_2(5);
                fill_1(7);
                break;
            default: break;
            }
        }

        n = c[2] / 9;
        r = c[2] - 9 * n;
        s += n;
        if (r > 0) {
            ++s;
            fill_1(4 * (9-r));
        }

        n = c[1] / 36;
        r = c[1] - 36 * n;
        s += n;
        if (r > 0) {
            ++s;
        }

        printf("%d\n", s);
    }
    return 0;
}
