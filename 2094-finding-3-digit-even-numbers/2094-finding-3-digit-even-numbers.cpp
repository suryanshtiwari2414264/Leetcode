class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        int freq[10] = {};
        // Count frequency of each digit
        for(int d : digits) {
            freq[d]++;
        }
        // Choose hundreds digit
        for(int i = 1; i <= 9; i++) {
            if(freq[i] == 0)
                continue;
            freq[i]--;
            // Choose tens digit
            for(int j = 0; j <= 9; j++) {
                if(freq[j] == 0)
                    continue;
                freq[j]--;
                // Choose units digit
                for(int k = 0; k <= 8; k += 2) {
                    if(freq[k] == 0)
                        continue;
                    int num = i * 100 + j * 10 + k;
                    ans.push_back(num);
                }
                freq[j]++;
            }
            freq[i]++;
        }
        return ans;
    }
};