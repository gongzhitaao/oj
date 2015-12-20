class Solution {
public:
  bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;

    string m(128, -1);
    vector<bool> used(128, false);

    for (int i = 0; i < s.size(); ++i) {
      char a = s[i], b = t[i];
      if (m[a] < 0) {
        if (used[b]) return false;
        m[a] = b;
        used[b] = true;
      } else if (m[a] != b) return false;
    }

    return true;
  }
};
