// BRUTE FORCE

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int i=0,j=0;
//         vector<int> a;
//         while(i<m && j<n)
//         {
//             if(nums1[i]<=nums2[j]){
//                 a.push_back(nums1[i]);
//                 i++;
               

//             }
//             else{
//                 a.push_back(nums2[j]);
                
//                 j++;
//             }
//             // else{
//             //     a.push_back(nums2[j]);
//             //     a.push_back(nums1[i]);
//             //     i++;
//             //     j++;
//             // }
//         }
//         while(i<m){
//            a.push_back(nums1[i]);
            
//             i++;
//         }
//         while(j<n){
//            a.push_back(nums2[j]);
            
//             j++;
//         }
//           for(int k = 0; k < m + n; k++)
//         {
//             nums1[k] = a[k];
//         }
        
//     }
// };

// OPTIMAL SOLUTION 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k--] = nums1[i--];
            }
            else
                nums1[k--] = nums2[j--];


        }
        while(j>=0){
            nums1[k--]=nums2[j--];
        }
            }
 };
