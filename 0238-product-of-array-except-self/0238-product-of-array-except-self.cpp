class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int multiply=1;
        vector<int>products(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            multiply=multiply*nums[i-1];
            products[i]=multiply;
        }
        int right=1;
        for(int i=nums.size()-1;i>=0;i--){
           products[i] =products[i]*right;
           right=right*nums[i];


        }
        return products;
    }
};