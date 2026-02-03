#include "headers.hpp"

using vec2i = vector<vector<int>>;

bool isValid(vec2i& grid, int r, int c) {
    int n = grid.size();
    int m = grid[0].size();
    return (r >= 0 && r < n && c >= 0 && c < m);
}

void dfs(vec2i& grid, int r, int c, vec2i& visited, queue<pair<int,int>>& q) {
    visited[r][c] = 1;
    q.push({r, c});

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    // for each neighbor of (r, c)
    for(int k = 0; k < 4; ++k) {
        int nr = r + dr[k];
        int nc = c + dc[k];

        if(isValid(grid, nr, nc) && !visited[nr][nc] && grid[nr][nc] == 1) {
            dfs(grid, nr, nc, visited, q);
        }
    }
}

// DFS + multi-source BFS
int shortestBridge(vector<vector<int>>& grid) {
 int n = grid.size();
    int m = grid[0].size();

    vec2i visited(n, vector<int>(m, 0));
    queue<pair<int,int>> q;

    bool found = false;

    // Step 1: find first island and DFS it
    for(int i = 0; i < n && !found; ++i) {
        for(int j = 0; j < m && !found; ++j) {
            if(grid[i][j] == 1) {
                dfs(grid, i, j, visited, q);
                found = true;
            }
        }
    }

    // Step 2: BFS expansion to reach second island
    int steps = 0;
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            auto [r, c] = q.front();
            q.pop();

            for(int k = 0; k < 4; ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(!isValid(grid, nr, nc) || visited[nr][nc])
                    continue;

                if(grid[nr][nc] == 1)
                    return steps;

                visited[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
        steps++;
    }

    return -1;
}

int main(int argc, char *argv[])
{

    return 0;
}