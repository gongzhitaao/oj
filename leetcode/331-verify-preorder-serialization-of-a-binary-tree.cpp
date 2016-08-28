class Solution
{
 public:
  bool isValidSerialization(string preorder)
  {
    vector<int> cnt;
    bool null = false, finish = false;
    for (char c : preorder + ',') {
      if (',' == c) {
        if (!null) cnt.push_back(0);
        null = false;
      } else {
        if (finish) return false;
        if ('#' == c) {
          null = true;
          while (!cnt.empty() && 2 == ++cnt.back())
            cnt.pop_back();
          finish = cnt.empty();
        }
      }
    }
    return cnt.empty();
  }
};
