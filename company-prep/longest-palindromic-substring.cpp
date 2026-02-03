#include "headers.hpp"

// O(n^2) time, O(1) space
string longestPalindrome(string s) {
    int n = s.size();
    int best_l = 0, best_len = 1;

    auto expand = [&](int l, int r) {
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > best_len) {
                best_len = r - l + 1;
                best_l = l;
            }
            --l;
            ++r;
        }
    };

    for (int i = 0; i < n; ++i) {
        expand(i, i);     // odd length
        expand(i, i + 1); // even length
    }

    return s.substr(best_l, best_len);
}

int main() {


    return 0;
}