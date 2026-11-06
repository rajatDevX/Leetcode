class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        int direction=1;
        int row=0;
        vector<string>rows(numRows);
        for(int i=0;i<s.size();i++){
            rows[row]+=s[i];
            if(row==0){
                direction=1;
            }
            else if(row==numRows-1){
                direction=-1;
            }
            row+=direction;

        
        }
        string ans="";
        for(int i=0;i<numRows;i++){
            ans+=rows[i];
        }
        return ans;
        
    }
};