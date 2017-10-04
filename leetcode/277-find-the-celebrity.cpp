// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution
{
 public:
  int findCelebrity(int n)
  {
    int cand0 = 0;
    for (int i = 1; i < n; ++i)
      if (knows(cand0, i)) cand0 = i;
    int cand1 = n - 1;
    for (int i = n - 2; i >= 0; --i)
      if (knows(cand1, i)) cand1 = i;
    return cand0 == cand1 ? cand0 : -1;
  }
};
