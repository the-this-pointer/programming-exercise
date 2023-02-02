#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;

    unordered_map<int, int> mapNum;
    for (int i = 0; i < nums.size(); i++)
      mapNum[nums[i]] = i;

    for (int i = 0; i < nums.size(); i++)
      if (mapNum.find(target - nums[i]) != mapNum.end() && i != mapNum[target - nums[i]])
      {
        res.push_back(i);
        res.push_back(mapNum[target - nums[i]]);
        break;
      }

    return res;
  }
};

int main() {
  vector<int> nums = {3,2,4};
  int target = 6;
  Solution s;

  vector<int> res = s.twoSum(nums, target);
  cout << "Output: " << endl;
  for(const auto c: res)
    cout << c << " " << endl;
  return 0;
}
