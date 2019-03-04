
#define max(a, b) (a > b ? a : b)

int maxProfit(int* prices, int pricesSize) {
    int index, total;
    total = 0;
    for(index = 1;index < pricesSize;index++){
        total += max(prices[index] - prices[index - 1], 0);
    }
    return total;
}
