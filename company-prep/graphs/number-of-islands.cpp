#include "include/headers.hpp"

/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ['1','1','1','1','0'],
  ['1','1','0','1','0'],
  ['1','1','0','0','0'],
  ['0','0','0','0','0']
]
Output: 1
Example 2:

Input: grid = [
  ['1','1','0','0','0'],
  ['1','1','0','0','0'],
  ['0','0','1','0','0'],
  ['0','0','0','1','1']
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

using vec2_ch = vector<vector<char>>;
using vec2_b = vector<vector<bool>>;


// 8 directions
void dfs_8(vec2_ch& grid, int r, int c, vec2_b& visited) {
  visited[r][c] = true;

  for(int dr = -1; dr <= 1; ++dr) {
    for(int dc = -1; dc <=1; ++dc) {
      if(dr == 0 && dc == 0) continue;

      int nr = r + dr;
      int nc = c + dc;
      if(isSafe(grid, r, c) && !visited[dr][dc])
        dfs(grid, r, c, visited);
    }
  }
}

bool isSafe(vec2_ch& grid, int r, int c) {
    int n = grid.size(); // num rows
    int m = grid[0].size(); // num cols

    bool within_bound = (r >= 0 && r < n && c >= 0 && c < m);

    return (within_bound && grid[r][c] == 'L');
}

void dfs(vec2_ch& grid, int r, int c, vec2_b& visited) {
    visited[r][c] = true;

    // down, up, right, left
    static int dr[4] = {1, -1, 0, 0};
    static int dc[4] = {0, 0, 1, -1};

    for(int k = 0; k < 4; ++k) {
        int nr = r + dr[k];
        int nc = c + dc[k];

        // also check if visited or not
        if(isSafe(grid, nr, nc) && !visited[nr][nc]) {
            dfs(grid, nr, nc, visited);
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vec2_b visited(n, vector<bool>(m, false));
    int num_island = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == '1' && !visited[i][j])
            {
                dfs(grid, i, j, visited);
                ++num_island;
            }
        }
    }
    return num_island;
}

int main() {

  vector<vector<char>> grid = {
        {'0','1','1','1','0'},
        {'0','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    // printing the number of islands
    cout << numIslands(grid) << endl;

    return 0;
}