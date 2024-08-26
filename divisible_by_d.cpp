#include "bits/stdc++.h"
#define int long long

using namespace std;

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, d; cin >> n >> d;
    unordered_map<int, int> prefixCount;
    int prefixSum = 0;
    int count = 0;
    prefixCount[0] = 1;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        prefixSum += x;
        int remainder = prefixSum%d;
        if(remainder < 0) remainder += d;
        if(prefixCount.find(remainder) != prefixCount.end()){
            count += prefixCount[remainder];
        }
        prefixCount[remainder]++;
    }
    cout << count << endl;
    return 0;
}