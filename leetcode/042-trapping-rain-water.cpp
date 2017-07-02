class Solution
{
 public:
  int trap(vector<int>& height)
  {
    if (height.size() < 3) return 0;

    vector<int> cnt(height.size(), 0);
    vector<int> area(height.size(), 0);
    vector<int> highest(height.size(), 0);

    cnt[0] = height[0];

    for (int i = 1, p, h; i < height.size(); ++i) {
      cnt[i] = cnt[i-1] + height[i];
      p = highest[i-1], h = height[p];
      if (height[i] >= h) {
        highest[i] = i;
      } else {
        highest[i] = p;
        p = i - 1, h = height[i];
        for (; p >= 0 && height[p] < h; --p) /* empty */;
      }
      area[i] = (i - p - 1) * h - (cnt[i-1] - cnt[p]) + area[p];
      if (area[i] < 0) area[i] = 0;
    }

    return area.back();
  }
};
