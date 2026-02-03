#include "headers.hpp"

int maxArea(vector<int>& height) {
    int L = 0;
    int R = height.size() - 1;

    int max_area = 0;
    while(L < R) {
      int area = min(height[R], height[L]) * (R - L);
      max_area = max(max_area, area);

      if(height[L] <= height[R])
        L++;
      else
        R--;
    }
    return max_area;
}

int main() {


  return 0;
}