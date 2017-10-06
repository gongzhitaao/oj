/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator
{
  vector<int> flat_;
  int ind_;

  void dfs(const vector<NestedInteger>& vni)
  {
    for (const NestedInteger& elm : vni) {
      if (elm.isInteger())
        flat_.push_back(elm.getInteger());
      else dfs(elm.getList());
    }
  }

 public:
  NestedIterator(vector<NestedInteger> &nestedList)
  {
    ind_ = 0;
    dfs(nestedList);
  }

  int next()
  {
    return flat_[ind_++];
  }

  bool hasNext()
  {
    return ind_ < flat_.size();
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
