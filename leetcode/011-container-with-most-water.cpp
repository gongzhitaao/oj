class Solution
{
 public:
  int maxArea(vector<int>& height)
  {
    int maxarea = 0;
    for (int i = 0, j = height.size() - 1, w, h; i < j;) {
      w = j - i;
      if (height[j] >= height[i])
        h = height[i++];
      else
        h = height[j--];
      maxarea = max(maxarea, w * h);
    }
    return maxarea;
  }
};
