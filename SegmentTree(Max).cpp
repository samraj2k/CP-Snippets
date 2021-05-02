class segTree {
public:
    vector<int> t;
    int n;
    segTree(int sz) {
        n = sz;
        t.resize(4 * n, 0);
    }
    void build(int v, int tl, int tr, int a[]) {
        if(tl == tr) {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm, a);
        build(2 * v + 1, tm + 1, tr, a);
        // merge here
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }
    int query(int v, int tl, int tr, int l, int r) {
        if(l > r) {
            // change as needed
            return -2e9;
        }
        if(tl == l and tr == r) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        // change as needed
        return max(query(2 * v, tl, tm, l, min(r, tm)), query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    void update(int v, int tl, int tr, int pos, int newVal) {
        if(pos > tr or pos < tl)
            return;
        if(tl == tr and tl == pos) {
            t[v] = newVal;
            return;
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(2 * v, tl, tm, pos, newVal);
            else
                update(2 * v + 1, tm + 1, tr, pos, newVal);
            // change as needed
            t[v] = max(t[2 * v] , t[2 * v + 1]);    
        }
        
    }
};
