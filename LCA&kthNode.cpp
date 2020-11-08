#include<bits/stdc++.h>	
#define int long long int
#define pb push_back
#define F first
#define S second     
using namespace std;
const int N = 3e5 + 5;
const int up = 21;
int level[N];
int lca[N][up];
vector<int> g[N];
void fill(){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < up; j++)
			lca[i][j] = 1;
}
void dfs(int v, int par, int depth = 0){
	level[v] = depth;
	for(auto to: g[v]){
		if(to == par)
			continue;
		dfs(to, v, depth + 1);
	}
}
void build(int v, int par){
	lca[v][0] = par;
	for(int i = 1; i < up; i++){
		lca[v][i] = lca[lca[v][i - 1]][i - 1];
	}
	for(auto to: g[v]){
		if(to == par)
			continue;
		build(to, v);
	}
}
int retlca(int a, int b){
	if(level[a] > level[b])
		swap(a, b);
	int lev_diff = level[b] - level[a];
	for(int i = up - 1; i >= 0; i--){
		if(!(lev_diff & (1 << i)))
			continue;
		b = lca[b][i];
	}
	if(a == b)
		return a;
	for(int i = up - 1; i >= 0; i--){
		if(lca[a][i] == lca[b][i])
			continue;
		a = lca[a][i];
		b = lca[b][i];
	}
	return lca[a][0];
}
int kth_node(int v, int k){
	for(int i = up - 1; i >= 0; i--){
		if(!(k & (1 << i)))
			continue;
		v = lca[v][i];
	}
	return v;
}
