class Codec
{
 public:
  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs)
  {
    string ret;
    for (string& w : strs) ret += to_string(w.size()) + "|" + w;
    return ret;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s)
  {
    vector<string> ret;
    for (int i = 0; i < s.size();) {
      int j = s.find_first_of('|', i);
      int size = stoi(s.substr(i, j - i));
      string t = s.substr(j + 1, size);
      ret.push_back(t);
      i = j + 1 + t.size();
    }
    return ret;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
