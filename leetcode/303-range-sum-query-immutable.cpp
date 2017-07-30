class NumArray {
public:
  NumArray(vector<int> &nums) : psums(nums.size() + 1, 0) {
    partial_sum(nums.begin(), nums.end(), psums.begin() + 1);
  }

  int sumRange(int i, int j) {
    return psums[j + 1] - psums[i];
  }

private:
  vector<int> psums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
