const int N = 2e5 + 5;
vector<pair<int, int>> g[N];
vector<int> dijkstra(int s, int n){
    vector<int> dist(n + 1, inf);
    vector<bool> visit(n + 1, false);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        auto cur = pq.top();
        int d = cur.F, v = cur.S;
        pq.pop();
        if(visit[v])
            continue;
        visit[v] = true;
        for(auto &to: g[v]){
            if(d + to.F < dist[to.S]){
                dist[to.S] = d + to.F;
                pq.push({dist[to.S], to.S});
            }
        }
    }
    return dist;
}
