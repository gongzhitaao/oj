class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ret;
    unordered_map<string, int> count;
    for (int i = 0; i < int(s.size()) - 9; ++i) {
      string k = s.substr(i, 10);
      ++count[k];
      if (2 == count[k]) ret.push_back(k);
    }

    return ret;
  }
};

// https://discuss.leetcode.com/topic/50910/c-solution-without-using-set-or-map
// The following code provides an excellent way of computing the key.

// class Solution {
//  private:
//   inline int getBits(char &c) {
//     switch (c) {
//       case 'A': return 0;
//       case 'C': return 1;
//       case 'G': return 2;
//       case 'T': return 3;
//       default: return 0;
//     }
//   }
//  public:
//   vector<string> findRepeatedDnaSequences(string s) {
//     int arr[0x100000] = {0}; // 0x00000 ~ 0xfffff
//     int key = 0;
//     vector<string> answer;
//     for (int i = 0; i < s.size(); i++) {
//       key = (key << 2 | getBits(s[i])) & 0xfffff;
//       if (i < 9) continue;
//       if (arr[key] == 1)
//         answer.push_back(s.substr(i-9, 10));
//       arr[key]++;
//     }
//     return answer;
//   }
// };
