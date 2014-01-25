
// Stacking Boxed
// Time-stamp: <2012-08-02 11:03:23 gongzhitaao>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXK = 30;
const int MAXD = 10;

int k, n;

struct Box
{
	int ind;
	int dim[MAXD];
};

Box box[MAXK];

int boxcomp(const void *a, const void *b)
{
	Box ba = *(Box *)a;
	Box bb = *(Box *)b;
	for (int i = 0; i < n; ++i) {
		if (ba.dim[i] < bb.dim[i]) return -1;
		else if (ba.dim[i] > bb.dim[i]) return 1;
	}
	return 0;
}

bool equal(const Box &a, const Box &b)
{
	for (int i = 0; i < n; ++i)
		if (a.dim[i] != b.dim[i]) return false;
	return true;
}

bool smaller(const Box &a, const Box &b)
{
	for (int i = 0; i < n; ++i)
		if (a.dim[i] >= b.dim[i]) return false;
	return true;
}

void find_lis(const vector<Box> &a, vector<int> &b)
{
	vector<int> q(a.size(), 1);
	vector<int> p(a.size(), -1);
	int max;
	for (int i = 1; i < a.size(); ++i) {
		max = 0;
		for(int j = 0; j < i; ++j) {
			if (smaller(a[j], a[i]))
				if (q[j] > max) {
					max = q[j];
					p[i] = j;
				}
		}
		q[i] = max+1;
	}
	int v;
	max = 0;
	for (int i = 0; i < q.size(); ++i) {
		if (q[i] > max) {
			max = q[i];
			v = i;
		}
	}
	for ( ; v != -1; v = p[v]) b.push_back(v);

	int s = b.size();
	for (int i = 0; i < s/2; ++i) {
		v = b[i];
		b[i] = b[s-1-i];
		b[s-1-i] = v;
	}
}

int main()
{
	while (cin >> k >> n) {
		for (int i = 0; i < MAXK; ++i)
			for (int j = 0; j < MAXD; ++j)
				box[i].dim[j] = 0;

		for (int i = 0; i < k; ++i) {
			box[i].ind = i + 1;
			for (int j = 0; j < n; ++j)
				cin >> box[i].dim[j];

			sort(box[i].dim, box[i].dim+n);
		}

		qsort(box, k, sizeof(Box), boxcomp);

		vector<Box> vb(box, box+k);
		vector<int> lis;
		find_lis(vb, lis);

		cout << lis.size() << endl;
		for (int i = 0; i < lis.size() - 1; ++i)
			cout << vb[lis[i]].ind << ' ';
		cout << vb[lis.back()].ind << endl;
	}
}
