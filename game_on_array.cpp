#include "bits/stdc++.h"

using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x; cin >> n;
    int ans = -2e9;
    int a[n+1];
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> x;
        a[i] = a[i-1] + x;
    }
    for(int i=1; i<=n; i++){
        ans = max({ans, a[i]*-1 + a[n]-a[i], a[i] + (a[n]-a[i])*-1});
    }
    cout << ans << endl;
    return 0;
}