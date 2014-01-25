#include <cstdio>
#include <algorithm>
#include <limits>
#include <utility>
using namespace std;

typedef pair<int, int> device;

int t, n, m[100], b0, b1;
device d[100][100];

bool comp(const device &a, const device &b)
{
	return a.first < b.first;
}

int pos(int i, int k)
{
	int b = 0, mid, e = m[i]-1;
	while (b < e) {
		mid = (b + e) / 2;
		if (d[i][mid].first < k) b = mid + 1;
		else e = mid;
	}
	return b;
}

float bp(int b)
{
	int s = 0;
	for (int i = 0; i < n; ++i) {
		int j0 = pos(i, b);
		int p = d[i][j0].second;
		for (int j = j0+1; j < m[i]; ++j)
			if (d[i][j].second < p) p = d[i][j].second;
		s += p;
	}
	return ((float)b) / s;
}

int main()
{
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d", &n);
		b0 = numeric_limits<int>::max();
		b1 = numeric_limits<int>::max();
		for (int i = 0; i < n; ++i) {
			scanf("%d", m+i);
			for (int j = 0; j < m[i]; ++j)
				scanf("%d %d", &d[i][j].first, &d[i][j].second);
			sort(d[i], d[i]+m[i], comp);
			if (d[i][0].first < b0) b0 = d[i][0].first;
			if (d[i][m[i]-1].first < b1) b1 = d[i][m[i]-1].first;
		}
		float s = numeric_limits<float>::min();
		for (int i = 0; i < n; ++i) {
			for (int j = pos(i, b0); d[i][j].first <= b1 && j < m[i]; ++j) {
				float t = bp(d[i][j].first);
				if (t > s) s = t;
			}
		}
		printf("%.3f\n", s);
	}
	return 0;
}