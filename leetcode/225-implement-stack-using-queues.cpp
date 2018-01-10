class MyStack
{
  queue<int> q_;

 public:
  /** Initialize your data structure here. */
  MyStack() {}

  /** Push element x onto stack. */
  void push(int x)
  {
    q_.push(x);
    for (int i = 0; i < q_.size() - 1; ++i) {
      q_.push(q_.front());
      q_.pop();
    }
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop()
  {
    int cur = top();
    q_.pop();
    return cur;
  }

  /** Get the top element. */
  int top()
  {
    return q_.front();
  }

  /** Returns whether the stack is empty. */
  bool empty()
  {
    return q_.empty();
  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
