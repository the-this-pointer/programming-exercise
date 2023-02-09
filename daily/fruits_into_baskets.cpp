// https://leetcode.com/problems/fruit-into-baskets/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;

class Solution {
public:

	int totalFruit(vector<int>& fruits) {
		unordered_map<int, int> fruitCount;
		int max = 0, curMax = 0, curTypes = 0, curStart = 0;

		for (int i = 0; i < fruits.size(); i++)
		{
			if (fruitCount[fruits[i]] == 0)
				curTypes++;
			fruitCount[fruits[i]]++;
			curMax++;

			while (curTypes > 2 && curStart < i)
			{
				fruitCount[fruits[curStart]]--;
				if (fruitCount[fruits[curStart]] == 0)
					curTypes--;
				curStart++;
				curMax--;
			}

			max = std::max(max, curMax);
		}
		return max;
	}
};

int main() {
	vector<vector<int>> fruits = { { 1, 2, 1 }, { 0, 1, 2, 2 }, { 1, 2, 3, 2, 2 }, { 3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4 }, { 3, 3, 3, 3, 3, 3 }, { 1, 1, 6, 5, 6, 6, 1, 1, 1, 1 } };
	vector<int> output = { 3, 3, 4, 5, 6, 6 };
	Solution s;

	for (int i = 0; i < fruits.size(); i++)
	{
		auto res = s.totalFruit(fruits[i]);
		cout << "--------------" << endl;
		cout << "Output : " << (res == output[i]) << endl;
	}
	getchar();
	return 0;
}