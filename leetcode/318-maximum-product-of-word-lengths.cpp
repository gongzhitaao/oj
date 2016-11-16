class Solution
{
 public:
  int maxProduct(vector<string>& words)
  {
    vector<int> sig;
    for (string& w : words) {
      int n = 0;
      for (char c : w) n |= 1 << (c-'a');
      sig.push_back(n);
    }

    int ret = 0;
    int n = words.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        if (!(sig[i] & sig[j])) {
          int tmp = words[i].size() * words[j].size();
          if (tmp > ret) ret = tmp;
        }
      }
    }
    return ret;
  }
};
