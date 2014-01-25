
// Skyline Problem
// Time-stamp: <2012-08-08 10:10:15 gongzhitaao>

#include <iostream>
using namespace std;

const int N = 10000;

int main()
{
	int l, h, r;
	int arr[N] = {0};
	int xmax = 0;
	while (cin >> l >> h >> r) {
		if (r > xmax) xmax = r;
		for (int j = l; j < r; ++j)
			if (h > arr[j]) arr[j] = h;
	}

	int curh = 0;
	int preh = 0;
	int first = true;
	for (int i = 0; i <= xmax; ++i) {
		if (arr[i] != curh) {
			if (!first) cout << ' ';
			else first = false;
			cout << i << ' ' << arr[i];
			curh = arr[i];
		}
	}
	if (curh != 0) cout << xmax << ' ' << 0;
	cout << endl;
	return 0;
}
