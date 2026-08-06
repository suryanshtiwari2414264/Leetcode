// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums)
//     {
//     int n=nums.size();
//      sort(nums.begin(),nums.end());
//      if(n==0){
//         return false;
//      }
//      for(int i = 0;i<n-1;i++)
//      {
//         if(nums[i]==nums[i+1])
//         {
//             return true;
//         }
//      }
//      return false; 
//     }
// };

//AVL TREE
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        set<int> st;

        for(int num : nums){

            if(st.find(num) != st.end())
                return true;

            st.insert(num);
        }

        return false;
    }
};