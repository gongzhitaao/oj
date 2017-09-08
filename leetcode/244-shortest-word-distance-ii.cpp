class WordDistance
{
 private:
  unordered_map<string, vector<int>> ind_;

 public:
  WordDistance(vector<string> words)
  {
    for (int i = 0; i < words.size(); ++i) ind_[words[i]].push_back(i);
  }

  int shortest(string word1, string word2)
  {
    vector<int>& a = ind_[word1];
    vector<int>& b = ind_[word2];
    int d = numeric_limits<int>::max();
    for (int i = 0, j = 0; i < a.size() && j < b.size(); ) {
      int cur = abs(a[i] - b[j]);
      if (cur < d) d = cur;
      if (a[i] < b[j]) ++i;
      else ++j;
    }
    return d;
  }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
