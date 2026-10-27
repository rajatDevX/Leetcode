class Solution {
public:
    int hIndex(vector<int>& citations) {
       int n=citations.size();
       sort(citations.begin(),citations.end(),greater<int>());
       int paperCount=0;
       for(int i=0;i<n;i++){
        if(citations[i]>i){
            paperCount++;
        }
       } 
       return paperCount;
    }
};