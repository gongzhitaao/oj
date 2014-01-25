
// The Block Problem
// Time-stamp: <2012-07-31 16:54:18 gongzhitaao>

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX = 25;

vector<int> blocks[MAX];
int index[MAX];

void move_onto(int a, int b)
{
  int ia = index[a];
  int ib = index[b];
  if (ia == ib) return;

  int t;
  while ((t = blocks[ia].back()) != a) {
    blocks[ia].pop_back();
    blocks[t].push_back(t);
    index[t] = t;
  }
  while ((t = blocks[ib].back()) != b) {
    blocks[ib].pop_back();
    blocks[t].push_back(t);
    index[t] = t;
  }

  blocks[ia].pop_back();
  blocks[ib].push_back(a);
  index[a] = ib;
}

void move_over(int a, int b)
{
  int ia = index[a];
  int ib = index[b];
  if (ia == ib) return;

  int t;
  while ((t = blocks[ia].back()) != a) {
    blocks[ia].pop_back();
    blocks[t].push_back(t);
    index[t] = t;
  }

  blocks[ia].pop_back();
  blocks[ib].push_back(a);
  index[a] = ib;
}

void pile_onto(int a, int b)
{
  int ia = index[a];
  int ib = index[b];
  if (ia == ib) return;

  int t;
  while ((t = blocks[ib].back()) != b) {
    blocks[ib].pop_back();
    blocks[t].push_back(t);
    index[t] = t;
  }

  vector<int> ts;
  while ((t = blocks[ia].back()) != a) {
    blocks[ia].pop_back();
    ts.push_back(t);
  }
  blocks[ia].pop_back();
  ts.push_back(a);
  while (!ts.empty()) {
    t = ts.back();
    ts.pop_back();
    blocks[ib].push_back(t);
    index[t] = ib;
  }
}

void pile_over(int a, int b)
{
  int ia = index[a];
  int ib = index[b];
  if (ia == ib) return;

  int t;
  vector<int> ts;
  while ((t = blocks[ia].back()) != a) {
    blocks[ia].pop_back();
    ts.push_back(t);
  }
  blocks[ia].pop_back();
  ts.push_back(a);
  while (!ts.empty()) {
    t = ts.back();
    ts.pop_back();
    blocks[ib].push_back(t);
    index[t] = ib;
  }
}

int main()
{

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    blocks[i].push_back(i);
    index[i] = i;
  }

  string cmd0, cmd1;
  int a, b;
  while (cin >> cmd0) {
    if (cmd0.compare("quit") == 0) break;

    cin >> a >> cmd1 >> b;
    if (a == b) continue;

    if (cmd0.compare("move") == 0) {
      if (cmd1.compare("onto") == 0) move_onto(a, b);
      else move_over(a, b);
    }

    if (cmd0.compare("pile") == 0) {
      if (cmd1.compare("onto") == 0) pile_onto(a, b);
      else pile_over(a, b);
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << i << ':';
    for (int j = 0; j < blocks[i].size(); ++j)
      cout << ' ' << blocks[i][j];
    cout << endl;
  }

  return 0;
}
