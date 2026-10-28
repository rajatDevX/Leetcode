class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int multiplication=1;
        int n=nums.size();
        vector<int>products(n,1);
        for(int i=1;i<nums.size();i++){
          products[i]=multiplication*nums[i-1];
          multiplication=products[i];

            
        }
        int right=1;
        for(int i=n-1;i>=0;i--){
            products[i]=right*products[i];
            right=right*nums[i];
        }
        return products;
    }
};