/*!
  \file   123.cpp
  \author Zhitao Gong <me@gongzhitaao.org>
  \date   Thu Jun 13 19:45:58 2013

  \brief  Searching Quickly
*/

#include <stdio.h>

#include <set>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    typedef vector<pair<int, int> > ind_type;
    typedef map<string, ind_type> kw_type;

    kw_type  keywords;
    set<string> ignores;
    vector<string> titles[200];

    string word;
    while (getline(cin, word) && 0 != word.compare("::"))
        ignores.insert(word);

    string line;
    for (int i = 0; getline(cin, line); ++i) {

        for (size_t j = 0; j < line.size(); ++j)
            line[j] = tolower(line[j]);

        stringstream ss;
        ss << line;

        for (int j = 0; ss >> word; ++j) {
            titles[i].push_back(word);
            if (ignores.find(word) == ignores.end())
                keywords[word].push_back(make_pair(i, j));
        }
    }

    for (kw_type::iterator it = keywords.begin(); it != keywords.end(); ++it) {
        ind_type &v = it->second;
        for (size_t i = 0; i < v.size(); ++i) {
            int r = v[i].first, c = v[i].second;

            vector<string> &t = titles[r];
            string &s = t[c];

            for (size_t j = 0; j < s.size(); ++j)
                s[j] = toupper(s[j]);

            cout << t[0];
            for (size_t j = 1; j < t.size(); ++j)
                cout << ' ' << t[j];
            cout << endl;

            for (size_t j = 0; j < s.size(); ++j)
                s[j] = tolower(s[j]);
        }
    }

    return 0;
}
