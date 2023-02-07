// https://leetcode.com/problems/shuffle-the-array/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;

class Solution {
public:
	vector<int> shuffle(vector<int>& nums, int n) {
		vector<int> ret;

		for (int i = 0; i < n; i++)
		{
			ret.push_back(nums[i]);
			ret.push_back(nums[n + i]);
		}

		return ret;
	}
};

int main() {
	vector<vector<int>> nums = { { 2, 5, 1, 3, 4, 7 }, { 1, 2, 3, 4, 4, 3, 2, 1 }, { 1, 1, 2, 2 } };
	vector<int> n = { 3, 4, 2 };
	vector<vector<int>> out = { { 2, 3, 5, 4, 1, 7 }, { 1, 4, 2, 3, 3, 2, 4, 1 }, { 1, 2, 1, 2 } };
	Solution s;

	for (int i = 0; i < nums.size(); i++)
	{
		auto res = s.shuffle(nums[i], n[i]);
		cout << "Output: " << (res == out[i]) << endl;
	}
	getchar();
	return 0;
}