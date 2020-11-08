const int N = 2e5 + 5;
vector<vector<int>> g;
int dp1[N];
int dp2[N];
void dfs1(int v, int par){
    dp1[v] = 0;
    for(auto to: g[v]){
        if(to == par)
            continue;
        dfs1(to, v);
        dp1[v] = max(dp1[v], dp1[to] + 1);
    }
}
void dfs2(int v, int par){
    int mx1 = -1, mx2 = -1;
    for(auto to: g[v]){
        if(to == par)
            continue;
        if(dp1[to] >= mx1){
            swap(mx2, mx1);
            mx1 = dp1[to];
        }
        else if(dp1[to] > mx2){
            mx2 = dp1[to];
        }
    }
    for(auto to: g[v]){
        if(to == par)
            continue;
        int longest = mx1;
        if(mx1 == dp1[to])
            longest = mx2;
        dp2[to] = 1 + max(dp2[v], 1 + longest);
        dfs2(to, v);
    }
}
