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

        vector<int> dp(m+1,0);
        dp[m] = true;
        for(int i = 0; i < m; i++){
            if(i < m)dp[i] = s2[i] == s3[n+i];
        }

        for(int i = n-1; i >= 0; i--){
            dp[m] = dp[m] && (s1[i] == s3[m+i]);
            for(int j = m-1; j>= 0; j--){
                bool ans = false;

                if(i < n && s1[i] == s3[i+j]){
                    ans = ans || dp[j];
                }

                if(j < m && s2[j] == s3[i+j]){
                    ans = ans || dp[j+1];
                }
                dp[j] = ans;
            }
        }

        return dp[0];
    }
};
