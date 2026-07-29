//ASSIGNING 0 TO THE VALUES;
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int n=nums.size();
//         int i=0;
//         int j=0;
//         while(i<n){
//             if(nums[i]!=0){
//                 nums[j]=nums[i];
//                 j++;
//             }
//             i++;
//         }
//         while(j<n){
//             nums[j]=0;
//             j++;
//         }
//     }
// };

// BY USING SWAPPING METHOD
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int j = 0;   

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};