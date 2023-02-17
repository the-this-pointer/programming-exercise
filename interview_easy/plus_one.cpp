#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    int c = 1;
    for(int i = digits.size()-1; i >= 0; i--)
    {
      digits[i] = (digits[i] + c) % 10;
      c = 0;
      if (digits[i] == 0)
        c = 1;
      if (c == 0)
        break;
    }
    if (c == 1)
      digits.insert(digits.begin(), 1);
    return digits;
  }
};

int main() {
  vector<int> num = {};
  Solution s;

  s.plusOne(num);
  cout << "Output: " << endl;
  for(const auto c: num)
    cout << c << endl;
  return 0;
}
