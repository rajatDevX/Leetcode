class Solution {
public:
    vector<string>mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>ans;
    void backtrack(string &digits,int index,string &current){
        if(index==digits.length()){
            ans.push_back(current);
            return ;
        }
        char digit=digits[index];
        string letters=mapping[digit-'0'];
        for(char ch:letters){
            current.push_back(ch);
            backtrack(digits,index+1,current);
            current.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        string current="";
        backtrack(digits,0,current);
        return ans;
    }
};