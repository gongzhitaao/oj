
// Simulation Wizardry
// Time-stamp: <2012-10-11 21:22:21 gongzhitaao>

#include <iostream>
using namespace std;

struct param {
    int v, c, f;
    // f: -1 for wall, 0 for nothing, 1 for bumper
    param() : v(0), c(0), f(0) {}
};

const int MAX = 51;
param grid[MAX][MAX];

const int dir[4][2] = {
    {1, 0} /*right*/, {0, 1} /*up*/,
    {-1, 0} /*left*/, {0, -1} /*down*/
};


void turn_right(int &d)
{
    d = (d + 3) % 4;
}

int main()
{
    int m, n, c, p;
    cin >> m >> n >> c >> p;

    // setup wall
    for (int i = 1; i <= m; ++i) {
        grid[1][i].f = grid[n][i].f = -1;
        grid[1][i].c = grid[n][i].c = c;
    }
    for (int j = 1; j <= n; ++j) {
        grid[j][1].f = grid[j][m].f = -1;
        grid[j][1].c = grid[j][m].c = c;
    }

    int x, y;
    for (int i = 0; i < p; ++i) {
        cin >> x >> y;
        cin >> grid[y][x].v >> grid[y][x].c;
        grid[y][x].f = 1;
    }

    int d, l, pts, tot = 0;
    int nx, ny;
    while (cin >> x >> y >> d >> l) {
        pts = 0;
        for (int i = 0; i < l - 1; ++i) {
            // move
            nx = x + dir[d][0];
            ny = y + dir[d][1];

            if (-1 == grid[ny][nx].f) {
                // hit wall
                turn_right(d);
                i += grid[ny][nx].c;
            } else if (1 == grid[ny][nx].f) {
                // hit bumper
                turn_right(d);
                i += grid[ny][nx].c;
                pts += grid[ny][nx].v;
            } else {
                x = nx;
                y = ny;
            }
        }
        cout << pts << endl;
        tot += pts;
    }
    cout << tot << endl;

    return 0;
}
