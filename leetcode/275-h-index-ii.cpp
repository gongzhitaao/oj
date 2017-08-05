class Solution
{
 public:
  int hIndex(vector<int>& citations)
  {
    int n = citations.size();
    int ret = 0;
    for (int lo = 0, hi = n - 1, mi; lo <= hi; ) {
      mi = lo + (hi - lo) / 2;
      if (citations[mi] >= n - mi) {
        ret = n - mi;
        hi = mi - 1;
      } else lo = mi + 1;
    }
    return ret;
  }
};
