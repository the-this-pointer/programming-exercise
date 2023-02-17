#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int profit = 0, prevPrice = prices[0];
    for (const auto& price: prices)
    {
      if (price > prevPrice)
      {
        profit += price - prevPrice;
      }

      prevPrice = price;
    }
    return profit;
  }
};

int main() {
  vector<int> nums = {7,1,5,3,6,4}; // => 7
  // vector<int> nums = {1,2,3,4,5}; // => 4
  // vector<int> nums = {7,6,4,3,1}; // => 0
  Solution s;
  int res = s.maxProfit(nums);
  cout << "Output: " << res << endl;
  return 0;
}
