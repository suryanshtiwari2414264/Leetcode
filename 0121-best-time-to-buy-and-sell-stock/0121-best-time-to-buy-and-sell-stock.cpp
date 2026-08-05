// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {

//         int minPrice = prices[0];
//         int maxProfit = 0;

//         for(int i = 1; i < prices.size(); i++) {

//             minPrice = min(minPrice, prices[i]);

//             int profit = prices[i] - minPrice;

//             maxProfit = max(maxProfit, profit);
//         }

//         return maxProfit;
//     }
// };

//KADANE'S Solution
class Solution{
public:
    int maxProfit(vector<int> &prices){
        int currsum=0;
        int maxprof=0;
        int n=prices.size();
        for(int i=1;i<n;i++){
            currsum += prices[i]-prices[i-1];
            if(currsum<0)
                currsum=0;
            maxprof = max(maxprof,currsum);
        }
        return maxprof;

    }
};