#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> dp(100000000, 1e9);
    dp[0] = 0;

    vector<int> coins(n);
    for(int i=0; i<n; i++) {
        cin >> coins[i];
        dp[coins[i]] = 1;
    }

    for(int i=1; i<=x; i++) {
        if(dp[i] == 1) continue;
        for(int c : coins) {
            if(i - c < 0 || dp[i-c] == 1e9) continue;
            dp[i] = min(dp[i], 1 + dp[i-c]);
        }
    }

    cout << ((dp[x] == 1e9) ? -1 : dp[x]) << endl;

    return 0;
}