class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string reference=strs[0];
        int k=reference.size();
        bool match=true;
        string ans="";
        for(int i=0;i<k;i++){
            for(int j=1;j<strs.size();j++){
                if(i>=strs[j].size()||reference[i]!=strs[j][i]){
                    match=false;
                    break;
                }
            } 
            if(match==true){
               ans+=reference[i];
            }
            else{
                
                return ans;
            }
            
        }
        return ans;
    }
};