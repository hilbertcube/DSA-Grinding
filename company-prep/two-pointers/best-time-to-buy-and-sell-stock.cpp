#include "headers.hpp"

int maxProfit(vector<int>& prices) {
    int L = 0, R = 1;
    int max_so_far = 0;

    while(R < prices.size()) {
        if(prices[L] < prices[R]) {
            int profit = prices[R] - prices[L];
            max_so_far = max(max_so_far, profit);
        } else {
            L = R;
        }
        R++;
    }
    return max_so_far;
}

int main(int argc, char *argv[])
{
    
    return 0;
}