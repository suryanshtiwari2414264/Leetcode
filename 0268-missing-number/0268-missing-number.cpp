class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int expected=0;
        int actual=0;
        for(int i=0;i<=n;i++){
            expected ^= i;
        }
        for(int num:nums){
            actual ^=num;
        }
        return expected ^ actual;
    }
};