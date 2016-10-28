class Codec
{
 public:
  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs)
  {
    string ret;
    for (string& s : strs) {
      for (char c : s)
        ret += to_string(int(c)) + " ";
      ret += "-";
    }
    return ret;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s)
  {
    vector<string> ret;
    int n = 0;
    string tmp;
    for (char c : s) {
      switch (c) {
        case ' ':
          tmp += char(n);
          n = 0;
          break;
        case '-':
          ret.push_back(tmp);
          tmp = "";
          break;
        default:
          n = n * 10 + (c - '0');
      }
    }
    return ret;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
