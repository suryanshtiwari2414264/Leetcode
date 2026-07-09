// BRUTE FORCE
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         int water = 0;
//         if(n==0){
//             return 0;
//         }

//         for (int i = 0; i < n; i++) {
//             int leftMax = 0, rightMax = 0;

//             // Find max on left
//             for (int j = 0; j <= i; j++) {
//                 leftMax = max(leftMax, height[j]);
//             }

//             // Find max on right
//             for (int j = i; j < n; j++) {
//                 rightMax = max(rightMax, height[j]);
//             }
//             if(height[i]<leftMax && height[i]<rightMax){

//             water += min(leftMax, rightMax) - height[i];
            
//             }
//         }

//         return water;
//     }
// };
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int left = 0, right = height.size() - 1;
//         int leftMax = 0, rightMax = 0;
//         int water = 0;

//         while (left < right) {
//             if (height[left] < height[right]) {
//                 if (height[left] >= leftMax)
//                     leftMax = height[left];
//                 else
//                     water += leftMax - height[left];
//                 left++;
//             } else {
//                 if (height[right] >= rightMax)
//                     rightMax = height[right];
//                 else
//                     water += rightMax - height[right];
//                 right--;
//             }
//         }
//         return water;
//     }
// };
class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        if(n == 0)
            return 0;

        vector<int> Lmax(n), Rmax(n);

        Lmax[0] = height[0];
        for(int i = 1; i < n; i++) {
            Lmax[i] = max(Lmax[i - 1], height[i]);
        }

        Rmax[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            Rmax[i] = max(Rmax[i + 1], height[i]);
        }

        int ans = 0;

        for(int i = 1; i < n - 1; i++) {
            ans += min(Lmax[i], Rmax[i]) - height[i];
        }

        return ans;
    }
};