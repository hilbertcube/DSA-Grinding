#include "headers.hpp"

using vec2i = vector<vector<int>>;

bool isValid(vec2i& grid, int r, int c) {
  if (grid.empty() || grid[0].empty()) return false;

  int n = grid.size();
  int m = grid[0].size();

  bool within_bound = (r >= 0 && r < n && c >= 0 && c < m);
  return (within_bound && grid[r][c] == 1);
}

int dfs(vec2i& grid, int r, int c, vector<vector<bool>>& visited) {
    visited[r][c] = true;
    int area = 1;

    static const int dr[4] = {1, -1, 0, 0};
    static const int dc[4] = {0, 0, 1, -1};

    for(int k = 0; k < 4; ++k) {
        int nr = r + dr[k];
        int nc = c + dc[k];

        if(isValid(grid, nr, nc) && !visited[nr][nc]) {
            area += dfs(grid, nr, nc, visited);
        }
    }
    return area;
}

int maxAreaOfIsland(vec2i& grid) {
    int n = grid.size();
    int m = grid[0].size();

    int max_area = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == 1 && !visited[i][j]) {
                int area = dfs(grid, i, j, visited);
                max_area = max(max_area, area);
            }
        }
    }
    return max_area;
}

int main(int argc, char *argv[])
{

    return 0;
}