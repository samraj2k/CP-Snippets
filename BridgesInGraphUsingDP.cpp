vector<vector<int>> g;
vector<int> dp, lvl;
int ans = 0, bridges = 0;
//bridges stores total number of bridges.
//dp[u] as the number of back-edges passing over the edge between u and its parent.
//dp[u]=(# of back-edges going up from u)−(# of back-edges going down from u)+∑dp[v] (v is a child of u).
//The edge between u and its parent is a bridge if and only if dp[u]=0.
void dfs(int v, int par){
	for(auto to: g[v]){
		if(to == par) continue;
		if(!lvl[to]){
			lvl[to] += lvl[v] + 1;
			dfs(to, v);
			dp[v] += dp[to];
		}
		else if(lvl[v] > lvl[to]) dp[v]++;
		else if(lvl[v] < lvl[to]) dp[v]--;
	}
	if (lvl[v] > 1 && !dp[v])
		bridges++;
}
