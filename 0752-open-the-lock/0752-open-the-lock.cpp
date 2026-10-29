// class Solution {
// public:
//     int openLock(vector<string>& deadends, string target) {
//         unordered_set<string> dead(deadends.begin(),deadends.end());
//         string start = "0000";
//         if(dead.count(start))
//             return -1;
//         queue<string> q;
//         unordered_set<string> visit;
//         q.push(start);
//         visit.insert(start);
//         int turn=0;
//         while(!q.empty()){
//             int size=q.size();
//             while(size--){
//                 string curr = q.front();
//                 q.pop();
//                 if(curr == target)
//                     return turn;
//                 for(int i = 0; i<4; i++){
//                     string nxt = curr;
//                     nxt[i] = (curr[i]-'0'+1)%10 +'0';
//                     if(!dead.count(nxt) && !visit.count(nxt)){
//                         visit.insert(nxt);
//                         q.push(nxt);
//                     }
//                     nxt = curr;
//                     nxt[i] = (curr[i]-'0'+9)%10+'0';
//                     if(!dead.count(nxt) && !visit.count(nxt)){
//                         visit.insert(nxt);
//                         q.push(nxt);
//                     }
//                 }
//             }
//             turn++;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int openLock(vector<string>& deadends, string target){
        unordered_map<char,char> nextslot={{'0','1'},{'1','2'},{'2','3'},{'3','4'},{'4','5'},{'5','6'},{'6','7'},{'7','8'},{'8','9'},{'9','0'}};
        unordered_map<char,char> prevslot={{'0','9'},{'1','0'},{'2','1'},{'3','2'},{'4','3'},{'5','4'},{'6','5'},{'7','6'},{'8','7'},{'9','8'}};
        unordered_set<string> visited(deadends.begin(),deadends.end());//sari deadends ki string visited me aa gyi
        queue<string> q;
        int turn = 0;
        if(visited.find("0000")!= visited.end())//edge case
            return -1;
        q.push("0000");
        visited.insert("0000");
        while(!q.empty()){
            int lvl_size= q.size();
            while(lvl_size--){
                string curr = q.front();
                q.pop();
                if(curr== target)
                    return turn;
                // if(visited.find(curr)!=visited.end())
                    // continue;
                for(int i=0;i<4;i++)
                {
                    string newcomb = curr;
                    newcomb[i]=nextslot[newcomb[i]];
                    if(visited.find(newcomb)==visited.end())
                    {
                        q.push(newcomb);
                        visited.insert(newcomb);
                    }
                    newcomb = curr;
                    newcomb[i]=prevslot[newcomb[i]];
                    if(visited.find(newcomb)==visited.end())
                    {
                        q.push(newcomb);
                        visited.insert(newcomb);
                    }
                } 
            }
            turn++;            
        }
        return -1;
    }
};