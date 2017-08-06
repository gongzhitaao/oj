class Solution
{
 public:
  int shortestWordDistance(vector<string>& words, string word1, string word2)
  {
    vector<int> p0, p1;
    for (int i = 0; i < words.size(); ++i) {
      if (words[i] == word1) p0.push_back(i);
      else if (words[i] == word2) p1.push_back(i);
    }

    if (p1.empty()) {
      int d = words.size();
      for (int i = 1; i < p0.size(); ++i) {
        if (p0[i] - p0[i-1] < d)
          d = p0[i] - p0[i-1];
      }
      return d;
    }

    int d = words.size();
    for (int t : p0) {
      for (int lo = 0, hi = p1.size()-1, mi; lo <= hi; ) {
        mi = lo + (hi - lo) / 2;
        if (abs(p1[mi] - t) < d)
          d = abs(p1[mi] - t);
        if (1 == d) return d;
        if (t > p1[mi]) lo = mi + 1;
        else hi = mi - 1;
      }
    }
    return d;
  }
};
