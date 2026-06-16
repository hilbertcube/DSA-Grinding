#include "headers.hpp"

void implementation(vector<int> &const input) {
}

#ifdef TESTING
#include <gtest/gtest.h>

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#else

int main() {
  return 0;
}

#endif
