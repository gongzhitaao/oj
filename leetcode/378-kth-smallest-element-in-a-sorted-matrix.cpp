class Solution
{
 public:
  int kthSmallest(vector<vector<int> >& matrix, int k)
  {
    int n = matrix.size(), m = matrix[0].size();
    struct cmp {
      bool operator()(pair<int, int>& a, pair<int, int>& b)
      { return a.first > b.first; }
    };
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;
    vector<int> idx(n, 0);
    for (int i = 0; i < n; ++i)
      q.push(make_pair(matrix[i][0], i));
    for (int i = 1; i < k; ++i) {
      auto e = q.top(); q.pop();
      if (idx[e.second] < m-1)
        q.push(make_pair(matrix[e.second][++idx[e.second]],
                         e.second));
    }
    return q.top().first;
  }
};
