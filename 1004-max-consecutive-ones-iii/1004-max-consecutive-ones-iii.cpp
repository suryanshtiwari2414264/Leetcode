class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int i=0;
        int j=-1;
        int count=0;
        while(i<nums.size()){
            if(nums[i]==0){
                count++;
                i++;
            }
            else{
                i++;
            }
            while(count>k){
                j++;
                if(nums[j]==0){
                    count--;
                }
            }
            int size=i-1-j;
            ans=max(ans,size);
        }

        return ans;
    }
};