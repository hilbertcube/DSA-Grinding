#include "headers.hpp"

using vec2i = vector<vector<int>>;

void transpose(vec2i& matrix) {
  int n = matrix.size();

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < i; ++j) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }
}   

// flip along the central vertical axis
void flip_horizontally(vec2i& matrix) {
  int n = matrix.size();

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n / 2; ++j) {
      swap(matrix[i][j], matrix[i][n - 1 - j]);
    }
  }
}

void rotate(vector<vector<int>>& matrix) {
  transpose(matrix);
  flip_horizontally(matrix);
}

int main(int argc, char *argv[])
{

    return 0;
}