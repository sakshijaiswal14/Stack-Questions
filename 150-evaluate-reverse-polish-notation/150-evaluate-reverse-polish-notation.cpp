class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            //if operator is found
            if(tokens[i]!= "+" && tokens[i]!= "-" && tokens[i]!= "*" 
               && tokens[i]!= "/")
            {
                st.push(stoi(tokens[i]));
            }
            else{
                char ch=tokens[i][0];
                int res;
                int b= st.top();
                st.pop();
                int a= st.top();
                st.pop();
                switch (ch)
                {
                    case '+':
                        res= a + b;
                        break;
                    case '-':
                        res= a - b;
                        break;
                    case '*':
                        res= a * b;
                        break;
                    case '/':
                        res= a / b;
                        break;
                }
                st.push(res);
            }
        }
        return st.top();
    }
};