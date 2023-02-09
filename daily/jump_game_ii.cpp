// https://leetcode.com/problems/jump-game-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int ret = 0;
		int curEnd = 0, nextEnd = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i > curEnd)
			{
				ret++;
				curEnd = nextEnd;
			}
			
			if (i + nums[i] > nextEnd)
				nextEnd = i + nums[i];
		}

		return ret;
	}
};

int main()
{
	vector<int> nums = { 2, 3, 1, 1, 4 };
	int out = 2;

	Solution s;
	int res = s.jump(nums);

	cout << "Output: " << (out == res) << endl;
	getchar();
	return 0;
}