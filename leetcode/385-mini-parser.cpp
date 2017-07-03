/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution
{
 public:
  NestedInteger deserialize(string s)
  {
    int n = 0;
    int sign = 1;
    bool integer = false;
    vector<NestedInteger*> stk;
    NestedInteger* par = nullptr;
    NestedInteger* cur = new NestedInteger();
    for (char c : s) {
      switch (c) {
        case '[':
          stk.push_back(cur);
          cur = new NestedInteger();
          break;
        case ']':
          if (integer) {
            cur->add(NestedInteger(sign * n));
            sign = 1, n = 0, integer = false;
          }
          par = stk.back(); stk.pop_back();
          par->add(*cur);
          cur = par;
          break;
        case ',':
          if (integer) {
            cur->add(NestedInteger(sign * n));
            sign = 1, n = 0, integer = false;
          }
          break;
        case '-':
          sign = -1, integer = true;
          break;
        default:
          integer = true;
          n = n * 10 + c - '0';
          break;
      }
    }
    if (integer)
      return NestedInteger(sign * n);
    return cur->getList()[0];
  }
};
