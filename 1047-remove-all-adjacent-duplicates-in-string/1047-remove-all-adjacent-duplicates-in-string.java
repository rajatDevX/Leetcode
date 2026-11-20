class Solution {
    public String removeDuplicates(String s) {
        Stack<Character>st=new Stack<>();
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            if(!st.empty()&&st.peek()==ch){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        StringBuilder result=new StringBuilder();
        while(!st.empty()){
            result.append(st.pop());
        }
        return result.reverse().toString();
    }
}