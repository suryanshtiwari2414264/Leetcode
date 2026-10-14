class Solution {
    public String maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";  // impossible to form such number

        StringBuilder res = new StringBuilder();
        for (int i = 0; i < num; i++) {
            int digit = Math.min(9, sum);  // choose the largest possible digit
            res.append(digit);              // append as character
            sum -= digit;
        }
        return res.toString();
    }
}