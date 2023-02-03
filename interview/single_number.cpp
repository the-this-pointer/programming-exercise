#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int cnt = 0;
    for (int i = 0; i < nums.size() -1; i++)
      if (nums[i] == nums[i+1]) {
        cnt++;
      }
      else if (cnt > 0)
        cnt = 0;
      else
        return nums[i];

    return nums[nums.size()-1];
  }
};

int main() {
  vector<int> nums = {1};
  Solution s;

  int res = s.singleNumber(nums);
  cout << "Output: " << res << endl;
  return 0;
}
