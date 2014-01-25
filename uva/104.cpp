
// Arbitrage
// Time-stamp: <2012-08-06 22:10:24 gongzhitaao>

#include <iostream>
using namespace std;

const int MAX = 20;

int n;
float dist[MAX][MAX][MAX+1];
int path[MAX][MAX][MAX+1];
int final[MAX+1];

int main()
{
	while (cin >> n) {

		for (int s = 0; s < MAX +1; ++s) {
			for (int i = 0; i < MAX; ++i) {
				for (int j = 0; j < MAX; ++j) {
					dist[i][j][s] = 0.0;
					path[i][j][s] = 0;
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (j == i) dist[i][j][1] = 1.0;
				else cin >> dist[i][j][1];
			}
		}

		float d;
		for (int s = 2; s < MAX+1; ++s) {
			for (int k = 0; k < n; ++k) {
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						d = dist[i][k][s-1] * dist[k][j][1];
						if (d > dist[i][j][s]) {
							dist[i][j][s] = d;
							path[i][j][s] = k;
						}
					}
				}
			}
		}

		int ind = -1;
		int stp;
		for (int s = n; s >= 2; --s) {
			for (int i = 0; i < n; ++i) {
				if (dist[i][i][s] > 1.01) {
					ind = i;
					stp = s;
				}
			}
		}

		if (-1 == ind)
			cout << "no arbitrage sequence exists" << endl;
		else {
			for (int i = stp, p = ind; i >= 0; --i) {
				final[i] = p;
				p = path[ind][p][i];
			}
			final[0] = ind;
			for (int i = 0; i < stp; ++i)
				cout << final[i]+1 << ' ';
			cout << final[stp]+1 << endl;
		}
	}
	return 0;
}
