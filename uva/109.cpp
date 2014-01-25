
// SCUD Busters
// Time-stamp: <2012-09-26 22:52:24 gongzhitaao>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_KINGDOM_N = 20;

struct site {
    int x, y;
} pivot;

vector<vector<site> >sites;
vector<vector<site> >polies;
vector<bool> calced(MAX_KINGDOM_N, false);

bool cmp_miny(const site &a, const site &b)
{
    return a.y == b.y ? a.x > b.x : a.y > b.y;
}

bool cmp_ang(const site &a, const site &b)
{
    return atan2((float)(a.y - pivot.y), (float)(a.x - pivot.x))
        < atan2((float)(b.y - pivot.y), (float)(b.x - pivot.x));
}

bool turn_left(const site& a, const site& b, const site& c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) >= 0;
}

void graham_scan(const vector<site>& sites, vector<site>& poly)
{
    int n = sites.size();
    poly.push_back(sites[0]);
    poly.push_back(sites[1]);
    for (int i = 2, j = 0; i < n; ++i) {
        while ((j = poly.size()) >= 2
               && !turn_left(poly[j - 2], poly[j - 1], sites[i])) {
            poly.pop_back();
        }
        poly.push_back(sites[i]);
    }
}

float area(const vector<site>& poly)
{
    int n = poly.size();
    float tot = 0;
    for (int i = 1; i < n; ++i)
        tot += poly[i - 1].x * poly[i].y - poly[i].x * poly[i - 1].y;
    return tot * .5;
}

bool hit(const vector<site>& sites, int x, int y)
{
    int n = sites.size();
    site s = {x, y};
    for (int i = 1; i < n; ++i)
        if (!turn_left(sites[i - 1], sites[i], s))
            return false;
    return true;
}

int main()
{
    int n;
    int x, y;
    while (cin >> n && n != -1) {
        // get all sites for a kingdom
        vector<site> st;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            site s = {x, y};
            st.push_back(s);
        }
        // get the min-y site
        make_heap(st.begin(), st.end(), cmp_miny);
        pivot = st[0];
        // sort preparing for graham-scan
        sort(st.begin() + 1, st.end(), cmp_ang);
        st.push_back(pivot);

        vector<site> poly;
        graham_scan(st, poly);

        sites.push_back(poly);
    }

    float areas = 0;
    while (cin >> x >> y) {
        n = sites.size();
        for (int i = 0; i < n; ++i) {
            if (hit(sites[i], x, y)) {
                if (!calced[i]) {
                    areas += area(sites[i]);
                    calced[i] = true;
                }
                break;
            }
        }
    }

    cout.precision(2);
    cout << fixed << areas << endl;
    return 0;
}
