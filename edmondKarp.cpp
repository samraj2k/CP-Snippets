#define inf 1e18     
using namespace std;
vector<vector<int>> g;
vector<vector<int>> capacity;
int n;
int bfs(int s, int t, vector<int> parent){
	parent[s] = -2;
	queue<array <int, 2>> q;
	q.push({s, inf});
	while(!q.empty()){
		int v = q.front()[0];
		int flow = q.front()[1];
		q.pop();
		for(auto to: g[v]){
			int newFlow = min(flow, capacity[v][to]);
			if(!newFlow or parent[to] != -1)
				continue;
			parent[to] = v;
			if(to == t)
				return newFlow;
			q.push({to, newFlow});
		}
	}
	return 0;
}
int edmondKarp(int s, int t){
	int flow = 0,curFlow = 0;
	vector<int> parent(n + 1, -1);
	while(curFlow = bfs(s, t, parent)){
		flow += curFlow;
		int par = t;
		while(par != s){
			capacity[parent[par]][par] -= curFlow;
			capacity[par][parent[par]] += curFlow;
			par = parent[par];
		}
	}
	return flow;
}
