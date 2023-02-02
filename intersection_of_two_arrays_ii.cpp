#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    if (nums1.size() < nums2.size())
      swap(nums1, nums2);

    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
      if (nums1[i] < nums2[j]) {
        i++;
        continue;
      }
      else if (nums1[i] > nums2[j]) {
        j++;
        continue;
      }

      res.push_back(nums2[j]);
      i++;
      j++;
    }

    return res;
  }
};

int main() {
  vector<int> nums1 = {4,9,5};
  vector<int> nums2 = {9,4,9,8,4};
  Solution s;

  vector<int> res = s.intersect(nums1, nums2);
  cout << "Output: " << endl;
  for(auto n: res)
    cout << n << " ";
  return 0;
}
