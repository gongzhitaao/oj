class Solution {
public:
  bool isValid(string s) {
    stack<char> stk;
    char last;
    for (char c : s) {
      switch (c) {
      case ')':
        if (stk.empty()) return false;
        last = stk.top();
        stk.pop();
        if (last != '(') return false;
        break;
      case '}':
        if (stk.empty()) return false;
        last = stk.top();
        stk.pop();
        if (last != '{') return false;
        break;
      case ']':
        if (stk.empty()) return false;
        last = stk.top();
        stk.pop();
        if (last != '[') return false;
        break;
      default:
        stk.push(c);
      }
    }

    return stk.empty();
  }
};
