class Solution
 {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2)
     {  
        // if(num1.empty()&&num2.empty())
        // {
        //     return 0;
        // }
         num1.insert(num1.end(), num2.begin(), num2.end());
         sort(num1.begin(), num1.end());
    //      for(int i = 1; i < num1.size(); i++) {
    //     if(num1[i] == num1[i-1]) {
    //     cout << "Duplicate element: " << num1[i] << endl;
    // }

        int n=num1.size();
        if(n%2==0){
           return (num1[n/2 - 1] + num1[n/2]) / 2.0;
        }
        else
        {
            return num1[n/2];
        }
        // if(num1.size()>num2.size()){
            
        //     return num1.back();
        // }
        // else if(num1.size()< num2.size()){
        //     return num2.front();
        // }
        // else{
        //     return (num1.back()+num2.front())/2;
        // }
        return 0;
    }
};