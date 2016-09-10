class Solution {
 public:
  int maxEnvelopes(vector<pair<int, int> >& envelopes) {
    if (envelopes.empty()) return 0;
    typedef pair<int, int> env_t;
    sort(envelopes.begin(), envelopes.end(),
         [&] (const env_t& a, const env_t& b) {
           return a.first == b.first ?
               a.second > b.second : a.first < b.first;
         });
    vector<int> lis;
    for (env_t& e : envelopes) {
      auto i = lower_bound(lis.begin(), lis.end(), e.second);
      if (i == lis.end()) lis.push_back(e.second);
      else if (e.second < *i) *i = e.second;
    }
    return lis.size();
  }
};
