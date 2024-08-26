#include <bits/stdc++.h>
#define int long long

using namespace std;

int kadane(vector<int> &arr) {
    int max_so_far = LLONG_MIN, max_ending_here = 0;
    for (int i = 0; i < arr.size(); i++) {
        max_ending_here += arr[i];
        max_so_far = max(max_so_far, max_ending_here);
        if (max_ending_here < 0) max_ending_here = 0;
    }
    return max_so_far;
}

int maxSubMatrixSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int max_sum = LLONG_MIN;
    for (int left = 0; left < m; left++) {
        vector<int> temp(n, 0);
        for (int right = left; right < m; right++) {
            for (int i = 0; i < n; i++) {
                temp[i] += matrix[i][right];
            }
            int sum = kadane(temp);
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}

signed main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << maxSubMatrixSum(matrix) << endl;
    return 0;
}