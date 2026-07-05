class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        int k = s3.length();

        if(n+m != k)return false;
        if(n == 0 || m == 0){
            return s1 == s3 || s2 == s3;
        }
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        dp[n][m] = 1;
        for(int i = 0; i < m; i++){
            dp[n][i] = (s2[i] == s3[i+n]);
        }
        for(int i = 0; i < n; i++){
            dp[i][m] = (s1[i] == s3[i+m]);
        }

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j>= 0; j--){
                bool ans = false;

                if(i < n && s1[i] == s3[i+j]){
                    ans = ans || dp[i+1][j];
                }

                if(j < m && s2[j] == s3[i+j]){
                    ans = ans || dp[i][j+1];
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }
};
