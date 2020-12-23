// Type = 0 means Longest Non-decreasing subsequence
// Type = 1 means Longest Increasing Subsequene
// a must be 0 based indexing
// solution vector stores the restored subsequence
int lis(vector<int> a, vector<int> &solution, int type = 0) {
    int MAX_INF = 3e18;
    int n = (int) a.size(), ans = 0;
    vector<int> b(n + 1, 0), f(n + 1, MAX_INF);
    for(int i = 0; i < n; i++) {
        if(!type)
            f[i + 1] = upper_bound(b.begin() + 1, b.begin() + ans + 1, a[i]) - b.begin();
        else 
            f[i + 1] = lower_bound(b.begin() + 1, b.begin() + ans + 1, a[i]) - b.begin();
        ans = max(ans, f[i + 1]);
        b[f[i + 1]] = a[i];
    }
    int req = ans;
    for(int i = n; i >= 1; i--) {
        if(f[i] == req) {
            solution.push_back(a[i - 1]);
            req--;
        }
    }
    reverse(solution.begin(), solution.end());
    return ans;
}
