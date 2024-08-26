#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x; cin >> n >> x;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    unordered_map<long long, int> prefix_sum_count;
    long long current_sum = 0;
    long long result = 0;
    prefix_sum_count[0] = 1;
    for (int i = 0; i < n; ++i) {
        current_sum += A[i];
        if (prefix_sum_count.find(current_sum - x) != prefix_sum_count.end()) {
            result += prefix_sum_count[current_sum - x];
        }
        prefix_sum_count[current_sum]++;
    }
    for(auto i : prefix_sum_count) {
        cout << i.first << " " << i.second << endl;
    }
    cout << result << endl;
    return 0;
}
