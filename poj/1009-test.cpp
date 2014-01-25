
// Test data generator
// Time-stamp: <2012-11-06 17:48:52 CST gongzhitaao>

#include <stdlib.h>
#include <time.h>

#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct rle {
    int val, len;

    rle(int v = 0, int l = 0) : val(v), len(l) {}
};

const int ROW = 20;
const int COL = 20;
int imgi[ROW][COL];
int imgo[ROW][COL];
vector<rle> rlei;
vector<rle> rleo;
int neighbor[8];

void to_rle(const int a[][ROW], vector<rle> &b)
{
    int l = 1;
    int r0, c0, r1, c1;
    for (int i = 1; i < ROW * COL; ++i) {
        r0 = (i - 1) / COL;
        c0 = (i - 1) % COL;
        r1 = i / COL;
        c1 = i % COL;
        if (a[r0][c0] == a[r1][c1]) ++l;
        else {
            b.push_back(rle(a[r0][c0], l));
            l = 1;
        }
    }
    b.push_back(rle(a[ROW-1][COL-1], l));
}

int find_neighbor(int idx)
{
    int cnt = 0;
    int r = idx / COL;
    int c = idx % COL;

    if (r > 0) {
        if (c > 0) neighbor[cnt++] = idx - COL - 1;
        neighbor[cnt++] = idx - COL;
        if (c < COL - 1) neighbor[cnt++] = idx - COL + 1;
    }

    if (c > 0) neighbor[cnt++] = idx - 1;
    // DONOT include yourself
    if (c < COL - 1) neighbor[cnt++] = idx + 1;

    if (r < ROW - 1) {
        if (c > 0) neighbor[cnt++] = idx + COL - 1;
        neighbor[cnt++] = idx + COL;
        if (c < COL - 1) neighbor[cnt++] = idx + COL + 1;
    }

    return cnt;
}

void edge(/* imgi, imgo */)
{
    int cnt, r0, c0, r1, c1, v;
    for (int i = 0; i < ROW * COL; ++i) {
        cnt = find_neighbor(i);
        r0 = i / COL;
        c0 = i % COL;
        for (int j = 0; j < cnt; ++j) {
            r1 = neighbor[j] / COL;
            c1 = neighbor[j] % COL;
            v = abs(imgi[r0][c0] - imgi[r1][c1]);
            if (v > imgo[r0][c0]) imgo[r0][c0] = v;
        }
    }
}

void print_rle(const char *fn, const vector<rle> &img)
{
    int n = img.size();
    ofstream of(fn, ios::trunc);
    of << COL << endl;
    for (int i = 0; i < n; ++i)
        of << img[i].val << ' ' << img[i].len << endl;
    of << 0 << ' ' << 0 << endl << 0 << endl;
    of.close();
}

void print_mat(const char *fn, const int a[][ROW])
{
    ofstream of(fn, ios::trunc);
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL - 1; ++j)
            of << a[i][j] << ' ';
        of << a[i][COL-1] << endl;
    }
}

int main()
{
    srand(time(NULL));

    int v = rand() % 100;
    int t = ROW + (rand() % ROW - (ROW >> 1));

    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j) {
            if (t-- > 0) imgi[i][j] = v;
            else {
                t = ROW + (rand() % ROW - (ROW >> 1));
                v = rand() % 100;
            }
            imgo[i][j] = 0;
        }

    to_rle(imgi, rlei);
    print_rle("1009.in", rlei);
    print_mat("1009-aux.in", imgi);

    edge();

    to_rle(imgo, rleo);
    print_rle("1009.out", rleo);
    print_mat("1009-aux.out", imgo);

    return 0;
}
