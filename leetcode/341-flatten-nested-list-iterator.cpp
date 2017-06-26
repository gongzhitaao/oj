/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator
{
 public:
  NestedIterator(vector<NestedInteger> &nestedList)
      : ptr_(0)
  {
    visit(nestedList);
  }

  int next()
  {
    return flat_[ptr_++];
  }

  bool hasNext()
  {
    return ptr_ < flat_.size();
  }

 private:
  void visit(vector<NestedInteger> &vec)
  {
    for (auto& i : vec)
      if (i.isInteger()) flat_.push_back(i.getInteger());
      else visit(i.getList());
  }

  vector<int> flat_;
  int ptr_;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
