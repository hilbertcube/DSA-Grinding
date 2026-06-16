#include "headers.hpp"

using vec2 = vector<vector<int>>;

/*
costs[i][0] = cost to paint house i with red
costs[i][1] = cost to paint house i with blue
costs[i][2] = cost to paint house i with green

find minimum cost to paint the houses, knowing that no two adjacent house can have the same color

idea:

- since adjacent houses can't have the same color, if we paint the prev house red, the current house can only be blue or green
- idea: use dp
- for each house position, we need to track
    - the min cost if we paint this house red/blue/green

    min cost for painting house i red would be

    min(cost if prev blue, cost if prev green) + cost to paint current red

*/

int min_cost(vector<vector<int>> &costs) {
  const int n = costs.size();
  const int cols = 3;
  vec2 dp(n, vector<int>(cols, 0));

  for (int i = 1; i < n; ++i) {
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
  }
}

int main(int argc, char *argv[]) {

  return 0;
}