
// The Cat in the Hat
// Time-stamp: <2012-08-16 17:52:44 gongzhitaao>

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int h, n;
	while (cin >> h >> n) {
		if (0 == h || 0 == n) break;

		if (1 == n) {
			cout << log(h)/log(2) << ' ' << (h<<1)-n << endl;
			continue;
		}

		int u, v, m1, m2;
		int t1, t2;
		int exp = 0;
		while (true) {
			++exp;

			u = 1, v = (int)pow(n, 1.0/exp) + 1;
			while (u < v) {
				m1 = (u+v) >> 1;
				t1 = pow(m1, exp);
				if (t1 > n) v = m1;
				else if (t1 < n) u = m1 + 1;
				else break;
			}

			if (u == v) {
				m1 = u;
				t1 = pow(m1, exp);
			}
			if (t1 != n) continue;

			u = 1, v = (int)pow(h, 1.0/exp) + 1;
			while (u < v) {
				m2 = (u+v) >> 1;
				t2 = pow(m2, exp);
				if (t2 > h) v = m2;
				else if (t2 < h) u = m2 + 1;
				else break;
			}

			if (u == v) {
				m2 = u;
				t2 = pow(m2, exp);
			}
			if (t2 != h) continue;

			if (m1 + 1 == m2) break;
		}

		cout << (n-1)/(m1-1) << ' ' << h*m2-m1*n << endl;
	}
	return 0;
}
