class Solution {
public:
    int schedule[1010101]{ 0 };
    
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26, 0);
        for (int i=0; i<tasks.size(); i++) {
            v[tasks[i]-'A']++;
        }
        sort(v.rbegin(), v.rend());
        int rest = (v[0]-1)*n;
        for (int i=1; i<v.size(); i++) {
            rest -= min(v[0]-1, v[i]);
        }
        if (rest < 0) return tasks.size();
        return tasks.size() + rest;
    }
};