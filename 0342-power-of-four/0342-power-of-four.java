// Iterative Approach
// class Solution {
//     public boolean isPowerOfFour(int n) {
//         if(n<=0)
//              return false;
//          while(n%4==0)
//              n = n/4;
//         return n==1;
        
//     }
// }

// Recursive Approach
class Solution{
    public boolean isPowerOfFour(int n) {
         if(n<=0)
            return false;
        return((n==1) || (n%4==0 && isPowerOfFour(n/4)));
    }

}