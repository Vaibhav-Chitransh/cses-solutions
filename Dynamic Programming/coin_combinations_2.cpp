#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];

    vector<vector<int>> dp(n, vector<int>(x+1, 0));
    for(int i=0; i<n; i++) dp[i][0] = 1;

    for(int i=n-1; i>=0; i--) {
        for(int j=1; j<=x; j++) {
            int pick = 0, notPick = 0;
            if(j - coins[i] >= 0) pick = dp[i][j - coins[i]];
            if(i != n-1) notPick = dp[i+1][j];
            dp[i][j] = (pick + notPick) % mod;
        }
    }

    cout << dp[0][x];
    return 0;
}