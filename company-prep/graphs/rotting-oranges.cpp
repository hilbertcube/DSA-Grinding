#include "headers.hpp"

/*
You are given an m x n grid where each cell can have one of three values:
- 0 representing an empty cell,
- 1 representing a fresh orange, or
- 2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1
*/

using vec2i = vector<vector<int>>;
using vec2b = vector<vector<bool>>;

bool isValid(const vec2i& grid, int r, int c) {
    int n = grid.size();
    int m = grid[0].size();

    bool within_bound = (r >= 0 && r < n && c >= 0 && c < m);
    return (within_bound);
}

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    int fresh = 0;

    // Initialize
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            // push all rotten oranges onto a queue
            // (multi-source bfs)
            if (grid[r][c] == 2) 
                q.push({r, c});
            else if (grid[r][c] == 1) 
                ++fresh;
        }
    }

    if (fresh == 0)
        return 0;

    static const int dr[4] = {1, -1, 0, 0};
    static const int dc[4] = {0, 0, 1, -1};

    int minutes = 0;

    while(!q.empty()) {
        int sz = q.size();
        bool rotted_this_round = false;

        while(sz > 0) {
            auto [curr_r, curr_c] = q.front(); q.pop();

            for(int k{0}; k < 4; ++k) {
                int nr = curr_r + dr[k];
                int nc = curr_c + dc[k];

                if(isValid(grid, nr, nc) && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2; // mark as visited
                    q.push({nr, nc});
                    --fresh;
                    rotted_this_round = true;
                }
            }
            --sz;
        }
        if(rotted_this_round) minutes++;
    }
    return (fresh == 0 ? minutes : -1);
}

int main(int argc, char *argv[])
{

    return 0;
}