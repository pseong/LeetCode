class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>());
        
        for (vector<int>& v : prerequisites) {
            adj[v[1]].push_back(v[0]);
            in[v[0]]++;
        }
        
        queue<int> q;
        for (int i=0; i<numCourses; i++) {
            if (in[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        while (q.size()) {
            int x = q.front(); q.pop();
            ans.push_back(x);
            for (int y : adj[x]) {
                in[y]--;
                if (!in[y]) q.push(y);
            }
        }
        if (ans.size() == numCourses) {
            return ans;
        }
        else return {};
    }
};