class Solution {
 public:
  int maxEnvelopes(vector<pair<int, int> >& envelopes) {
    if (envelopes.empty()) return 0;
    typedef pair<int, int> env_t;
    sort(envelopes.begin(), envelopes.end())
    int n = envelopes.size();
    vector<int> lis(n, 1);
    for (int i = 1; i < n; ++i) {
      env_t& e = envelopes[i];
      for (int j = 0; j < i; ++j) {
        env_t& t = envelopes[j];
        if (e.first > t.first && e.second > t.second)
          lis[i] = max(lis[i], lis[j] + 1);
      }
    }
    return *max_element(lis.begin(), lis.end());
  }
};
