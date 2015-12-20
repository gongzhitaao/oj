// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int ret = -1;
    for (int l = 1, h = n; l <= h; ) {
      int m = ((long long)l + h) / 2;
      if (isBadVersion(m)) ret = m, h = m - 1;
      else l = m + 1;
    }

    return ret;
  }
};
