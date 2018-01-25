class Solution
{
 public:
  bool verifyPreorder(vector<int>& preorder)
  {
    int n = preorder.size();
    return isvalid(preorder, 0, n - 1);
  }

  bool isvalid(vector<int>& vec, int lo, int hi)
  {
    if (hi - lo + 1 < 3) return true;

    int mi = lo + 1;
    for (; mi <= hi && vec[mi] < vec[lo]; ++mi)
      ;

    for (int i = mi; i <= hi; ++i)
      if (vec[i] < vec[lo]) return false;

    return isvalid(vec, lo + 1, mi - 1) && isvalid(vec, mi, hi);
  }
};
