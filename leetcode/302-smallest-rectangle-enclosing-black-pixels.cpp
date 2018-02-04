class Solution
{
 public:
  int minArea(vector<vector<char>>& image, int x, int y)
  {
    if (image.empty() || image[0].empty()) return 0;
    int xmin = x, xmax = x;
    int ymin = y, ymax = y;
    dfs(image, x, y, xmin, ymin, xmax, ymax);
    return (xmax - xmin + 1) * (ymax - ymin + 1);
  }

  void dfs(vector<vector<char>>& img, int x, int y, int& xmin, int& ymin,
           int& xmax, int& ymax)
  {
    if (x < xmin) xmin = x;
    else if (x > xmax) xmax = x;
    if (y < ymin) ymin = y;
    else if (y > ymax) ymax = y;
    img[x][y] = 'x';
    if (0 <= x - 1 && '1' == img[x - 1][y])
      dfs(img, x - 1, y, xmin, ymin, xmax, ymax);
    if (y + 1 < img[0].size() && '1' == img[x][y + 1])
      dfs(img, x, y + 1, xmin, ymin, xmax, ymax);
    if (x + 1 < img.size() && '1' == img[x + 1][y])
      dfs(img, x + 1, y, xmin, ymin, xmax, ymax);
    if (0 <= y - 1 && '1' == img[x][y - 1])
      dfs(img, x, y - 1, xmin, ymin, xmax, ymax);
  }
};
