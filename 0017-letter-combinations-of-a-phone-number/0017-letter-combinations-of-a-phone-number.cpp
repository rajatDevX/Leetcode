class Solution {

   vector<string> mapping = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    vector<string>ans;
    void backtrack(string&digits,int index,string &current){
        if(index==digits.length()){
            ans.push_back(current);
            return;
        }
        char ch1=digits[index];

        string words=mapping[ch1-'0'];


        for(char word:words){
            current.push_back(word);

            backtrack(digits,index+1,current);

            current.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {

       if(digits.empty()){
        return {};
       }
        string current="";
        backtrack(digits,0,current);
        return ans;
    }
};