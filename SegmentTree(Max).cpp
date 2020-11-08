void build(int v, int tl, int tr,int a[], int t[]) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm, a, t);
        build(v*2+1, tm+1, tr, a, t);
        t[v] = max(t[v*2] , t[v*2+1]);
    }
}
int cal(int v, int tl, int tr, int l, int r, int t[]) {
    if (l > r) 
        return (int) -2e9;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(cal(v*2, tl, tm, l, min(r, tm), t), cal(v*2+1, tm+1, tr, max(l, tm+1), r, t));
}
void update(int v, int tl, int tr, int pos, int new_val, int t[]) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val, t);
        else
            update(v*2+1, tm+1, tr, pos, new_val, t);
        t[v] = max(t[v*2] , t[v*2+1]);
    }
}
