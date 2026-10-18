class Solution {
    int sum(int x) {
        int r = 0;
        for (; x; r += x % 10, x /= 10)
        ;
        return r;
    }
    
public:
    int minSwaps(vector<int>& nums) {
        const int n = nums.size();
        vector<int> w(n), ind(n);
        for (int i = 0; i < n; ++i) {
            w[i] = sum(nums[i]);
            ind[i] = i;
        }
        sort(ind.begin(), ind.end(), [&](const int x, const int y) {
            return w[x] < w[y] || (w[x] == w[y] && nums[x] < nums[y]);
        });
        unordered_map<int, int> p;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            p[nums[i]] = i;
            v[i] = nums[ind[i]];
        }
        int r = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != v[i]) {
                p[nums[i]] = p[v[i]];
                nums[p[v[i]]] = nums[i];
                p[v[i]] = i;
                nums[i] = v[i];
                ++r;
            }
        }
        return r;     
    }
};