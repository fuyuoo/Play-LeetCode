class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int minprice = INT_MAX;
        int maxProfit = INT_MIN;
        for(int price : prices){
            if(price < minprice)
                minprice = price;
            if(price - minprice > maxProfit)
                maxProfit = price - minprice;
        }
        return maxProfit;
    }
};