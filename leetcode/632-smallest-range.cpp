class Solution
{
 public:
  vector<int> smallestRange(vector<vector<int>>& nums)
  {
    const int n = nums.size();
    int a = 0, b = numeric_limits<int>::max();

    struct cmp {
      bool operator()(const pair<int, int>& a, const pair<int, int>& b)
      {
        return a.first > b.first;
      }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;

    int end = numeric_limits<int>::min();
    for (int i = 0; i < n; ++i) {
      q.push({nums[i][0], i});
      if (nums[i][0] > end) end = nums[i][0];
    }

    vector<int> ind(n, 0);
    for (bool found = false; !found;) {
      pair<int, int> elm = q.top(); q.pop();
      int start = elm.first;
      if (end - start < b - a) a = start, b = end;

      int i = elm.second;
      if (++ind[i] >= nums[i].size()) {
        found = true;
        break;
      }

      q.push({nums[i][ind[i]], i});
      if (nums[i][ind[i]] > end) end = nums[i][ind[i]];
    }

    return {a, b};
  }
};
