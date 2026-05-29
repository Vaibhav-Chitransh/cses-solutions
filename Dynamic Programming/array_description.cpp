#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1000000007;
 
int n, m;
vector<int> arr;
vector<vector<int>> dp;
 
int solve(int idx, int prev) {
    if (idx == n) return 1;
 
    if (dp[idx][prev] != -1) return dp[idx][prev];
 
    int res = 0;
 
    if (arr[idx] == 0) {
        if (idx == 0) {
            for (int k = 1; k <= m; k++) {
                res = (res + solve(idx + 1, k)) % MOD;
            }
        } else {
            if (prev - 1 >= 1) res = (res + solve(idx + 1, prev - 1)) % MOD;
            res = (res + solve(idx + 1, prev)) % MOD;
            if (prev + 1 <= m) res = (res + solve(idx + 1, prev + 1)) % MOD;
        }
    } else {
        if (idx == 0 || abs(arr[idx] - prev) <= 1) {
            res = solve(idx + 1, arr[idx]) % MOD;
        } else {
            res = 0;
        }
    }
 
    return dp[idx][prev] = res;
}
 
int main() {
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
 
    dp.assign(n + 1, vector<int>(m + 2, -1)); 
 
    int result;
    if (arr[0] == 0) {
        result = 0;
        for (int val = 1; val <= m; val++) {
            result = (result + solve(1, val)) % MOD;
        }
    } else {
        result = solve(1, arr[0]);
    }
 
    cout << result;
    return 0;
}