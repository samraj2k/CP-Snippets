// Returns LIS (Strictly)
// The vector does not contain the correct sequence.
// Change lower_bound to upper_bound to calculate LNDS
vector<int> lis;
for (int i = 0; i < n; i++) {
    auto it = lower_bound(lis.begin(), lis.end(), a[i]);
    if (it != lis.end()) *it = a[i];
    else lis.push_back(a[i]);
}
return (int) lis.size();
