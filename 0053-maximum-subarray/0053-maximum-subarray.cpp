// BRUTE FORCE
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int maxsum=INT_MIN;
//         int n= nums.size();
//         for(int i=0;i<n;i++){
//             int sum =0;
//             for(int j=i;j<n;j++){
//                 sum += nums[j];
//                 maxsum=max(maxsum,sum);
//             }
//         }
//         return maxsum;
//     }
// };


// WE WILL GET TLE FOR THE BRUTE FORCE 
// NOW KADANE'S ALGO
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0;
        int maxsum=INT_MIN;
        for(int num:nums){
            currsum += num;
            maxsum=max(maxsum,currsum);
            if(currsum<0)
                currsum=0;
        }
        return maxsum;
        
    }
};