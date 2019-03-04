int maxProfit(int* prices, int pricesSize) {
    int buy, profit, now, max;
    
    max = 0;
    now = prices[0];
    for(buy = 1;buy < pricesSize;buy++){
        int profit = prices[buy] - now; 
        if(profit > max){
            max = profit;
        }
        if(now > prices[buy]){
            now = prices[buy];
        }
    }
    
    return max;
}