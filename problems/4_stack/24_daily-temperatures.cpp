#include "headers.hpp"

vector<int> dailyTemperaturesBrute(vector<int> &temps) {
  int n = temps.size();
  vector<int> result(n);

  for (int i{0}; i < n; ++i) {
    int steps = i + 1;
    while (steps < n && temps[i] >= temps[steps]) {
      steps++;
    }
    result[i] = (steps < n) ? steps - i : 0;
  }
  return result;
}

int main(int argc, char *argv[]) {

  return 0;
}