#include "bits/stdc++.h"

using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x; cin >> n;
    long long max_sum = LLONG_MIN, sum = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        sum += x;
        max_sum = max(max_sum, sum);
        if(sum < 0) sum = 0;
    }
    cout << max_sum << endl;
    return 0;
}