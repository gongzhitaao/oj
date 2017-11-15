class ValidWordAbbr
{
  unordered_map<string, int> abbr_;
  unordered_set<string> dict_;

 public:
  ValidWordAbbr(vector<string> dictionary)
  {
    for (string& word : dictionary) {
      if (word.empty() || dict_.find(word) != dict_.end()) continue;
      dict_.insert(word);
      int n = word.size();
      string key = n > 2 ? word[0] + to_string(n - 2) + word.back() : word;
      ++abbr_[key];
    }
  }

  bool isUnique(string word)
  {
    if (word.empty()) return true;
    int n = word.size();
    string key = n > 2 ? word[0] + to_string(n - 2) + word.back() : word;
    return abbr_.find(key) == abbr_.end() ||
           1 == abbr_[key] && dict_.find(word) != dict_.end();
  }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
