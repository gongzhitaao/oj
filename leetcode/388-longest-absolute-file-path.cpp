class Solution {
 public:
  int lengthLongestPath(string input)
  {
    int maxlen = 0;
    input += "\n";
    int n = input.size();
    vector<int> stk{0};
    for (int i = 0, cnt = 0, curlev = 0, isfile = 0;
         i < n; ++i) {
      switch (input[i]) {
        case '\n':
          while (stk.size() > curlev + 1)
            stk.pop_back();
          stk.push_back(stk.back() + cnt);
          if (isfile) {
            isfile = 0;
            if (stk.back() + curlev > maxlen)
              maxlen = stk.back() + curlev;
          }
          curlev = 0;
          cnt = 0;
          break;
        case '\t':
          ++curlev;
          break;
        case '.':
          isfile = 1;
        default:
          ++cnt;
          break;
      }
    }
    return maxlen;
  }
};
