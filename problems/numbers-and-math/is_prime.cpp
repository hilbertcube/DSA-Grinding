#include "headers.hpp"

vector<int> sieveOfEratosthenes(int n) {
  vector<bool> prime(n + 1, true);
  vector<int> output(n, 0);
  prime[0] = prime[1] = false;

  for (int p = 2; p * p <= n; p++) {
    if (prime[p]) {
      for (int i = p * p; i <= n; i += p)
        prime[i] = false;
    }
  }

  // Print all prime numbers
  for (int p = 2; p <= n; p++) {
    if (prime[p])
      output.push_back(p);
  }
  return {};
}

int main() {
}