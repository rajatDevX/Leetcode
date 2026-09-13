class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum=nums[0];

        int currMax=nums[0];
        int maxSum=nums[0];
        int currMin=nums[0];
        int minSum=nums[0];

        for(int i=1;i<nums.size();i++){
            currMax=max(nums[i],nums[i]+currMax);
            maxSum=max(currMax,maxSum);

            currMin=min(nums[i],nums[i]+currMin);
            minSum=min(currMin,minSum);

            totalSum+=nums[i];
        }

        if(maxSum<0){
            return maxSum;
        }
        return max(maxSum,totalSum-minSum);
    }
};