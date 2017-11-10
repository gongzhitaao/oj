class Solution
{
 public:
  int minDistance(string word1, string word2)
  {
    vector<int> cur(word2.size() + 1, 0), pre(word2.size() + 1, 0);
    for (int j = 1; j <= word2.size(); ++j)
      cur[j] = pre[j] = j;

    for (int i = 0; i < word1.size(); ++i) {
      swap(cur, pre);
      cur[0] = i + 1;
      for (int j = 0; j < word2.size(); ++j) {
        if (word1[i] == word2[j])
          cur[j + 1] = pre[j];
        else
          cur[j + 1] = min(min(pre[j + 1], pre[j]), cur[j]) + 1;
      }
    }
    return cur[word2.size()];
  }
};
