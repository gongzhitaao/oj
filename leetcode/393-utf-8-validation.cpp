class Solution
{
 public:
  bool validUtf8(vector<int>& data)
  {
    int n = data.size();
    for (int i = 0; i < n; ++i) {
      bool valid =
          !(0x80 & data[i] ^ 0x00) ||
          ((++i) < n &&
           !(0xE0 & data[i-1] ^ 0xC0) && !(0xC0 & data[i] ^ 0x80)) ||
          ((++i) < n &&
           !(0xF0 & data[i-2] ^ 0xE0) && !(0xC0 & data[i-1] ^ 0x80) && !(0xC0 & data[i] ^ 0x80)) ||
          ((++i) < n &&
           !(0xF8 & data[i-3] ^ 0xF0) && !(0xC0 & data[i-2] ^ 0x80) && !(0xC0 & data[i-1] ^ 0x80) && !(0xC0 & data[i] ^ 0x80));
      if (!valid) return false;
    }
    return true;
  }
};
