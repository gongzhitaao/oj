// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution
{
 public:
  int findCelebrity(int n)
  {
    for (int i = 0, j; i < n; ++i) {
      for (j = 0; j < n; ++j) {
        if (j == i) continue;
        if (knows(i, j) || !knows(j, i))
          break;
      }
      if (j == n) return i;
    }
    return -1;
  }
};
