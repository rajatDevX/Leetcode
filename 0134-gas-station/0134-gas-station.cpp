class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 1-greedy
        int remaining =0;
        int startingIndex=0;
        int total=0;
        for(int i=0;i<gas.size();i++){
            remaining+=gas[i]-cost[i];
               total += gas[i] - cost[i];
            if(remaining<0){
                startingIndex=i+1;
                remaining=0;
            }

        }
        if(total<0){
            return -1;
        }
        else{
            return startingIndex;
        }
        
    }
};