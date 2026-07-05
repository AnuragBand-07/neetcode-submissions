class Solution {
private:
    bool solve(int i, int j, string& s1, string& s2, string& s3, vector<vector<int>>& dp){
        int n = s1.length();
        int m = s2.length();
        int k = s3.length();
        if(i >= n && j >= m )return true;

        if(dp[i][j] != -1)return dp[i][j];

        bool ans = false;

        if(i < n && s1[i] == s3[i+j]){
            ans = ans || solve(i+1, j, s1, s2, s3, dp);
        }
        
        if(j < m && s2[j] == s3[i+j]){
            ans = ans || solve(i, j+1, s1, s2, s3, dp);
        }

        return dp[i][j] = ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        int k = s3.length();

        if(n+m != k)return false;
        if(n == 0 || m == 0){
            return s1 == s3 || s2 == s3;
        }
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

        return solve(0,0,s1,s2,s3,dp);
    }
};
