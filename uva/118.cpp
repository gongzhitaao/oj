/*!
  \file   118.cpp
  \author Zhitao Gong <me@gongzhitaao.org>
  \date   Wed Jun 12 09:34:33 2013

  \brief  Mutant Flatworld Explorers
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int dir[4][2] = {
        {0, 1},                 // north
        {1, 0},                 // east
        {0,-1},                 // south
        {-1,0}                  // west
    };

    int X, Y;
    cin >> X >> Y;

    int x, y, d;
    char ch;
    string ins;

    bool board[51][51];
    for (int i = 0; i < 51; ++i)
        for (int j = 0; j < 51; ++j)
            board[i][j] = false;

    while (cin >> x >> y >> ch >> ins) {

        switch (ch) {
        case 'N': d = 0; break;
        case 'E': d = 1; break;
        case 'S': d = 2; break;
        case 'W': d = 3; break;
        default: break;
        }

        bool f = false;
        for (size_t i = 0; i < ins.size(); ++i) {
            switch (ins[i]) {
            case 'L': d -= 1; if (d < 0) d = 3; break;
            case 'R': d += 1; if (d > 3) d = 0; break;
            default:
                if (!((x+dir[d][0] > X || x+dir[d][0] < 0) ||
                      (y+dir[d][1] > Y || y+dir[d][1] < 0))) {
                    x += dir[d][0], y += dir[d][1];
                } else if (!board[x][y]) {
                    f = board[x][y] = true;
                }
            }
            if (f) break;
        }

        switch (d) {
        case 0: ch = 'N'; break;
        case 1: ch = 'E'; break;
        case 2: ch = 'S'; break;
        case 3: ch = 'W'; break;
        }
        cout << x << ' ' << y << ' ' << ch;
        if (f) cout << " LOST";
        cout << endl;
    }
    return 0;
}
