class Solution {
private:
    int solve(int i1, int i2, string& text1, string& text2, vector<vector<int>>& dp){
        if(i1 < 0 || i2 < 0)return 0;

        if(dp[i1][i2] != -1)return dp[i1][i2];

        if(text1[i1] == text2[i2]){
            return dp[i1][i2] = 1 + solve(i1-1, i2-1, text1, text2,dp);
        }
        else{
            int x = max(solve(i1-1,i2,text1,text2,dp), solve(i1,i2-1,text1,text2,dp));
            return dp[i1][i2] = x;
        }

        return 0;

    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,text1,text2,dp);
    }
};
