class Solution {

    private boolean ok(String s) {
        for (int i = 1; i < s.length(); ++i) {
            if (s.charAt(i) < s.charAt(i - 1)) {
                return false;
            }
        }
        return true;
    }

    public int minOperations(String s) {
        if (ok(s)) return 0;

        int n = s.length();
        if (n == 2) return -1;

        char m1 = s.charAt(0);
        char m2 = s.charAt(0);

        // Find min and max character
        for (int i = 1; i < n; ++i) {
            char c = s.charAt(i);
            if (c < m1) m1 = c;
            if (c > m2) m2 = c;
        }

        if (m1 == s.charAt(0) || m2 == s.charAt(n - 1)) return 1;

        for (int i = 0; i + 1 < n; ++i) {
            if (s.charAt(i) == m1) return 2;
        }

        for (int i = 1; i < n; ++i) {
            if (s.charAt(i) == m2) return 2;
        }

        return 3;
    }
}