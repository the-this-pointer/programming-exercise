#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int nonZeroIdx = 0;
    for(int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 0)
      {
        for (nonZeroIdx = i + 1; nonZeroIdx < nums.size() && nums[nonZeroIdx] == 0; nonZeroIdx++);
        if (nonZeroIdx < nums.size() && nums[nonZeroIdx] != 0)
        {
          auto tmp = nums[i];
          nums[i] = nums[nonZeroIdx];
          nums[nonZeroIdx] = tmp;
        }
      }
    }
  }
};

int main() {
  vector<int> nums = {45192,0,-659,-52359,-99225,-75991,0,-15155,27382,59818,0,-30645,-17025,81209,887,64648};
  Solution s;

  s.moveZeroes(nums);
  cout << "Output: " << endl;
  for(const auto c: nums)
    cout << c << " ";
  return 0;
}
