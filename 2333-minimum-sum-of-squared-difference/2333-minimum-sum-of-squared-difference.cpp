class Solution {
    long long mul(long long x, long long y) {
        return x * y;
    }
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        map<int, int> have;
        for (int i = 0; i < nums1.size(); ++i) {
            ++have[abs(nums1[i] - nums2[i])];
        }
        for (int i = k1 + k2; i; ) {
            auto t = have.rbegin();
            if (t->first == 0) {
                return 0;
            }
            const int d = min(t->second, i);
            i -= d;
            t->second -= d;
            have[t->first - 1] += d;
            if (t->second == 0) {
                have.erase(t->first);
            }
        }
        long long r = 0;
        for (const auto& p : have) {
            r += mul(mul(p.first, p.first), p.second);
        }
        return r;
    }
};