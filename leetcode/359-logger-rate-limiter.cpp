class Logger
{
 public:
  /** Initialize your data structure here. */
  Logger()
  {
  }

  /** Returns true if the message should be printed in the given
      timestamp, otherwise returns false.  If this method returns
      false, the message will not be printed.  The timestamp is in
      seconds granularity. */
  bool shouldPrintMessage(int timestamp, string message)
  {
    int last = -20;
    if (buf_.find(message) != buf_.end())
      last = buf_[message];
    bool print = timestamp - last >= 10;
    if (print) buf_[message] = timestamp;
    return print;
  }

 private:
  unordered_map<string, int> buf_;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
