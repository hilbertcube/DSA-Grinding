#include "../../include/headers.hpp"

/*
You are given a 2D grid representing a parking lot.

- 'C' represents a charging station
- 'E' represents an empty parking spot
- 'X' represents an obstacle

You are also given a starting position (sr, sc) that is guaranteed to be an empty spot.

Your task is to find the minimum number of steps required to reach any charging station.

You may move: up, down, left, right

You cannot move through obstacles.

If it is impossible to reach a charging station, return -1
*/

using vec2c = vector<std::vector<char>>;
using vec2b = vector<std::vector<bool>>;

bool isValid(vec2c& grid, int r, int c) {
    int n = grid.size();
    int m = grid[0].size();

    bool within_bound = (r >= 0 && r < n && c >= 0 && c < m);

    return (within_bound && grid[r][c] != 'X');
}

int minimumSteps(vec2c& grid, int r, int c) {
    if(grid[r][c] == 'X') return -1;
    if (grid[r][c] == 'C') return 0;

    int n = grid.size();
    int m = grid[0].size();

    int steps = 0;
    static const int dr[4] = {1, -1, 0 ,0};
    static const int dc[4] =  {0, 0, 1, -1};

    vec2b visited(n, vector<bool>(m, 0));
    queue<pair<int, int>> q;

    visited[r][c] = true;
    q.push({r, c});
    while(!q.empty()) {
        int sz = q.size();
        while(sz > 0) {
            auto [curr_r, curr_c] = q.front(); q.pop(); // structured bindings

            // for each unvisited neighbor of r, c
            // mark the neighbor as visited
            // enqueue the neighbor
            for(int k = 0; k < 4; ++k) {
                int nr = curr_r + dr[k];
                int nc = curr_c + dc[k];

                if(!isValid(grid, nr, nc) || visited[nr][nc])
                    continue;

                if(grid[nr][nc] == 'C')
                    return steps + 1;

                visited[nr][nc] = true;
                q.push({nr, nc});
            }
            --sz;
        }
        steps++;
    }
    return -1;
}

// regular BFS
int minimumSteps2(vec2c& grid, int r, int c) {
    int n = grid.size();
    int m = grid[0].size();

    if (grid[r][c] == 'C')
        return 0;

    static const int dr[4] = {1, -1, 0, 0};
    static const int dc[4] = {0, 0, 1, -1};

    vec2b visited(n, vector<bool>(m, false));
    queue<pair<pair<int, int>, int>> q;
    // { {row, col}, distance }

    visited[r][c] = true;
    q.push({{r, c}, 0});

    while (!q.empty()) {
        auto [pos, dist] = q.front();
        q.pop();

        int curr_r = pos.first;
        int curr_c = pos.second;

        for (int k = 0; k < 4; ++k) {
            int nr = curr_r + dr[k];
            int nc = curr_c + dc[k];

            if (!isValid(grid, nr, nc) || visited[nr][nc])
                continue;

            if (grid[nr][nc] == 'C')
                return dist + 1;

            visited[nr][nc] = true;
            q.push({{nr, nc}, dist + 1});
        }
    }

    return -1;
}



int main() {
    vector<std::vector<char>> grid = {
        {'E', 'E', 'E', 'X', 'C'},
        {'X', 'X', 'E', 'X', 'E'},
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'X', 'X', 'X', 'E'},
        {'E', 'E', 'E', 'C', 'E'}
    };

    return 0;
}