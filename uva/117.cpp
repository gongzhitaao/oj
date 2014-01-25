/*!
  \file   117.cpp
  \author Zhitao Gong <me@gongzhitaao.org>
  \date   Tue Jun 11 15:53:32 2013

  \brief  The Postal Worker Rings Once
*/

#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <string>
using namespace std;

const int SIZE = 'z'+1;
int d[SIZE];
int w[SIZE][SIZE];
int deg[SIZE];
int cost;
map<char, string> adj;
string name;

struct comp
{
    bool operator()(const char a, const char b)
    {
        return d[a] > d[b];
    }
};

int main()
{

    for (int i = 'a'; i < SIZE; ++i) {
        deg[i] = 0;
        d[i] = numeric_limits<int>::max();
    }
    adj.clear();
    cost = 0;

    while (cin >> name) {
        if (0 == name.compare("deadend")) {

            char a = 0, b = 0;
            map<char, string>::iterator it;

            for (it = adj.begin(); it != adj.end(); ++it) {
                if (1 == deg[it->first]%2) {
                    a = it->first;
                    break;
                }
            }

            if (!a) cout << cost << endl;
            else {
                for (++it; it != adj.end(); ++it) {
                    if (1 == deg[it->first]%2) {
                        b = it->first;
                        break;
                    }
                }

                string adja = adj[a];
                for (size_t i = 0; i < adja.size(); ++i) {
                    char u = adja[i];
                    d[u] = w[a][u];
                }
                d[a] = 0;

                priority_queue<int, vector<int>, comp> pq;
                for (it = adj.begin(); it != adj.end(); ++it)
                    pq.push(it->first);

                while (!pq.empty()) {
                    char u = pq.top();
                    pq.pop();
                    string adju = adj[u];
                    for (size_t i = 0; i < adju.size(); ++i) {
                        char v = adju[i];
                        if (d[v] > d[u]+w[u][v]) d[v] = d[u]+w[u][v];
                    }
                }
                cout << cost+d[b] << endl;
            }

            // reset variables
            for (int i = 'a'; i < SIZE; ++i) {
                deg[i] = 0;
                d[i] = numeric_limits<int>::max();
            }
            adj.clear();
            cost = 0;

        } else {
            char a = name[0], b = *name.rbegin();
            w[a][b] = w[b][a] = name.length();
            cost += w[a][b];
            ++deg[a], ++deg[b];
            adj[a] += b;
            adj[b] += a;
        }
    }

    return 0;
}
