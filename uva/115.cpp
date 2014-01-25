
// Climbing Trees
// Time-stamp: <2012-10-16 21:34:38 gongzhitaao>

#include <cmath>
#include <iostream>
#include <iterator>
#include <deque>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

struct person
{
    string name;
    int level;
    int par;
    vector<int> children;

    person(const string &n = ""): name(n), level(-1), par(-1) {}
};

bool operator < (const person &a, const person &b)
{
    return a.name.compare(b.name) < 0;
}

const int MAX = 300;
person all[MAX];
set<person> tmp;
vector<pair<string, string> > rel;
int parent, childa, childb;

int bsearch(const string &n)
{
    int l = 0, r = tmp.size() - 1, m, c;
    while (l <= r) {
        m = (l + r) >> 1;
        c = n.compare(all[m].name);
        if (c < 0) r = m - 1;
        else if (c > 0) l = m + 1;
        else return m;
    }

    return -1;
}

void bfs(int i)
{
    all[i].level = 0;
    deque<int> children;
    copy(all[i].children.begin(), all[i].children.end(), back_inserter(children));
    int k;
    while (!children.empty()) {
        k = children.front();
        children.pop_front();
        all[k].level = all[all[k].par].level + 1;
        copy(all[k].children.begin(), all[k].children.end(), back_inserter(children));
    }
}

void get_level()
{
    int n = tmp.size();
    for (int i = 0, j, k; i < n; ++i) {
        if (-1 != all[i].level) continue;
        k = j = i;
        while ((j = all[j].par) != -1) k = j;
        bfs(k);
    }
}

void find_par()
{
    int n = rel.size();
    int a, b;
    for (int i = 0; i < n; ++i) {
        a = bsearch(rel[i].first);
        b = bsearch(rel[i].second);
        all[a].par = b;
        all[b].children.push_back(a);
    }
}

void lca(const string &a, const string &b)
{
    parent = -1;

    int ai = childa = bsearch(a);
    int bi = childb = bsearch(b);

    if (-1 == ai || -1 == bi) return;

    int al = all[ai].level;
    int bl = all[bi].level;

    while (al > bl) {
        ai = all[ai].par;
        al = all[ai].level;
    }
    while (bl > al) {
        bi = all[bi].par;
        bl = all[bi].level;
    }

    while (!(-1 == ai || -1 == bi || ai == bi)) {
        ai = all[ai].par;
        bi = all[bi].par;
    }

    if (ai == bi) parent = ai;
}

int main()
{
    string p, q;
    while (cin >> p >> q) {
        if (!p.compare("no.child")) break;
        tmp.insert(person(p));
        tmp.insert(person(q));
        rel.push_back(make_pair(p, q));
    }
    copy(tmp.begin(), tmp.end(), all);

    find_par();
    get_level();

    // int n = tmp.size();
    // cout << "-----------------------" << endl;
    // for (int i = 0; i < n; ++i) {
    //     cout << all[i].name << ' ' << all[all[i].par].name << endl;
    // }

    int level_diff, k;
    while (cin >> p >> q) {
        lca(p, q);
        if (-1 == parent) cout << "no relation" << endl;
        else if (parent == childa) {
            level_diff = all[childb].level - all[childa].level;
            if (1 == level_diff) {
                cout << "parent" << endl;
            } else {
                for (int i = 2; i < level_diff; ++i)
                    cout << "great ";
                cout << "grand parent" << endl;
            }
        }
        else if (parent == childb) {
            level_diff = all[childa].level - all[childb].level;
            if (1 == level_diff) {
                cout << "child" << endl;
            } else {
                for (int i = 2; i < level_diff; ++i)
                    cout << "great ";
                cout << "grand child" << endl;
            }
        } else {
            level_diff = abs(all[childa].level - all[childb].level);
            k = min(all[childa].level - all[parent].level - 1,
                    all[childb].level - all[parent].level - 1);
            if (!k && !level_diff) cout << "sibling" << endl;
            else {
                cout << k << " cousin";
                if (level_diff)
                    cout << " removed " << level_diff;
                cout << endl;
            }
        }
    }
    return 0;
}
