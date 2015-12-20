class Solution {
public:
  bool wordPattern(string pattern, string str) {
    unordered_map<char, string> h1;
    unordered_map<string, bool> h2;

    int beg = 0, end = 1;
    for (char c : pattern) {
      end = str.find_first_of(' ', beg)
    }
  }
};
