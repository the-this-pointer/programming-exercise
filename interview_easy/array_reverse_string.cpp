#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  void reverseString(vector<char>& s) {
    for(int i = 0; i < s.size() / 2; i++)
      swap(s[i], s[s.size()-i-1]);
  }
};

int main() {
  vector<char> str = {'h','e','l','l','o'};
  Solution s;

  s.reverseString(str);
  cout << "Output: " << endl;
  for(const auto c: str)
    cout << c;
  getchar();
  return 0;
}
