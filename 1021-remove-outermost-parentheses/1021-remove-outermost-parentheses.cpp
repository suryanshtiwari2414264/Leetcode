class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        string ans = "";

        for (char ch : s) {

            if (ch == '(') {
                // Add only if it is NOT outermost
                if (depth > 0) {
                    ans += ch;
                }

                depth++;
            }

            else {
                // Decrease depth first
                depth--;

                // Add only if it is NOT outermost
                if (depth > 0) {
                    ans += ch;
                }
            }
        }

        return ans;
    }
};