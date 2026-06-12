#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1000000007;
 
int n, m;
vector<int> arr;
vector<vector<int>> dp;
 
int main() {
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
 
    dp.resize(n+2, vector<int>(m+2, 0));

    for(int i=1; i<=n; i++) {
        for(int x=1; x<=m; x++) {
            if(i == 1) {
                if(arr[i-1] == 0 || arr[i-1] == x) dp[i][x] = 1;
            } else {
                if(arr[i-1] == 0 || arr[i-1] == x) dp[i][x] = ((dp[i-1][x-1] + dp[i-1][x]) % MOD + dp[i-1][x+1]) % MOD;
            }
        }
    }

    int ans = 0;
    for(int x=1; x<=m; x++) ans = (ans + dp[n][x]) % MOD;

    cout << ans << "\n";

    return 0;
}