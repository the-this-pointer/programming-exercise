// it's just a training!

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

std::vector<std::pair<char, char>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

typedef struct cell_s {
  char i;
  char j;

  char pi;
  char pj;

  char f;
  char g;
  char h;
} cell_t;

class Solution {
public:
  int minPushBox(vector<vector<char>>& grid) {
    int res = -1;
    auto cmp = [](cell_t left, cell_t right) { return left.f < right.f; };
    vector<cell_t> openList, closedList;

    auto valid = [&grid](char i, char j) {
      return j < grid.size() && i < grid[0].size();
    };

    cell_t goal = {-1, -1, 0, 0, 0};
    // find the starting point
    for(char j = 0; j < grid.size(); j++)
      for(char i = 0; i < grid[j].size(); i++)
        if (grid[j][i] == 'B')
          openList.push_back({i, j, -1, -1, 0, 0, 0}), cout << "found the starting point " << (int)i << ", " << (int)j << endl;
        else if (grid[j][i] == 'T')
          goal.i = i, goal.j = j,cout << "found the goal point " << (int)i << ", " << (int)j << endl;


    while(!openList.empty())
    {
      sort(openList.begin(), openList.end(), cmp);
      auto q = *openList.begin();
      openList.erase(openList.begin());
      closedList.push_back(q);

      for (const std::pair<char, char>& dir: dirs)
      {
        char ci = q.i + dir.second;
        char cj = q.j + dir.first;
        if (!valid(cj, ci))
          continue;

        if  (grid[cj][ci] != '.' && grid[cj][ci] != 'T')
          continue;

        if (cj == goal.j && ci == goal.i) {
          cout << "found the target!" << endl;

          res = 1;
          cell_t p = q;
          do {
            cout << "loc " << (int)p.i << ", " << (int)p.j << endl;
            res++;
            for(const auto& _p: closedList)
              if (p.pi == _p.i && p.pj == _p.j)
                p = _p;
          } while (p.pi != -1);

          goto end;
        }

        char newG = q.g + 1;
        char newH = abs(ci - goal.i) + abs(cj - goal.j);
        char newF = newG + newH;

        bool skip = false;
        for (auto& c: openList)
          if (c.i == ci && c.j == cj && c.f < newF)
            skip = true;

        for (auto& c: closedList)
          if (c.i == ci && c.j == cj && c.f < newF)
            skip = true;

        if (!skip) {
          cell_t c;
          c.i = ci;
          c.j = cj;

          c.pi = q.i;
          c.pj = q.j;

          c.f = newF;
          c.g = newG;
          c.h = newH;
          openList.push_back(c);
          cout << "openlist push " << (int)ci << ", " << (int)cj << " with f " << (int)newF << endl;
        }
      }
    }
end:
    return res;
  }
};

int main()
{
  /*vector<vector<char>> grid = {{'#','#','#','#','#','#'},
                               {'#','T','#','#','#','#'},
                               {'#','.','.','B','.','#'},
                               {'#','.','#','#','.','#'},
                               {'#','.','.','.','.','#'},
                               {'#','#','#','#','#','#'}};*/

  vector<vector<char>> grid = {{'#','#','#','#','#','#'},
                               {'#','T','#','#','#','#'},
                               {'#','.','#','B','.','#'},
                               {'#','#','#','#','.','#'},
                               {'#','.','.','.','.','#'},
                               {'#','#','#','#','#','#'}};

	int out = 3;

	Solution s;
	int res = s.minPushBox(grid);

	cout << "Output: " << (out == res) << endl;
	return 0;
}