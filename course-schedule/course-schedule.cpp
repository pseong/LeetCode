class Solution {
public:    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>());
        
        for (vector<int>& v : prerequisites) {
            adj[v[0]].push_back(v[1]);
            in[v[1]]++;
        }
        
        queue<int> q;
        for (int i=0; i<numCourses; i++) {
            if (in[i] == 0) q.push(i);
        }
        
        int cnt = 0;
        while (q.size()) {
            cnt++;
            int x = q.front(); q.pop();
            for (int y : adj[x]) {
                in[y]--;
                if (!in[y]) q.push(y);
            }
        }
        
        if (cnt != numCourses) return false;
        return true;
    }
};