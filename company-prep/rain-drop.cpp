#include "headers.hpp"

constexpr int ROAD_SIZE = 25;
constexpr int RAIN_SIZE = 5;

vector<int> road(ROAD_SIZE, 0);

bool isFilled(int pos) {
  int start = max(0, pos - RAIN_SIZE / 2);
  int end = min(ROAD_SIZE - 1, pos + RAIN_SIZE / 2);

  for (int i = start; i <= end; ++i) {
    road[i] += 1;
  }

  for (int i = start; i <= end; ++i) {
    if (road[i] == 0)
      return false;
  }
  return true;
}

int main() {

  return 0;
}