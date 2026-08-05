class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3]={0};
        int idx=0;
        for(int num:nums){
            count[num]++;
        }
        while(count[0]--){
            nums[idx++]=0;
        }
        while(count[1]--){
            nums[idx++]=1;
        }
        while(count[2]--){
            nums[idx++]=2;
        }

    }    
};