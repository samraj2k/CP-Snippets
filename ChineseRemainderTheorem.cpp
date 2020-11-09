//Works for Non Coprime Moduli also
//Nlog(LCM) complexity
//Overflow may occur
int ext_gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
pair<int, int> chinese_remainder_theorem(vector<int> A, vector<int> M) {
    if(A.size() != M.size()) 
        return {-1, -1}; //Invalid input
    int n = A.size();
    int a1 = A[0];
    int m1 = M[0];
    for (int i = 1; i < n; i++) {
        int a2 = A[i];
        int m2 = M[i];
        int g = __gcd(m1, m2);
        if (a1 % g != a2 % g)
            return {-1, -1};
        int p, q;
        ext_gcd(m1 / g, m2 / g, p, q);
        int md = m1 / g * m2;
        int x = (a1 * (m2 / g) * q + a2 * (m1 / g) * p) % md;
        a1 = x;
        if (a1 < 0) a1 += md;
        m1 = md;
    }
    return {a1, m1};
}
