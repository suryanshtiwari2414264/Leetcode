class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        int ans = Integer.MAX_VALUE;

        // Case 1: rotation of [0,1,2,...]
        boolean ok = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (nums[0] + i) % n) {
                ok = false;
                break;
            }
        }

        if (ok) {
            int cost1 = (n - nums[0]) % n;      // left rotate only
            int cost2 = nums[0] + 2;           // reverse -> rotate -> reverse

            ans = Math.min(ans, Math.min(cost1, cost2));
        }

        // Case 2: rotation of reversed [n-1,...,0]
        ok = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (nums[0] - i + n) % n) {
                ok = false;
                break;
            }
        }

        if (ok) {
            int cost3 = 1 + (n - nums[n - 1]) % n; // reverse -> rotate
            int cost4 = 1 + nums[n - 1];           // rotate -> reverse

            ans = Math.min(ans, Math.min(cost3, cost4));
        }

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}