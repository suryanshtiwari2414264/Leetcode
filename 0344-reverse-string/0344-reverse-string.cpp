class Solution {
public:

    void reverseString(int i, int j, vector<char>& s) {

        if(i >= j)
            return;

        swap(s[i], s[j]);

        reverseString(i + 1, j - 1, s);
    }

    void reverseString(vector<char>& s) {

        reverseString(0, s.size() - 1, s);
    }
};