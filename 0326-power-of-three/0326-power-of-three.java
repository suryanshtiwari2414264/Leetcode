//First Approach
// class Solution {
//     public boolean isPowerOfThree(int n) {
//         if(n<=0)
//             return false;
//         while(n%3==0)
//             n=n/3;
//         return n==1;
//     }
// }
// RECURSIVE APPROACH
class Solution{
    public boolean isPowerOfThree(int n) {
        if(n<=0)
            return false;
        return((n==1) || (n%3==0 && isPowerOfThree(n/3)));
    }

}