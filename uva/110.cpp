
// Meta-Loopless Sorts
// Time-stamp: <2012-09-30 23:33:53 gongzhitaao>

#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const string decl_s0 = "program sort(input,output);\nvar\n";
int depth;
string L = "";
map<int, string> memo;

string decl(int n)
{
    stringstream ss;
    for (int i = 0; i < n - 1; ++i)
        ss << char('a' + i) << ',';
    ss << char('a' + n - 1);
    string decl_s1;
    ss >> decl_s1;
    return decl_s0 + decl_s1 + " : integer;\nbegin\nreadln("
        + decl_s1 + ");";
}

void add(char c, int i)
{
    L = L.substr(0, i) + c + L.substr(i);
}

void del(int i)
{
    L = L.substr(0, i) + L.substr(i + 1);
}

ostream &prtL(ostream &o)
{
    int i;
    for (i = 0; i < L.size() - 1; ++i)
        o << L[i] << ',';
    o << L[i];
    return o;
}

// struct _ind { int n; };
// inline _ind ind(int n) { _ind i = {n}; return i; }
// stringstream & operator << (stringstream &o, const _ind &i)
// {
//     o << string(i.n << 1, ' ');
//     return o;
// }

string permutate(const string &s, int i)
{
    stringstream ss;
    if (i < s.size()) {
        for (int j = L.size(); j >= 0; --j) {
            add(s[i], j);
            if (j > 0 && j >= i)
                ss << ind(i) << "if " << L[j - 1] << " < " << L[j] << " then" << endl;
            ss << permutate(s, i + 1);
            if (j > 0) {
                ss << ind(i) << "else";
                if (j > 1)
                    ss << " if " << L[j - 2] << " < " << L[j] << " then" << endl;
                else ss << endl;
            }
            del(j);
        }
    } else {
        ss << ind(i) << "writeln(" << prtL << ")" << endl;
    }
    return ss.str();
}

string strn(int n)
{
    string s = "";
    for (int i = 0; i < n; ++i)
        s += 'a' + i;
    return s;
}

int main()
{
    int m, n;
    cin >> m;
    map<int, string>::iterator it;
    while (m-- > 0) {
        cin >> n;
        it = memo.find(n);
        if (it != memo.end())
            cout << it->second << endl;
        else {
            memo[n] = decl(n) + "\n" + permutate(strn(n), 0) + "end.";
            cout << memo[n] << endl;
        }
        if (m > 0) cout << endl;
    }
    return 0;
}
