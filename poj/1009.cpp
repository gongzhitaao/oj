
// Edge Detection
// Time-stamp: <2012-11-06 17:46:38 CST gongzhitaao>

#include <cmath>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

struct rle {
    unsigned char val;
    int idx;

    rle(unsigned char v = 0, int i = 0) : val(v), idx(i) {}
};

int row, col;
vector<rle> imgi;
map<int, rle> imgo;
int neighbor[8], neighbor1[8];

inline unsigned char getv(int idx /* ,imgi */)
{
    int l = 0, r = imgi.size() - 1, m;

    if (idx >= imgi[r].idx) return imgi[r].val;

    while (l < r) {
        m = (l + r) >> 1;
        if (idx == imgi[m].idx) return imgi[m].val;
        else if (idx > imgi[m].idx) {
            if (idx < imgi[m+1].idx) return imgi[m].val;
            l = m + 1;
        } else r = m;
    }
    // impossible to reach here
    return 0;
}

inline int find_neighbor(int idx, int *neighbor)
{
    int cnt = 0;
    int r = idx / col;
    int c = idx % col;

    if (r > 0) {
        if (c > 0) neighbor[cnt++] = idx - col - 1;
        neighbor[cnt++] = idx - col;
        if (c < col - 1) neighbor[cnt++] = idx - col + 1;
    }

    if (c > 0) neighbor[cnt++] = idx - 1;
    // DONOT include yourself
    if (c < col - 1) neighbor[cnt++] = idx + 1;

    if (r < row - 1) {
        if (c > 0) neighbor[cnt++] = idx + col - 1;
        neighbor[cnt++] = idx + col;
        if (c < col - 1) neighbor[cnt++] = idx + col + 1;
    }

    return cnt;
}

inline void activate(int idx, unsigned char val)
{
    unsigned char v, t0, t1, t2;
    int cnt, cnt1;
    bool b = false;

    cnt = find_neighbor(idx, neighbor);
    t0 = 0;
    b = imgo.find(idx) == imgo.end();
    // Disturb and register all the undisturbed neighbors
    for (int j = 0; j < cnt; ++j) {
        v = getv(neighbor[j]);

        if (b) {
            t1 = abs(v - val);
            if (t1 > t0) t0 = t1;
        }

        if (imgo.find(neighbor[j]) == imgo.end()) {
            t1 = 0;
            cnt1 = find_neighbor(neighbor[j], neighbor1);
            for (int k = 0; k < cnt1; ++k) {
                t2 = abs(getv(neighbor1[k]) - v);
                if (t2 > t1) t1 = t2;
            }
            imgo[neighbor[j]] = rle(t1, neighbor[j]);
        }
    }
    // Register if disturbed the first time
    if (b) imgo[idx] = rle(t0, idx);
}

void transform(/* imgi, imgo */)
{
    int n = imgi.size(), idx;
    for (int i = 0; i < n; ++i) {
        activate(imgi[i].idx, imgi[i].val);
        idx = i < n - 1 ? imgi[i+1].idx : row * col - 1;
        if (idx / col != imgi[i].idx / col) {
            idx = imgi[i].idx + col - imgi[i].idx % col;
            activate(idx, getv(idx));
        }
    }
}

void print(/* imgo */)
{
    vector<rle> tmpimg;
    for (map<int, rle>::iterator it = imgo.begin();
         it != imgo.end(); ++it)
        tmpimg.push_back(it->second);

    cout << col << endl;
    int beg = 0, n = tmpimg.size();
    for (int i = 1; i < n; ++i) {
        if (tmpimg[i].val != tmpimg[i-1].val) {
            cout << (int)tmpimg[i-1].val << ' '
                 << tmpimg[i].idx - beg << endl;
            beg = tmpimg[i].idx;
        }
    }

    if (beg < row * col)
        cout << (int)tmpimg[n-1].val << ' '
             << row * col - beg << endl;
    cout << 0 << ' ' << 0 << endl;
}

int main()
{
    int i, l, v;
    while (cin >> col && col) {
        i = 0;

        while (cin >> v >> l) {

            if (!v && !l) {
                row = i / col;

                transform();
                print();

                // for (int i = 0; i < row; ++i) {
                //     for (int j = 0; j < col; ++j)
                //         cout << (int)getv(i * col + j) << ' ';
                //     cout << endl;
                // }

                imgi.clear();
                imgo.clear();
                break;
            }

            imgi.push_back(rle(v, i));
            i += l;
        }
    }
    cout << 0 << endl;

    return 0;
}
