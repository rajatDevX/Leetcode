class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>mul(n,1);
        for(int i=1;i<n;i++){
            mul[i]=mul[i-1]*nums[i-1];



        }
        vector<int>mul1(n,1);
        for(int i=n-2;i>=0;i--){
            mul1[i]=mul1[i+1]*nums[i+1];


        }
        vector<int>result(n);
        for(int i=0;i<n;i++){
         result[i]=mul[i]*mul1[i];
        }
        return result;

    }
};