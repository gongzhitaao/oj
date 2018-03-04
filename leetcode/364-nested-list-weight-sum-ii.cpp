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
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer
 * to it. void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution
{
 public:
  int depthSumInverse(vector<NestedInteger>& nestedList)
  {
    int maxdep = 1, sum = 0, tmp = 0;
    for (NestedInteger& nl : nestedList) tmp += dfs(nl, 1, maxdep, sum);
    return sum * (maxdep + 1) - tmp;
  }

  int dfs(NestedInteger& nl, int curdep, int& maxdep, int& sum)
  {
    if (curdep > maxdep) maxdep = curdep;
    if (nl.isInteger()) {
      sum += nl.getInteger();
      return nl.getInteger() * curdep;
    }
    int ret = 0;
    for (NestedInteger& e : nl.getList())
      ret += dfs(e, curdep + 1, maxdep, sum);
    return ret;
  }
};
