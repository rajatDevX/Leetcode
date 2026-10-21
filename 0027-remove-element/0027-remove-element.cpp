class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        int p=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                p++;
                continue;
            }
            nums[k]=nums[i];
            k++;
        }
        return nums.size()-p;
        
    }
};