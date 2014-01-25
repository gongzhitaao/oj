
// Maximun Sum
// Time-stamp: <2012-08-17 15:30:23 gongzhitaao>

#include <iostream>
using namespace std;

const int MAX = 100;
int N;
int presum[MAX][MAX] = {0};

int kadane(int u, int v)
{
    int cursum = 0, maxsum = -127001;
    for (int k = 0; k < N; ++k) {
	cursum += presum[v][k];
	if (u > 0 && k > 0) cursum += presum[u-1][k-1]-presum[u-1][k]-presum[v][k-1];
	else if (u > 0) cursum -= presum[u-1][k];
	else if (k > 0) cursum -= presum[v][k-1];

	if (cursum > maxsum) maxsum = cursum;
	if (cursum < 0) cursum = 0;
    }
    return maxsum;
}

int main()
{
    int arr[MAX][MAX] = {0};

    cin >> N;

    for (int i = 0; i < N; ++i) {
	for (int j = 0; j < N; ++j) {
	    cin >> arr[i][j];
	    presum[i][j] += arr[i][j];
	    if (j > 0 && i > 0) presum[i][j] +=
				    presum[i][j-1] + presum[i-1][j] - presum[i-1][j-1];
	    else if (j > 0) presum[i][j] += presum[i][j-1];
	    else if (i > 0) presum[i][j] += presum[i-1][j];
	}
    }

    int maxsum = -127001;
    for (int u = 0; u < N; ++u) {
	for (int v = u; v < N; ++v) {
	    int cursum = kadane(u, v);
	    if (cursum > maxsum) maxsum = cursum;
	}
    }

    cout << maxsum << endl;

    return 0;
}
