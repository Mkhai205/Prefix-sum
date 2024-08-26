#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<long long> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    vector<long long> leftMax(n);
    long long currentSum = A[0];
    leftMax[0] = A[0];
    for (int i = 1; i < n; i++) {
        currentSum = max(A[i], currentSum + A[i]);
        leftMax[i] = max(leftMax[i - 1], currentSum);
    }
    vector<long long> rightMax(n);
    currentSum = A[n - 1];
    rightMax[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        currentSum = max(A[i], currentSum + A[i]);
        rightMax[i] = max(rightMax[i + 1], currentSum);
    }
    long long maxSum = LLONG_MIN;
    for (int i = 1; i < n - 1; i++) {
        maxSum = max(maxSum, leftMax[i - 1] + A[i] + rightMax[i + 1]);
    }
    cout << maxSum << endl;
    return 0;
}
