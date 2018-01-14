class Solution
{
 public:
  vector<string> findStrobogrammatic(int n)
  {
    vector<string> d1{"0", "1", "8"};
    vector<string> d2{"11", "69", "88", "96"};
    vector<string> dd{"00", "11", "69", "88", "96"};

    if (n <= 0) return {};
    if (1 == n) return d1;
    if (2 == n) return d2;

    vector<string> ret = (n & 1) ? d1 : vector<string>{""};

    for (int i = 0; i < n / 2 - 1; ++i) {
      vector<string> tmp;
      for (string& s : ret)
        for (string& d : dd)
          tmp.push_back(d[0] + s + d[1]);
      ret = tmp;
    }

    vector<string> tmp;
    for (string& s : ret)
      for (string& d : d2)
        tmp.push_back(d[0] + s + d[1]);
    return tmp;
  }
};
