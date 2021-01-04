/*Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.
A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

Example:

Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
*/


class Solution {
public:
    int recur(int n,int x,vector<vector<int>>&dp)
    {
        if(dp[n][x]!=(-1))
            return dp[n][x];
        int s=0;
        for(int i=1;i<=x;i++)
        {
            s+=recur(n-1,i,dp);
        }
        return (dp[n][x]=s);
    }
    int countVowelStrings(int n) {
        vector<vector<int>>dp(n+1,vector<int>(6,-1));
        for(int i=1;i<=5;i++)
            dp[1][i]=i;
        return recur(n,5,dp);
    }
};
