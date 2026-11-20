class Solution {
    public int calPoints(String[] operations) {
        Stack<Integer>st=new Stack<>();
        for(int i=0;i<operations.length;i++){
            String op=operations[i];
            if(op.equals("C")){
                st.pop();
            }
            else if(op.equals("D")){
                int top=st.peek();
                st.push(top*2);
            }
            else if(op.equals("+")){
                int top1=st.pop();
                int top2=st.peek();
                st.push(top1);
                st.push(top1+top2);
            }
            else{
                st.push(Integer.parseInt(op));
            }
        }

        int sum=0;
        while(!st.empty()){
            sum+=st.pop();
        }
        return sum;
    }
}