#define int long long
const int mod = 1e9 + 9, pw = 31;

struct hsh_str {
	vector<int> h, p;
	hsh_str(string s) {
		int n = s.size();
		h.resize(n), p.resize(n);
		h[0] = s[0] - 'a' + 1, p[0] = 1;
		for (int i = 1; i < n; ++i) {
			h[i] = ((h[i - 1] * pw) % mod + (s[i] - 'a' + 1)) % mod;
			p[i] = (p[i - 1] * pw) % mod;
		}
	}
	int get(int l, int r) {
		int res = h[r];
		if (l > 0) res -= (h[l - 1] * p[r - l + 1]) % mod;
		if (res < 0) res += mod;
		return res;
	}
	int all() {
		return h[(int)h.size() - 1];
	}
};
