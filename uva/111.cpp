
// Histroy Grading
// Time-stamp: <2012-10-01 22:15:47 gongzhitaao>

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 20;
int s[MAX+1][MAX+1];
int a[MAX], b[MAX];
int size;

int lcs()
{
    for (int i = 0; i <= size; ++i) s[i][0] = s[0][i] = 0;
    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= size; ++j) {
            if (a[i-1] == b[j-1]) s[i][j] = s[i-1][j-1] + 1;
            else s[i][j] = max(s[i-1][j], s[i][j-1]);
        }
    }
    return s[size][size];
}

int main()
{
    cin >> size;
    int p;
    for (int i = 0; i < size; ++i) {
        cin >> p;
        a[p-1] = i;
    }
    while (cin >> p) {
        b[p - 1] = 0;
        for (int i = 1; i < size; ++i) {
            cin >> p;
            b[p-1] = i;
        }
        cout << lcs() << endl;
    }
    return 0;
}
