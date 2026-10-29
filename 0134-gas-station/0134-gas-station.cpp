class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalCost=0;
        int totalGas=0;
        for(int i=0;i<gas.size();i++){
            totalCost+=cost[i];
            totalGas+=gas[i];
        }
        if(totalGas<totalCost){
            return -1;
        }
        int startIndex=0;
        int currentGas=0;
        for(int i=0;i<gas.size();i++){
             currentGas+=gas[i]-cost[i];
             if(currentGas<0){
                startIndex=i+1;
                currentGas=0;
             }
        }
        return startIndex;
        
    }
};