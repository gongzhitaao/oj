class Solution
{
 public:
  int findLongestChain(vector<vector<int>>& pairs)
  {
    if (pairs.empty()) return 0;

    auto cmp = [](const vector<int>& a, const vector<int>& b) {
      return a[0] < b[0];
    };
    sort(pairs.begin(), pairs.end(), cmp);

    const int n = pairs.size();
    vector<int> lens(n, 1);
    int maxlen = 1;

    for (int i = 1; i < pairs.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (pairs[j][1] < pairs[i][0] && lens[j] + 1 > lens[i])
          lens[i] = lens[j] + 1;
      }
      if (lens[i] > maxlen) maxlen = lens[i];
    }

    return maxlen;
  }
};
