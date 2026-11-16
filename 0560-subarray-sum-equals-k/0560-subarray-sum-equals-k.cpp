class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
       int n=nums.size();
       mp[0]=1;
       int sum=0;
       int count=0;
       for(int i=0;i<n;i++){
        sum+=nums[i];
        int remaining=sum-k;
        if(mp.find(remaining)!=mp.end()){
            count+=mp[remaining];
        }
        mp[sum]++;
       } 
       return count;
    }
};