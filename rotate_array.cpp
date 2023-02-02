#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    if (k < nums.size())
      std::rotate(nums.rbegin(), nums.rbegin() + k, nums.rend());
    else
      for (int i = 0; i < k; i++)
        std::rotate(nums.rbegin(), nums.rbegin() + 1, nums.rend());
  }
};

int main() {
  /*vector<int> nums = {1,2,3,4,5,6,7};
  int k = 3;*/
  vector<int> nums = {-1};
  int k = 2;
  Solution s;

  s.rotate(nums, k);
  cout << "Output: " << endl;
  for(const auto& num: nums)
    cout << num << " " << endl;
  return 0;
}
