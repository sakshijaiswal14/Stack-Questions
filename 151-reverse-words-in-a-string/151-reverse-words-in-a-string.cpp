class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word; //a variable to store word
        stringstream iss(s); // making a string stream
        while(iss>>word){
            st.push(word);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};