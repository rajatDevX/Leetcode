class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.size();i++){
            bool match=true;
            int starting_position=i;
            for(int j=0;j<needle.size();j++){
                
                
                if(haystack[i+j]!=needle[j]){
                    match=false;
                    break;
                
                    
                }
            }
            if(match==true){
                return starting_position;
            }
        }

        return -1;
    }
};