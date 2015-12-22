class Solution {
public:
  int maxProduct(vector<string>& words) {
    vector<unsigned int> bits;
    for (string &word : words) {
      unsigned int bit = 0;
      for (char c : word) bit |= 1 << (c - 'a');
      bits.push_back(bit);
    }

    int ret = 0;
    for (int i = 0; i < words.size(); ++i) {
      for (int j = i + 1; j < words.size(); ++j) {
        if (!(bits[i] & bits[j])) {
          int t = words[i].size() * words[j].size();
          if (t > ret) ret = t;
        }
      }
    }

    return ret;
  }
};
