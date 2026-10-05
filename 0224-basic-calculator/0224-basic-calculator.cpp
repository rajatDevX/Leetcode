class Solution {
public:
    int calculate(string s) {
         stack<long long> st;
        long long result = 0;
        long long number = 0;
        int sign = 1;
        for(char ch:s){
            if(ch>='0' && ch<='9'){
                number=number*10+(ch-'0');
            }
            else if(ch=='+' || ch=='-'){
                result+=sign*number;
                number=0;
                sign=(ch=='+')?1:-1;

            }
            else if(ch=='('){
                st.push(result);
                st.push(sign);

                // inside bracket fresh calculation
                result=0;
                number=0;
                sign=1;
            }
            else if(ch==')'){
                result+=sign*number;
                number=0;
                int outsideSign=st.top();
                st.pop();
                int outsideResult=st.top();
                st.pop();
                result = outsideResult + outsideSign * result;

            }
          
        }
          return result + sign * number;
    }
};