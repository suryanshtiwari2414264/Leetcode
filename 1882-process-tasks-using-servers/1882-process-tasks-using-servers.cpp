class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        set<pair<long long, int>> s;
        for (int i = 0; i < servers.size(); ++i) {
            s.insert({0LL, i});
        }
        const int m = tasks.size();
        for (int j = 0; j < m; ++j) {
            s.insert({j, INT_MAX});
        }
        vector<int> r(m, -1);
        set<pair<int, int>> ss;
        queue<int> tt;
        for (;r.back() < 0;) {
            const long long now = s.begin()->first;
            for (;!s.empty() && s.begin()->first == now; s.erase(s.begin())) {
                const int id = s.begin()->second;
                if (id == INT_MAX) {
                    tt.push(now);
                } else {
                    ss.insert({servers[id], id});
                }
            }
            while (!tt.empty() && !ss.empty()) {
                const int id = ss.begin()->second;
                r[tt.front()] = id;
                s.insert({now + tasks[tt.front()], id});
                tt.pop();
                ss.erase(ss.begin());

            }
        }
        return r;
    }
};