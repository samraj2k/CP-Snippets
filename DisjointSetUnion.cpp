class dsu {
public:
    int n;
    vector<int> par, siz; 
    dsu(int sz) {
        n = sz;
        par.resize(n + 1);
        siz.resize(n + 1, 1);
        iota(par.begin(), par.end(), 0);
    }
    int findPar(int v) {
        if(v == par[v])
            return v;
        return par[v] = findPar(par[v]);
    }
    bool unionSet(int u, int v) {
        int parU = findPar(u);
        int parV = findPar(v);
        if(parU == parV)
            return false;
        if (siz[parU] < siz[parV])
            swap(parU, parV);
        par[parV] = parU;
        siz[parU] += siz[parV];
        return true;
    }
};
