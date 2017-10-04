// Forward declaration of the read4 API.
int read4(char *buf);

class Solution
{
 private:
  char buf_[4];
  int n_;
  int i_;

 public:
  Solution() : i_(0), n_(0) {}
  /**
   * @param buf Destination buffer
   * @param n   Maximum number of characters to read
   * @return    The number of characters read
   */
  int read(char *buf, int n)
  {
    int cnt;
    for (cnt = 0; cnt < n && ((i_ < n_) || (i_ = 0) < (n_ = read4(buf_)));
         ++cnt, ++i_)
      buf[cnt] = buf_[i_];
    return cnt;
  }
};
