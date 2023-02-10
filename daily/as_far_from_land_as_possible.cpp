// https://leetcode.com/problems/as-far-from-land-as-possible/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

class Solution {
public:
  int maxDistance(vector<vector<int>>& grid) {
    int d = 0;
    const vector<pair<int, int>> dirs = {{-1,0}, {0, -1}, {1, 0}, {0, 1}};

    queue<pair<int,int>> q;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j])
          q.push({i, j});
      }
    }

    if (q.size() == 0 || q.size() == grid.size() * grid[0].size())
      return -1;

    int qSize;
    while ((qSize = q.size()))
    {
      while (qSize)
      {
        auto c = q.front();
        q.pop();
        qSize--;

        for (const auto dir: dirs)
        {
          int ci = c.first + dir.first;
          int cj = c.second + dir.second;

          if (ci >= 0 && cj >= 0 && ci <= grid.size() && ci < grid.size() && cj < grid[0].size() && grid[ci][cj] == 0)
          {
            grid[ci][cj] = 1;
            q.push({ci, cj});
          }
        }
      }
      d++;
    }

    return d-1;
  }
};

int main() {
	vector<vector<int>> grid = {{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}};
	int out = -1;
	Solution s;

  auto res = s.maxDistance(grid);
  cout << "Output: " << (res == out) << endl;
	getchar();
	return 0;
}