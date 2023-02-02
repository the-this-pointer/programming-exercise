#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> lookup;
    for(int i = 0; i < nums.size(); i++)
    {
      if (lookup.find(nums[i]) != lookup.end())
        return true;
      lookup[nums[i]] = 0;
    }
    return false;
  }
};

int main() {
  vector<int> nums = {1,2,3,4};
  Solution s;

  int res = s.containsDuplicate(nums);
  cout << "Output: " << res << endl;
  return 0;
}
