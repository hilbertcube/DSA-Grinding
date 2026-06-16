#include "headers.hpp"

int maxAreaBruteForce(vector<int> &heights) {
  int max_water = 0;
  for (int i = 0; i < heights.size(); ++i) {
    for (int j = i + 1; j < heights.size(); ++j) {
      int area = (j - i) * min(heights[i], heights[j]);
      max_water = max(area, max_water);
    }
  }
  return max_water;
}

int maxArea(vector<int> &heights) {
  int L = 0;
  int R = heights.size() - 1;
  int max_water = 0;

  while (L < R) {
    int area = (R - L) * min(heights[L], heights[R]);
    max_water = max(max_water, area);

    if (heights[L] <= heights[R])
      L++;
    else
      R--;
  }
  return max_water;
}

int main(int argc, char *argv[]) {

  return 0;
}