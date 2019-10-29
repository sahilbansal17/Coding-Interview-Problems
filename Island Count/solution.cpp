#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int dRow[4] = {-1, 0, 0, +1};
int dCol[4] = {0, +1, -1, 0};

/*
   C2
C1 C3 C4
   C5
*/

bool isSafe(int row, int col, int R, int C) {
  if (row < 0 || row >= R || col < 0 || col >= C) {
    return false;
  }
  return true;
}

void bfs(int cr, int cc, const vector<vector<int>>& binaryMatrix,
         vector<vector<bool>> &visited) {
  queue<pair<int, int>> q;
  q.push({cr, cc});
  int R = binaryMatrix.size();
  int C = binaryMatrix[0].size();
  while (!q.empty()) {
    // pop from the queue to get front cell
    int curRow = q.front().first;
    int curCol = q.front().second;
    visited[curRow][curCol] = true;
    q.pop();
    
    for (int k = 0; k < 4; ++k) {
      int nextRow = curRow + dRow[k];
      int nextCol = curCol + dCol[k];
      if (isSafe(nextRow, nextCol, R, C)) {
        bool shouldVisit = !visited[nextRow][nextCol] && 
                          (binaryMatrix[nextRow][nextCol] == 1);
        if (shouldVisit) {
          q.push({nextRow, nextCol});
        }
      }
    }
  }
}

int getNumberOfIslands( const vector<vector<int>>& binaryMatrix ) 
{
  int countOfIslands = 0;
  
  int rows = binaryMatrix.size();
  int cols = binaryMatrix[0].size();
  vector<vector<bool>> visited(rows, vector<bool>(cols, false));
  
  for (int curRow = 0; curRow < rows; ++curRow) {
    for (int curCol = 0; curCol < cols; ++curCol) {
      // check if not visited and equal to 1
      bool shouldVisit = !visited[curRow][curCol] && (binaryMatrix[curRow][curCol] == 1);
      if (shouldVisit) {
        bfs(curRow, curCol, binaryMatrix, visited);
        ++countOfIslands;
      }
    }
  }
  return countOfIslands;
}

int main() {
  
  vector<vector<int>> matrix = {{1, 1, 1, 1, 0}};
  
  cout << getNumberOfIslands(matrix) << endl;
  return 0;
  
}