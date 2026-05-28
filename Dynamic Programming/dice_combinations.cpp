#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1, 0);
    dp[1] = 1;

    for(int i=2; i<=n; i++) {
        if(i <= 6) dp[i] = 1;
        for(int x=1; x<=6; x++) {
            if(i - x >= 1) dp[i] = (dp[i-x] + dp[i]) % mod;
        }
    }

    cout << dp[n] << endl;

    return 0;
}