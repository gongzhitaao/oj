class Solution
{
 public:
  int minArea(vector<vector<char>>& image, int x, int y)
  {
    const int row = image.size(), col = image[0].size();
    int xmin = search_row(image, 0, x, 1);
    int xmax = search_row(image, x, row, 0);
    int ymin = search_col(image, 0, y, 1);
    int ymax = search_col(image, y, col, 0);
    return (xmax - xmin) * (ymax - ymin);
  }

  int search_row(vector<vector<char>>& img, int lo, int hi, int findmin)
  {
    int col = img[0].size();
    while (lo < hi) {
      int mi = lo + (hi - lo) / 2;
      int black = 0;
      for (int i = 0; i < col; ++i)
        if ('1' == img[mi][i]) {
          black = 1;
          break;
        }
      if (black ^ findmin)
        lo = mi + 1;
      else
        hi = mi;
    }
    return lo;
  }

  int search_col(vector<vector<char>>& img, int lo, int hi, int findmin)
  {
    int row = img.size();
    while (lo < hi) {
      int mi = lo + (hi - lo) / 2;
      int black = 0;
      for (int i = 0; i < row; ++i)
        if ('1' == img[i][mi]) {
          black = 1;
          break;
        }
      if (black ^ findmin)
        lo = mi + 1;
      else
        hi = mi;
    }
    return lo;
  }
};
