
// Maya Canlendar
// Time-stamp: <2012-11-02 20:20:52 gongzhitaao>

#include <iostream>
#include <map>
#include <string>
using namespace std;

const string haab_months[] = {
    "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen",
    "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu",
    "uayet"
};

const string tzolkin_days[] = {
    "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat",
    "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban",
    "eznab", "canac", "ahau",
};

int main()
{
    map<string, int> haab_months_idx;
    for (int i = 0; i < 19; ++i)
        haab_months_idx.insert(make_pair(haab_months[i], i));

    int n, id, y, a;
    float d;
    string m;
    cin >> n;
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        cin >> d >> m >> y;
        a = (int)d + haab_months_idx[m] * 20 + y * 365;
        y = a / 260;
        a %= 260;
        m = tzolkin_days[a % 20];
        id = a % 13 + 1;
        cout << id << ' ' << m << ' ' << y << endl;
    }
    return 0;
}
