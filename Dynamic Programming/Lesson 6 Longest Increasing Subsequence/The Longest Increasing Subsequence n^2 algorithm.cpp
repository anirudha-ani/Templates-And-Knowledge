/**
    Problem Link - https://leetcode.com/problems/longest-increasing-subsequence/#/description
    Solving Technique - Longest Increasing Subsequence (O(n^2) algorithm )
    Learning Resource - https://www.youtube.com/watch?v=CE2b_-XfVDk&list=PLgwE03nSxZ4GoHvoy6ay6OSBmcJ6BX2h7&index=6
**/

int DP[10005];

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0 )
        {
            return 0;
        }
        int ans = 1 ;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            DP[i] = 1 ;
        }

        for(int i = 1 ; i < nums.size() ; i++)
        {
            for(int j = 0 ; j < i ; j++)
            {
                if(nums[j] < nums[i])
                {
                    DP[i] = max(DP[j] + 1 , DP[i]);
                    ans = max(DP[i] , ans);
                }
            }
        }
        return ans ;
    }
};
