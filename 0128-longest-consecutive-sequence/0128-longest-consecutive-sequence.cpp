class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        unordered_set<int> st;
        for (int num : nums){
            st.insert(num);
            }
        int longest = 0;
        for(int num:st){
            if (st.find(num - 1) == st.end()) {
                int curr = num;
                int len = 1;
                while (st.find(curr + 1) != st.end()) 
                {
                    curr++;
                    len++;
                }
                longest = max(longest, len);
            }
        }
        return longest;
    }
};