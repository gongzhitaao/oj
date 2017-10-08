class Solution
{
 public:
  int maximumSwap(int num)
  {
    string numstr = to_string(num);
    const int n = numstr.size();
    vector<int> pos(n, 0);
    for (int i = n - 1, maxpos = n - 1; i >= 0; --i)
      if (numstr[i] > numstr[maxpos]) pos[i] = maxpos = i;
      else if (numstr[i] < numstr[maxpos]) pos[i] = maxpos;
      else pos[i] = i;
    for (int i = 0; i < n; ++i)
      if (pos[i] != i) {
        swap(numstr[i], numstr[pos[i]]);
        break;
      }
    return stoi(numstr);
  }
};
