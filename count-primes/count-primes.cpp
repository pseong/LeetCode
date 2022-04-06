class Solution {
public:
    int countPrimes(int n) {
        if (n==0) return 0;
        vector<bool> prime(n, true);
        prime[0] = false;
        prime[1] = false;
        for (int i=0; i*i<n; i++) {
            if (prime[i]) {
                for (int j=i*i; j<n; j+=i) {
                    prime[j] = 0;
                }
            }
        }
        return count(prime.begin(), prime.end(), true);
    }
};