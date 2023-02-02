#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int currentNum = nums[0], currentW = 1;
    for(auto& num: nums)
    {
      if (num > currentNum)
      {
        currentNum = num;
        nums[currentW++] = num;
      }
    }
    return currentW;
  }
};

int main() {
  vector<int> nums = {1,2,2};
  Solution s;
  int res = s.removeDuplicates(nums);
  cout << "Output: " << res << endl;
  for (int i = 0; i < res; i++)
    cout << nums[i] << " ";
  return 0;
}
