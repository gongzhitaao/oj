class Solution {
 public:
  int wordsTyping(vector<string>& sentence, int rows, int cols)
  {
    int cnt = 0, n = sentence.size();
    for (int i = 0, j = 0; i < rows; ++i) {
      for (int col = 0; ; ++col) {
        if (n == j) j = 0, ++cnt;
        col += sentence[j].size();
        if (col > cols) break;
        ++j;
      }
    }
    return cnt;
  }
};
