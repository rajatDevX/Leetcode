class Solution {
public:
    int solve(vector<int>nums,int i,vector<int>&memo){
        if(i<0){
            return 0;
        }
        if(memo[i]!=-1){
            return memo[i];
        }
        int rob=nums[i]+solve(nums,i-2,memo);
        int skip=solve(nums,i-1,memo);
        return memo[i]=max(rob,skip);

    }
    int rob(vector<int>& nums) {
        vector<int>memo(nums.size(),-1);
        return solve(nums,nums.size()-1,memo);
    }
};