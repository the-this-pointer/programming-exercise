// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/769/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    auto checkDuplicates = [] (vector<char> v) {
      if (v.size() == 0)
        return false;
      sort(v.begin(), v.end());
      for (int i = 0; i < v.size() - 1; i++)
        if (v[i] == v[i + 1] && v[i] != '.')
          return true;
      return false;
    };
    auto checkSubBox = [&board, checkDuplicates](int i, int j) {
      vector<char> res;
      for (int si = 0; si < 3; si++)
        for (int sj = 0; sj < 3; sj++)
          if (board[sj + j][si + i] != '.')
            res.push_back(board[sj + j][si + i]);
      return !checkDuplicates(res);
    };
    auto checkVertical = [&board, checkDuplicates](int i) {
      vector<char> res;
      for (int j = 0; j < board.size(); j++)
        if (board[j][i] != '.')
          res.push_back(board[j][i]);
      return !checkDuplicates(res);
    };
    auto checkHorizontal = [&board, checkDuplicates](int j) {
      return !checkDuplicates(board[j]);
    };

    for (int j = 0; j < board.size(); j++) {
      if (!checkHorizontal(j))
        return false;
      for (int i = 0; i < board[j].size(); i++)
        if (!checkVertical(i))
          return false;
    }

    for (int j = 0; j < board.size(); j+=3)
      for (int i = 0; i < board[j].size(); i+=3)
        if (!checkSubBox(i, j))
          return false;
    return true;
  }
};

int main() {
  vector<vector<char>> board =
      /*{{'8','3','.','.','7','.','.','.','.'}
      ,{'6','.','.','1','9','5','.','.','.'}
      ,{'.','9','8','.','.','.','.','6','.'}
      ,{'8','.','.','.','6','.','.','.','3'}
      ,{'4','.','.','8','.','3','.','.','1'}
      ,{'7','.','.','.','2','.','.','.','6'}
      ,{'.','6','.','.','.','.','2','8','.'}
      ,{'.','.','.','4','1','9','.','.','5'}
      ,{'.','.','.','.','8','.','.','7','9'}};*/
      {{'.','.','.','.','.','.','.','.','.'}
      ,{'.','.','.','.','.','.','.','.','.'}
      ,{'.','.','.','.','.','.','.','.','.'}
      ,{'.','.','.','.','.','.','.','.','.'}
      ,{'.','.','.','.','.','.','.','.','.'}
      ,{'.','.','.','.','.','.','.','.','.'}
      ,{'.','.','.','.','.','.','.','.','.'}
      ,{'.','.','.','.','.','.','.','.','.'}
      ,{'.','.','.','.','.','.','.','.','.'}};

  Solution s;
  bool res = s.isValidSudoku(board);
  cout << "Output: " << res << endl;
  return 0;
}
