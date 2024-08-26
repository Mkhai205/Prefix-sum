#include "bits/stdc++.h"
#define int long long

using namespace std;

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin >> n >> q;
    int a[n+1], b[n+1]; a[0] = 0; b[0] = 0;
    for(int i = 1; i<=n; i++){
        int x; cin >> x;
        a[i] = a[i-1] + x;
        b[i] = b[i-1] + i*x;
    }
    while(q--){
        int l, r; cin >> l >> r; l--, r--;
        if(l == 0) cout << b[r+1] << '\n';
        else cout << b[r+1] - b[l] - l*(a[r+1] - a[l]) << '\n';
    }
    return 0;
}
