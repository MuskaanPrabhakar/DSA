class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && 
                tokens[i] != "*" && tokens[i] != "/") {
                
                st.push_back(stoi(tokens[i]));
            } 
            else {
                int a = st.back(); st.pop_back();
                int b = st.back(); st.pop_back();

                if (tokens[i] == "+") st.push_back(b + a);
                else if (tokens[i] == "-") st.push_back(b - a);
                else if (tokens[i] == "*") st.push_back(b * a);
                else st.push_back(b / a);
            }
        }

        return st.back();
    }
};
/*class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto &t : tokens) {
            if (t != "+" && t != "-" && t != "*" && t != "/") {
                st.push(stoi(t));
            } else {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();

                if (t == "+") st.push(b + a);
                else if (t == "-") st.push(b - a);
                else if (t == "*") st.push(b * a);
                else st.push(b / a);
            }
        }

        return st.top();
    }
};*/
