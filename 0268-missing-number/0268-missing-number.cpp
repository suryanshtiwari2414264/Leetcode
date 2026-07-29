class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum;
        int actual=0;
        int missing;
        sum=int{(n*(n+1)/2)};
        for(int i =0;i<n;i++){
            actual += nums[i];
        }
        
        return missing=sum-actual;

               
    }
};