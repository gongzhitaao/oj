class Solution
{
 public:
  vector<int> topKFrequent(vector<int>& nums, int k)
  {
    unordered_map<int, int> tmp;
    for (int n : nums) ++tmp[n];
    vector<pair<int, int>> cnt;
    for (auto& kv : tmp) cnt.push_back({kv.first, kv.second});
    auto comp = [](pair<int, int>& a, pair<int, int>& b) {
      return a.second > b.second;
    };
    nth_element(cnt.begin(), cnt.begin() + k - 1, cnt.end(), comp);
    vector<int> ret;
    int sep = cnt[k - 1].second;
    cout << sep << endl;
    for (int i = 0; i < cnt.size() && ret.size() < k; ++i)
      if (cnt[i].second >= sep) ret.push_back(cnt[i].first);
    return ret;
  }
};
