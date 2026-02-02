#include "headers.hpp"

int sum_digits_square(int n) {
    int sum = 0;
    while(n != 0) {
        int extract = n % 10;
        sum += extract * extract;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> seen;

    while(n != 1) {
        if(seen.count(n))
            return false;
        seen.insert(n);
        n = sum_digits_square(n);
    }
    return true;
}

int main() {



    return 0;
}