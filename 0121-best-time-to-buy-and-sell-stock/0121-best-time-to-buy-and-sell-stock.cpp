class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int difference=0;
        int minPrice=prices[0];
        int maxProfit=0;
        for(int i=1;i<prices.size();i++){
           minPrice=min(minPrice,prices[i]);
           int currentProfit=prices[i]-minPrice;
           maxProfit=max(maxProfit,currentProfit);
          
        }
        return maxProfit;
        
    }
};