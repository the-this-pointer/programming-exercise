// https://leetcode.com/problems/zigzag-conversion/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
      vector<string> rows(numRows, "");
      int currentRow = 0;

      for(int i = 0; i < s.length();)
      {
        for (currentRow = 0; i < s.length() && currentRow < numRows; i++, currentRow++)
          rows[currentRow].push_back(s[i]);
        for (currentRow = numRows-2; i < s.length() && currentRow > 0; i++, currentRow--)
          rows[currentRow].push_back(s[i]);
      }
      string res;
      for (int i = 0; i < numRows; i++)
        res += rows[i];
      return res;
    }
};

int main() {
  string input = "A";
  int numRows = 5;
  Solution s;

  string res = s.convert(input, numRows);
  cout << "Output: " << res << endl;
  return 0;
}
