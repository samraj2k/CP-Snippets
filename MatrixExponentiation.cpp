#define mod 1000000007    
const int NN = 101;
class matrix {
public:
    int mat[NN][NN];
    int r, c;
    matrix() {
        for(int i = 0; i < NN; i++){
            for(int j = 0; j < NN; j++){
                mat[i][j] = 0;
            }
        }
    }
    void setsize(int _r, int _c) {
        r = _r, c = _c;
    }
    inline matrix operator * (const matrix & a) {
        assert(c == a.r);
        matrix temp;
        temp.setsize(r, a.c);
        for(int i = 0; i < r; i++){
            for(int j = 0; j < a.c; j++) {
                for(int k = 0; k < a.r; k++) {
                    temp.mat[i][j] += (mat[i][k] * a.mat[k][j]) % mod;
                    if (temp.mat[i][j] >= mod)
                        temp.mat[i][j] -= mod;
                }
            }
        }
        return temp;
    }
    inline matrix operator + (const matrix & a) {
        assert(r == a.r && c == a.c);
        matrix temp;
        temp.setsize(r, c);
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                temp.mat[i][j] = mat[i][j] + a.mat[i][j];
                if (temp.mat[i][j] >= mod)
                    temp.mat[i][j] -= mod;
            } 
        }
        return temp;
    }
    inline matrix operator - (const matrix & a) {
        assert(r == a.r && c == a.c);
        matrix temp;
        temp.setsize(r, c);
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                temp.mat[i][j] = mat[i][j] - a.mat[i][j];
                if (temp.mat[i][j] < 0)
                    temp.mat[i][j] += mod;
            }    
        }
        return temp;
    }
    inline void operator = (const matrix & a) {
        for(int i = 0; i < a.r; i++)
            for(int j = 0; j < a.c; j++)
                mat[i][j] = a.mat[i][j];
        r = a.r, c = a.c;
    }
};

matrix pow(matrix a, int k) {
    assert(a.r == a.c);
    matrix ans;
    for(int i = 0; i < a.r; i++)
        ans.mat[i][i] = 1;
    ans.r = a.r;
    ans.c = a.r;
    while (k) {
        if (k & 1)
            ans = ans * a;
        a = a * a;
        k >>= 1;
    }
    return ans;
}
