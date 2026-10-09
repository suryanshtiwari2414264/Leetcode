class Solution {
public:
    int minInsertions(string s) {
        int r = 0, d = 0;
        for (int i = 0; i < s.length(); ) {
            for (; i < s.length() && s[i] == '('; ++d, ++i)
            ;
            int t = 0;
            for (; i < s.length() && s[i] == ')'; ++t, ++i)
            ;
            r += t & 1;
            d -= (t + 1) >> 1;
            if (d < 0) {
                r -= d;
                d = 0;
            }
        }
        return r + d * 2;
    }
};