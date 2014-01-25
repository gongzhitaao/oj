
// Tree Summing
// Time-stamp: <2013-06-19 16:24:18 CDT gongzhitaao>

#include <set>
#include <iostream>
using namespace std;

set<int> allsum;

bool create_tree(int sum, int cnt)
{
    char ch;
    cin >> ch >> ch;
    if (')' == ch) {
        for (int i = 0; i < cnt; ++i) {
            cin >> ch;
            if (')' != ch) {
                cin.putback(ch);
                break;
            }
        }
        return false;
    } else {
        int n;
        if ('-' != ch) {
            cin.putback(ch);
            cin >> n;
        } else {
            cin >> n;
            n = -n;
        }

        bool l = create_tree(n+sum, cnt+1);
        bool r = create_tree(n+sum, cnt+1);
        if (!l && !r) allsum.insert(n+sum);
        return true;
    }
}

int main()
{
    char ch;
    int sum;
    while (cin >> ch) {
        if ('-' != ch) {
            cin.putback(ch);
            cin >> sum;
        } else {
            cin >> sum;
            sum = -sum;
        }
        allsum.clear();
        create_tree(0, 0);
        if (allsum.find(sum) == allsum.end())
            cout << "no" << endl;
        else cout << "yes" << endl;
    }
    return 0;
}
