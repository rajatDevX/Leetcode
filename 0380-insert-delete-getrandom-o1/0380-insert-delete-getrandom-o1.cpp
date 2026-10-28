class RandomizedSet {
public:
   unordered_map<int,int>mp;
        vector<int>nums;
    RandomizedSet() {
     
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        nums.push_back(val);
        mp[val]=nums.size()-1;
        return true;


        
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        int index=mp[val];
        int lastVal=nums.back();
        nums[index]=lastVal;
        mp[lastVal]=index;
        nums.pop_back();
        mp.erase(val);
        return true;



        
    }
    
  int getRandom() {
    int index = rand() % nums.size();
    return nums[index];
}
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */