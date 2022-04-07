class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i=0; i<(int)s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i]== '{') st.push(s[i]);
            else {
                if (s[i] == ')') {
                    if (st.size() && st.top() == '(') st.pop();
                    else return false;
                }
                else if (s[i] == ']') {
                    if (st.size() && st.top() == '[') st.pop();
                    else return false;
                }
                else {
                    if (st.size() && st.top() == '{') st.pop();
                    else return false;
                }
            }
        }
        if (st.size()) return false;
        return true;
    }
};