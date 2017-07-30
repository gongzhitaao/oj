class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
    for (uint32_t i = n, k = 31; i; i >>= 1, --k)
      ret |= (i & 1) << k;
    return ret;
  }
};
