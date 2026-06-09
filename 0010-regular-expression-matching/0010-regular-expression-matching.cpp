class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        // dp[i][j] = does p[0..j-1] match s[0..i-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true; // empty pattern matches empty string

        // Handle patterns like a*, a*b*, .* that can match empty string
        for (int j = 2; j <= n; j++)
            if (p[j-1] == '*')
                dp[0][j] = dp[0][j-2];

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] == '*') {
                    // Zero occurrences of preceding element
                    dp[i][j] = dp[i][j-2];
                    // One more occurrence (if preceding element matches s[i-1])
                    if (p[j-2] == '.' || p[j-2] == s[i-1])
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                } else {
                    // Direct match: letter or '.'
                    if (p[j-1] == '.' || p[j-1] == s[i-1])
                        dp[i][j] = dp[i-1][j-1];
                }
            }
        }

        return dp[m][n];
    }
};