class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(),deadends.end());
        string start = "0000";
        if(dead.count(start))
            return -1;
        queue<string> q;
        unordered_set<string> visit;
        q.push(start);
        visit.insert(start);
        int turn=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string curr = q.front();
                q.pop();
                if(curr == target)
                    return turn;
                for(int i = 0; i<4; i++){
                    string nxt = curr;
                    nxt[i] = (curr[i]-'0'+1)%10 +'0';
                    if(!dead.count(nxt) && !visit.count(nxt)){
                        visit.insert(nxt);
                        q.push(nxt);
                    }
                    nxt = curr;
                    nxt[i] = (curr[i]-'0'+9)%10+'0';
                    if(!dead.count(nxt) && !visit.count(nxt)){
                        visit.insert(nxt);
                        q.push(nxt);
                    }
                }
            }
            turn++;
        }
        return -1;
    }
};