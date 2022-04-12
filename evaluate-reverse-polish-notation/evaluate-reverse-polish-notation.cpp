class Solution {
public:
    stack<int> st;
    int evalRPN(vector<string>& tokens) {
        for (int i=0; i<tokens.size(); i++) {
            if (tokens[i] == "+") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a+b);
            }
            else if (tokens[i] == "-") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a-b);
            }
            else if (tokens[i] == "*") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a*b);
            }
            else if (tokens[i] == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a/b);
            }
            else st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};