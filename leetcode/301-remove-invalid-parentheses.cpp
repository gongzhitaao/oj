#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

class Solution
{
 public:
  vector<string> removeInvalidParentheses(string s)
  {
    queue<string> q0, q1;
    unordered_set<string> visited;

    for (q0.push(s); q0.size();) {
      string s = q0.front();

      if (isvalid(s)) break;
      q0.pop();

      for (int i = 0; i < s.size(); ++i) {
        if ('(' == s[i] || ')' == s[i]) {
          string child = s.substr(0, i) + s.substr(i + 1);
          if (visited.find(child) == visited.end()) {
            q1.push(child);
            visited.insert(child);
          }
        }
      }

      if (q0.empty()) swap(q0, q1);
    }

    vector<string> ret;
    for (; q0.size(); q0.pop()) {
      string s = q0.front();
      if (isvalid(s)) ret.push_back(s);
    }

    return ret;
  }

  inline bool isvalid(const string& s)
  {
    int cnt = 0;
    for (char c : s) {
      if ('(' == c)
        ++cnt;
      else if (')' == c)
        --cnt;
      if (cnt < 0) return false;
    }
    return 0 == cnt;
  }
};

// Just do BFS or DFS in a naive way, no way to lower the time complexity.
