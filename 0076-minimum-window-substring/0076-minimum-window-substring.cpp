class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        if(t.length()>n)
        return "";
        unordered_map<char,int> mp;
        for(char& ch:t){
            mp[ch]++;
        }
        int req=t.length();
        int i=0,j=0;
        int minwindow=INT_MAX;
        int start=0;
        while(j<n){
            char ch=s[j];
            if(mp[ch]>0){
                req--;
            }
            mp[ch]--;
            while(req==0){
                int curr=j-i+1;
                if(minwindow>curr){
                    minwindow=curr;
                    start=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    req++;
                }
                i++;
            }
            j++;
        }
        return minwindow==INT_MAX ? "": s.substr(start,minwindow);
    }
};