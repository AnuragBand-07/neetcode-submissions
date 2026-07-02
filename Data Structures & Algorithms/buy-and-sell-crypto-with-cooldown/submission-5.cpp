class Solution {
private:
// buy --> 1, sell--> 0
int solve(int i, int buy_sell, vector<int>& prices, vector<vector<int>>& dp){
    int n = prices.size();
    if(i >= n)return 0;

    if(dp[i][buy_sell] != -1)return dp[i][buy_sell];

    if(buy_sell == 1){
        int buy = solve(i+1, 0, prices ,dp) - prices[i];
        int skip = solve(i+1, 1, prices, dp);
        return dp[i][buy_sell] = max(buy,skip);
    }
    else{
        int sell = solve(i+2, 1, prices ,dp) + prices[i];
        int skip = solve(i+1, 0, prices, dp);
        return dp[i][buy_sell] = max(sell,skip);
    }
    return 0;
}
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};
