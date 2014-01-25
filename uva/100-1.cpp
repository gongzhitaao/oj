
// 3n+1 Problem
// Time-stamp: <2012-07-31 15:15:37 gongzhitaao>

#include <iostream>
#include <stack>
#include <map>
using namespace std;

const int MAX = 1000000;

int count[MAX+1];
typedef map<int, int> memo;
memo more_count;

int cyclen(int n) {

  stack<int> q;

  int cur;
  int cnt;

  if (n < MAX && count[n] != 0) return count[n];

  cur = n;
  while (cur >= MAX || 0 == count[cur]) {
    q.push(cur);
    if (cur % 2 == 0) cur >>= 1;
    else cur = cur*3 + 1;
  }
  cnt = count[cur];
  while (!q.empty()) {
    cur = q.top();
    q.pop();
    ++cnt;
    if (cur < MAX)
      count[cur] = cnt;
  }
  return count[n];
}

int main() {

  fill(count, count+MAX+1, 0);

  count[1] = 1;

  int i, j;
  int t;
  bool b;

  while (cin >> i >> j) {

    b = false;
    if (j < i) {
      t = i;
      i = j;
      j = t;
      b = true;
    }

    int max = 0;
    for (int ii = i; ii <= j; ++ii) {
      t = cyclen(ii);
      if (t > max) max = t;
    }

    if (b)
      cout << j << ' ' << i << ' ' << max << endl;
    else
      cout << i << ' ' << j << ' ' << max << endl;
  }

  return 0;
}
