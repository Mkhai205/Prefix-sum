#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countSubarraysWithAverageK(vector<long long>& A, int n, int k) {
    vector<long long> B(n);
    for (int i = 0; i < n; ++i) B[i] = A[i] - k;
    unordered_map<int, int> prefixSumCount;
    long long count = 0, currentSum = 0;
    prefixSumCount[0] = 1;
    for (int i = 0; i < n; i++) {
        currentSum += B[i];
        if (prefixSumCount.find(currentSum) != prefixSumCount.end()) {
            count += prefixSumCount[currentSum];
        }
        prefixSumCount[currentSum]++;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, k; cin >> n >> k;
    vector<long long> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    cout << countSubarraysWithAverageK(A, n, k) << endl;
    return 0;
}
