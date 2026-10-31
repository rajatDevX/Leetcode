class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=1;
        int maxCandidate=nums[0];
        for(int i=1;i<n;i++){
            if(count==0){
                maxCandidate=nums[i];
                count=1;
            }
            else if(nums[i]==maxCandidate){
                count++;
            }
            else{
                count--;
            }
        }
        return maxCandidate;
        
    }
};