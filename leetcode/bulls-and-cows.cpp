class Solution {
public:
  string getHint(string secret, string guess) {
    int bulls = 0, cows = 0;
    vector<int> cnt(10, 0);

    for (int i = 0; i < secret.size(); ++i) {
      char a = secret[i], b = guess[i];
      if (a == b) ++bulls;
      else ++cnt[a - '0'];
    }

    for (int i = 0; i < secret.size(); ++i) {
      char a = secret[i], b = guess[i];
      if (a != b && cnt[b - '0']-- > 0) ++cows;
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
  }
};
