/*!
  \file   119.cpp
  \author Zhitao Gong <me@gongzhitaao.org>
  \date   Wed Jun 12 15:47:26 2013

  \brief  Greedy Gift Givers
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

struct fortune
{
    int in_;
    int out_;
    int left_;

    fortune() : in_(0), out_(0), left_(0) {}
};

int main()
{
    int n, amount, m, give;
    string name, from, to;
    string index[10];
    int cnt = 0;
    while (cin >> n) {
        map<string, fortune> info;

        for (int i = 0; i < n; ++i) {
            cin >> index[i];
            info[name] = fortune();
        }

        for (int i = 0; i < n; ++i) {
            cin >> from >> amount >> m;

            fortune &ft = info[from];

            if (m) {
                ft.left_ = amount%m;
                give = amount/m;
                ft.out_ = give*m;
            } else ft.left_ += amount;

            for (int j = 0; j < m; ++j) {
                cin >> to;
                info[to].in_ += give;
            }
        }

        if (cnt++) cout << endl;

        for (int i = 0; i < n; ++i) {
            fortune &ft = info[index[i]];
            cout << index[i] << ' '
                 << ft.in_-ft.out_ << endl;
        }
    }

    return 0;
}
