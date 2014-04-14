#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int main()
{
  int N, K, T;
  scanf("%d %d %d", &N, &K, &T);

  typedef map<int, vector<int> >::iterator iter;
  map<int, vector<int> > schedule;
  for (int i = 1, t; i <= N; ++i) {
    scanf("%d", &t);
    schedule[t].push_back(i);
  }

  int prosp[101];
  for (int i = 1; i <= N; ++i)
    scanf("%d", prosp + i);

  int stout[101];
  for (int i = 1; i <= N; ++i)
    scanf("%d", stout + i);

  int stat[102];
  memset(stat, 0, 102 * sizeof(int));

  for (int t = 1; t <= T; ++t) {
    int tmp = 0;
    iter it = schedule.find(t);
    int I = min(t, K);
    for (int i = 1; i <= I; ++i) {
      int p = 0;

      if (it != schedule.end()) {
        vector<int> &v = it->second;
        for (vector<int>::iterator j = v.begin(); j != v.end(); ++j)
          if (stout[*j] == i) p += prosp[*j];
      }

      p += max(max(stat[i - 1], stat[i]), stat[i + 1]);
      stat[i - 1] = tmp;
      tmp = p;
    }
    stat[I] = tmp;
  }

  int ans = stat[1];
  int I = min(K, T);
  for (int i = 2; i <= I; ++i)
    if (stat[i] > ans) ans = stat[i];

  printf("%d\n", ans);

  return 0;
}
