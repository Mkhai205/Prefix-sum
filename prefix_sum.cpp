#include "bits/stdc++.h"

using namespace std;

int main(){
    int n, x, q; cin >> n >> q;
    long long a[n+1];
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> x;
        a[i] = a[i-1] + x;
    }
    while(q--){
        int l, r; cin >> l >> r;
        cout << a[r] - a[l-1] << endl;
    }
    return 0;
}