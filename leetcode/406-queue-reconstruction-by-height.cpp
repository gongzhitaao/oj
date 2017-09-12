class Solution
{
 public:
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people)
  {
    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
      return a.first > b.first || a.first == b.first && a.second < b.second;
    };
    sort(people.begin(), people.end(), cmp);
    vector<pair<int, int>> ret;
    for (auto& p : people)
      ret.insert(ret.begin() + p.second, p);
    return ret;
  };
};
