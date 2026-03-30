#include <stdio.h>
int maxProfit(int* prices, int pricesSize) {
    int result = 0;
    for(int i = 0; i < pricesSize; ++i){
        int profit = 0;

        for (int j = i + 1; j < pricesSize; ++j) {
             int sum = prices[j] - prices[i];
            if (sum > profit) profit = sum;
        }

        result = profit;
    }
    return result;
}

int main(void){

    int  prices[] = {7,1,5,3,6,4};

    int result = maxProfit(prices, 6);
    printf("%d", result);
    return 0;
}