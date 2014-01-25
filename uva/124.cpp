/*!
  \file   124.cpp
  \author Zhitao Gong <me@gongzhitaao.org>
  \date   Fri Jun 14 16:14:09 2013

  \brief  Following Orders
*/

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>
using namespace std;

char order[20];
int depth;

typedef set<char> var_type;
typedef map<char, set<char> > rule_type;

void dfs(var_type &vars, rule_type &rules, int d)
{
    if (d == depth) {
        for (int i = 0; i < d; ++i) cout << order[i];
        cout << endl;
        return;
    }

    var_type tmp(vars);

    for (rule_type::iterator i = rules.begin(); i != rules.end(); ++i) {
        var_type &r = i->second;
        for (var_type::iterator j = r.begin(); j != r.end(); ++j)
            tmp.erase(*j);
    }

    for (var_type::iterator i = tmp.begin(); i != tmp.end(); ++i) {
        char ch = *i;
        var_type bak(rules[ch]);
        rules.erase(ch);
        vars.erase(ch);
        order[d] = ch;
        dfs(vars, rules, d+1);
        rules[ch] = bak;
        vars.insert(ch);
    }
}

int main()
{
    string line;
    char ch, a, b;
    int cnt = 0;
    while (getline(cin, line)) {
        var_type vars;
        rule_type rules;

        stringstream ss(line);
        while (ss >> ch) vars.insert(ch);

        ss.str("");
        ss.clear();
        getline(cin, line);
        ss << line;
        while (ss >> a >> b)
            rules[a].insert(b);

        depth = vars.size();
        if (cnt++) cout << endl;
        dfs(vars, rules, 0);
    }
    return 0;
}
