class Solution
{
 public:
  int largestRectangleArea(vector<int>& heights)
  {
    heights.push_back(0);

    const int n = heights.size();

    vector<int> stk;
    stk.reserve(n);
    stk.push_back(-1);

    int maxarea = 0;
    for (int i = 0; i < n; ++i) {
      for (; stk.size() > 1 && heights[i] < heights[stk.back()];
           stk.pop_back()) {
        int area = (i - 1 - stk[stk.size() - 2]) * heights[stk.back()];
        if (area > maxarea) maxarea = area;
      }
      stk.push_back(i);
    }

    return maxarea;
  }
};
