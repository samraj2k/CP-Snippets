pair<pair<int, int>, int> give(int x1, int y1, int x2, int y2){
    int a = y1 - y2;
    int b = x1 - x2;
    int hcf = __gcd(abs(a), abs(b));
    a /= hcf;
    b /= hcf;
    if(a < 0 or (a == 0 and b < 0)){
        a *= -1;
        b *= -1;
    }
    return {{a, b}, a * x1 - b * y1};
}
