#include <iostream>
#include <vector>
using namespace std;

class Solution {
 private:
  int dx[4] = {-1, 0, 0, +1};
  int dy[4] = {0, -1, +1, 0};
  int res;

  bool allVisited(vector<vector<int>>& grid) {
    for (int r = 0; r < grid.size(); ++r) {
      for (int c = 0; c < grid[0].size(); ++c) {
        if (grid[r][c] == 0) {  // unvisited cell
          return false;
        }
      }
    }

    return true;
  }

  void backtrack(int sx, int sy, int ex, int ey, vector<vector<int>>& grid) {
    if (sx == ex && sy == ey) {
      // check if all cells are visited
      res += allVisited(grid) ? 1 : 0;
    }

    for (int k = 0; k < 4; ++k) {
      int nx = sx + dx[k];
      int ny = sy + dy[k];
      if (nx >= grid.size() || nx < 0 || ny >= grid[0].size() || ny < 0) {
        continue;  // safety checking
      }
      if (grid[nx][ny] == 0 ||
          grid[nx][ny] == 2) {  // only 0 / 2 cell can be visited
        grid[nx][ny] = 3;       // marking as visited
        backtrack(nx, ny, ex, ey, grid);
        grid[nx][ny] = 0;  // marking as unvisited
      }
    }
  }

 public:
  Solution() { res = 0; }

  int uniquePathsIII(vector<vector<int>>& grid) {
    int sx = -1, sy = -1, ex = -1, ey = -1;
    for (int r = 0; r < grid.size(); ++r) {
      for (int c = 0; c < grid[0].size(); ++c) {
        if (grid[r][c] == 1) {
          sx = r, sy = c;
        } else if (grid[r][c] == 2) {
          ex = r, ey = c;
        }
      }
    }

    backtrack(sx, sy, ex, ey, grid);
    return res;
  }
};

int main () {
	Solution solver;
  vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
	cout << solver.uniquePathsIII(grid) << endl;
	return 0;
}
