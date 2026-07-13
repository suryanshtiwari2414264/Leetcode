class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> st;
       int n=height.size();
       int i;
       st.push(-1);
       int max_area=0;
       for(i=0;i<n;i++){
        while(st.top()!=-1 && height[st.top()]>= height[i]){
            int current=height[st.top()];
            st.pop();
            int width=i-st.top()-1;
            max_area= max(max_area,current*width);
        }
        st.push(i); //push the current shorter buliding 
       }
       // remaining building in the stack 
       while(st.top()!=-1){
        int current=height[st.top()];
        st.pop();
        int width =i-st.top()-1;
        max_area= max(max_area,current*width);
       }
        return max_area;
    }
};