class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p;
        vector<int> n;
        for(int num:nums){
            if(num>0)
                p.push_back(num);
            else
                n.push_back(num);
        }
        vector<int> ans;
        for(int i=0; i<p.size();i++){
            ans.push_back(p[i]);
            ans.push_back(n[i]);
        }
        return ans;
        
    }
};