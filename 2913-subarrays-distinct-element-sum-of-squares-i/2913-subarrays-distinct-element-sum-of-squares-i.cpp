class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int r =0;
        for(int i =0;i<n;i++){
            unordered_set<int>s;
            for(int j = i ; j<n;j++){
                s.insert(nums[j]);
                r += s.size() * s.size();
            }
        }
        return r;
        
    }
};