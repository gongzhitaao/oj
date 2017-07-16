class Solution
{
 public:
  string simplifyPath(string path)
  {
    vector<string> stk;
    string name = "";
    int dot = 0;
    path += "/";
    for (char c : path) {
      switch (c) {
        case '/':
          if (0 == dot || dot > 2) {
            if (name.size()) stk.push_back(name);
          } else if (2 == dot) {
            if (stk.size() > 0) stk.pop_back();
          }
          dot = 0;
          name = "";
          break;
        case '.':
          ++dot;
          name += c;
          break;
        default:
          dot = 0;
          name += c;
      }
    }

    string ret;
    for (string& s : stk)
      ret += "/" + s;
    return ret.size() ? ret : "/";
  }
};
