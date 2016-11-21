class MinStack
{
 public:
  void push(int x)
  {
    if (s_.empty() || x <= min_.top())
      min_.push(x);
    s_.push(x);
  }

  void pop()
  {
    if (s_.top() == min_.top())
      min_.pop();
    s_.pop();
  }

  int top()
  {
    return s_.top();
  }

  int getMin()
  {
    return min_.top();
  }

 private:
  stack<int> s_;
  stack<int> min_;
};
