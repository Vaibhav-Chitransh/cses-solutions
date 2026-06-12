#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long modPow(long long a, long long b) {
    long long res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    long long total = 1LL * n * (n + 1) / 2;

    if(total & 1) {
        cout << 0 << '\n';
        return 0;
    }

    int target = total / 2;

    vector<long long> dp(target + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int x = target; x >= i; x--) {
            dp[x] = (dp[x] + dp[x - i]) % MOD;
        }
    }

    long long inv2 = modPow(2, MOD - 2);

    cout << dp[target] * inv2 % MOD << '\n';
}