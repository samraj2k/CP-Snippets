#define mod 1000000007
const int mx = 2e5 + 5;
int fact[mx], invfact[mx], inv[mx];
//fact[] = n % mod;
//invfact[] = (1 / n!) % mod;
//inv[] = (1 / n) % mod
//cal_fact = Call in main function pre-comp
//nck = nCr
int pow(int x, int y){          
    int res = 1;
    x %= mod;
    while(y){
        if(y & 1) res *= x;
        x *= x;
        x %= mod;
        res %= mod;
        y /= 2;
    }
    return res;
}
int modinv(int num){              
   return powm(num, mod - 2);
}
void cal_fact(){                 
   fact[0] = 1;
    for(int i = 1; i < mx; i++){
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }
    inv[1] = 1;
    for(int i = 2; i < mx; i++)
        inv[i] = (mod - (mod / i) * inv[mod % i]) % mod;
    invfact[mx - 1] = modinv(fact[mx - 1]);
    for(int i = mx - 2; i >= 0; i--){
        invfact[i] = invfact[i + 1] * (i + 1);
        invfact[i] %= mod; 
   }
}
int nck(int n, int k){
    if(n < k)
        return 0;
    int temp = 0;
    temp = fact[n];
    temp %= mod;
    temp *= invfact[k];
    temp %= mod;
    temp *= invfact[n - k];
    return temp % mod;
}
