/*!
  \file   127.cpp
  \author Zhitao Gong <me@gongzhitaao.org>
  \date   Mon Jun 17 09:01:23 2013

  \brief  "Accordian" Patience
*/

#include <iostream>
#include <stack>
#include <list>
#include <utility>
using namespace std;

typedef pair<char,char> card_type;
typedef stack<card_type> card_stack;
typedef list<card_stack> card_list;

card_list cards;

bool match(card_list::iterator &from, card_list::iterator &to)
{
    card_type a = (*from).top();
    card_type b = (*to).top();
    if (a.first == b.first || a.second == b.second) {
        (*from).pop();
        (*to).push(a);
        if ((*from).empty()) cards.erase(from);
        from = to;
        return true;
    }
    return false;
}

int main()
{
    char v, s;
    while (cin >> v && '#' != v) {
        cards.clear();

        cin >> s;
        card_stack stk;
        stk.push(make_pair(v,s));
        cards.push_back(stk);
        for (int i = 0; i < 51; ++i) {
            cin >> v >> s;
            card_stack stk;
            stk.push(make_pair(v,s));
            cards.push_back(stk);
        }

        for (card_list::iterator beg = cards.begin(), i = cards.begin(); i != cards.end(); ) {
            if (distance(beg, i) >= 3) {
                card_list::iterator j = i;
                advance(i, -3);
                if (!match(j, i)) {
                    advance(i, 2);
                    if (!match(j, i)) i = ++j;
                }
            } else if (distance(beg, i) >= 1) {
                card_list::iterator j = i;
                advance(i, -1);
                if (!match(j, i)) i = ++j;
            } else ++i;
        }

        int n = cards.size();
        if (n > 1) cout << n << " piles remaining:";
        else cout << n << " pile remaining:";
        for (card_list::iterator i = cards.begin(); i != cards.end(); ++i)
            cout << " " << (*i).size();
        cout << endl;
    }
    return 0;
}
