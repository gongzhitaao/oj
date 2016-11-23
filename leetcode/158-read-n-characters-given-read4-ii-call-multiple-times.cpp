// Forward declaration of the read4 API.
int read4(char *buf);

class Solution
{
 public:
  Solution()
  { i4_ = n4_ = 0; }
  /**
   * @param buf Destination buffer
   * @param n   Maximum number of characters to read
   * @return    The number of characters read
   */
  int read(char *buf, int n)
  {
    int i = 0;
    while (i < n && (i4_ < n4_ || (i4_ = 0) < (n4_ = read4(buf_))))
      buf[i++] = buf_[i4_++];
    return i;
  }

 private:
  char buf_[4];
  int i4_, n4_;
};
