// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
 public:
  int guessNumber(int n) {
    int mid;
    for (int l = 1, h = n; l <= h; ) {
      if (!guess(l)) return l;
      if (!guess(h)) return h;

      mid = l + (h - l) / 2;
      int g = guess(mid);
      if (!g) break;
      if (g > 0) l = mid + 1, --h;
      else ++l, h = mid - 1;
    }
    return mid;
  }
};
