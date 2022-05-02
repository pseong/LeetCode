class Solution {
public:
    int schedule[1010101]{ 0 };
    
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26, 0);
        for (int i=0; i<tasks.size(); i++) {
            v[tasks[i]-'A']++;
        }
        sort(v.rbegin(), v.rend());
        int sum = 0;
        int cnt = 1;
        for (int i=1; i<25; i++) {
            sum += min(v[0]-1, v[i]);
            if (v[i] == v[0]) cnt++;
        }
        int buket = n*(v[0]-1);
        if (sum >= buket) {
            return tasks.size();
        }
        else {
            return (n+1)*(v[0]-1) + cnt;
        }
    }
};