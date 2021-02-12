/*Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

It's guaranteed the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag
 

Constraints:

0 <= s.length, t.length <= 1000
s and t consist of English letters.*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.length(), n = s.length();
        long long int dp[m+1][n+1];
        for(int i=0;i<=m;i++) dp[i][0]=0;
        for (int j = 0; j <= n; j++) dp[0][j] = 1;
        for (int j = 1; j <= n; j++)
        { for (int i = 1; i <= m; i++){
               if(t[i-1]==s[j-1])
                   dp[i][j]=dp[i][j-1]+dp[i-1][j-1]; //without s[j-1] + with s[j-1]
            else
                dp[i][j]=dp[i][j-1]; // without s[j-1]
        }
        }
        return dp[m][n];
    }
};