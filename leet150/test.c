// gcc -o test test.c && ./test
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
int maxProfit(int* prices, int pricesSize){

  int cheapest = prices[0];
  int max_profit = 0;

  // find cheapes
  for(int i = 0; i < pricesSize; ++i){
    
    if(prices[i] < cheapest)
    {
      cheapest = prices[i];
    }
    else // check for max profit
    {
      int profit = prices[i] - cheapest;

      if (profit > max_profit) {
        max_profit = profit;
      }
    }
  }
  return max_profit;

}

int main(void){

    int  prices[] = {7,1,5,3,6,4};

    int result = maxProfit(prices, 6);
    printf("%d\n", result);
    return 0;
}