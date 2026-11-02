class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>r2i;
        r2i['I']=1;
        r2i['V']=5;
        r2i['X']=10;
        r2i['L']=50;
        r2i['C']=100;
        r2i['D']=500;
        r2i['M']=1000;
        int total=0;
        for(int i=0;i<s.length();i++){
            if(i+1<s.length() && r2i[s[i]]<r2i[s[i+1]]){
              total-=r2i[s[i]];
            }
            else{
                total+=r2i[s[i]];
            }
        }
        return total;
        
    }
};