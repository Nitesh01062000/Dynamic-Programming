/*Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       sort(nums.begin(),nums.end()); 
        vector<int> parent(nums.size(),0);
        vector<int>dp(nums.size(),0);
        int m1=0,m2=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int j=i;j<nums.size();j++)
            {
                if(nums[j]%nums[i]==0 && dp[i]<1+dp[j])
                {
                    dp[i]=1+dp[j];
                    parent[i]=j;
                }
                
               if(dp[i]>m1)
               {
                   m1=dp[i]; m2=i;
               }
            }
            
            
        }
        
         vector<int> res;
        
        for(int i = 0; i < m1; ++i)
        {
            res.push_back(nums[m2]);
            m2 = parent[m2];
        }
        
        return res;

    }
};


        
        