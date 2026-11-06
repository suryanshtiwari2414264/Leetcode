// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         for (int i = 0; i < n - 2; i++) {
//             if (i > 0 && nums[i] == nums[i - 1])
//                 continue;
//             int left = i + 1;
//             int right = n - 1;
//             while (left < right) {
//                 long long sum = (long long)nums[i] + nums[left] +nums[right];
//                 if (sum == 0) {
//                     ans.push_back({nums[i],nums[left],nums[right]});
//                     left++;
//                     right--;
//                     while (left < right &&
//                            nums[left] == nums[left - 1])
//                         left++;
//                     while (left < right &&
//                            nums[right] == nums[right + 1])
//                         right--;
//                 }
//                 else if (sum < 0) {
//                     left++;
//                 }
//                 else {
//                     right--;
//                 }
//             }
//         }
//         return ans;
//     }
// };

//BRUTE FORCE
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums){
//         set<vector<int>>unique;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 for(int k = j+1;k<n;k++){
//                     if(nums[i]+nums[j]+nums[k]==0){
//                         vector<int> trip ={nums[i],nums[j],nums[k]};
//                         sort(trip.begin(),trip.end());
//                         unique.insert(trip);
//                     }
//                 }
//             }
//         }
//         vector<vector<int>>ans(unique.begin(),unique.end());
//         return ans;
//     }
// };

// SEMI OPTIMIZED APPROACH O(n^2 log(n))
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         set<vector<int>>uniquetrip;
//         for(int i = 0; i<n;i++){
//             set<int>s;
//             for(int j=i+1;j<n;j++){
//                 int third = 0-nums[i]-nums[j];
//                 if(s.find(third)!= s.end()){
//                     vector<int>trip ={nums[i],nums[j],third};
//                     sort(trip.begin(),trip.end());
//                     uniquetrip.insert(trip);
//                 }
//                 s.insert(nums[j]);
//             }
//         }
//         vector<vector<int>>ans(uniquetrip.begin(),uniquetrip.end());
//         return ans;
//     }
// };

// OPTIMEZED PRESORTING AND TWO POINTER O(N^2)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>uniquetrip;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<n;i++){
            int l = i+1;
            int h = n-1;
            while(l<h){
                if(nums[i]+nums[l]+nums[h]==0){
                    vector<int> trip ={nums[i],nums[l],nums[h]};
                    sort(trip.begin(),trip.end());
                    uniquetrip.insert(trip);
                    l++;
                    h--;
                }
                else if(nums[i]+nums[l]+nums[h]<0){
                    l++;
                }
                else
                    h--;
            }
        }
        vector<vector<int>>ans(uniquetrip.begin(),uniquetrip.end());
        return ans;
    }
};