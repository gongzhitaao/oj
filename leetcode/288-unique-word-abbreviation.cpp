class ValidWordAbbr {
 public:
  ValidWordAbbr(vector<string> &dictionary)
  {
    for (string& w : dictionary) {
      if (dict_.find(w) == dict_.end()) {
        dict_.insert(w);
        ++abbr_[make_key(w)];
      }
    }
  }

  bool isUnique(string word)
  {
    string key = make_key(word);
    if (dict_.find(word) == dict_.end())
      return abbr_.find(key) == abbr_.end();
    return abbr_[key] < 2;
  }

  inline string make_key(string& w)
  {
    return w[0] +
        (w.size() > 2 ? to_string(w.size() - 2) : "") +
        w[w.size() - 1];
  }

 private:
  unordered_map<string, int> abbr_;
  unordered_set<string> dict_;
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
