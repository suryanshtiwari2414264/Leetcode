// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(),nums.end());
//         int missing =-1;
//         int duplicate =-1;
//         for(int i = 1;i<n;i++){
//             if(nums[i]==nums[i-1]){
//                  duplicate = nums[i];
//                  break;
//             }
//         }
//         for(int i = 1; i<=n;i++){
//             if(i != nums[i-1]){
//                 missing= i;
//                 break;
//             }
//         }
//         if(missing ==-1)
//             missing = n;
//         return {duplicate, missing};
//     }
// };


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int duplicate = -1;
        int missing = -1;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] == nums[i-1])
            {
                duplicate = nums[i];
                break;
            }
        }
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
        for(int x : nums)
        {
            actualSum += x;
        }
        missing = expectedSum - (actualSum - duplicate);
        return {duplicate, missing};
    }
};