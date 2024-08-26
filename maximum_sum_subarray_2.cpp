#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long maxTwoSubArraysSum(vector<long long>& A) {
    int n = A.size();
    vector<long long> maxLeft(n), maxRight(n);
    long long currentMax = A[0];
    maxLeft[0] = A[0];
    for (int i = 1; i < n; i++) {
        currentMax = max(A[i], currentMax + A[i]);
        maxLeft[i] = max(maxLeft[i - 1], currentMax);
    }
    currentMax = A[n - 1];
    maxRight[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        currentMax = max(A[i], currentMax + A[i]);
        maxRight[i] = max(maxRight[i + 1], currentMax);
    }
    long long maxSum = LLONG_MIN;
    for (int i = 0; i < n - 1; i++) {
        maxSum = max(maxSum, maxLeft[i] + maxRight[i + 1]);
    }
    return maxSum;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<long long> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    cout << maxTwoSubArraysSum(A) << endl;
    return 0;
}
